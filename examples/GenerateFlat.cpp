/**
 * This is code that creates N number of flat phase space events, calculates the bin number using the BES3 schemes, AND the amplitude for each event. Code based of MinimalExample.cpp provided by Martin Tat & Xiaodong Shi
 * 
 * For D24pi, AmpGen is such that you have to C-conjugate the D0bar events before feeding it into the Amplitude function - this gives results in agreement with the BES3 results. 
 * 
 * The input is a ROOT file of a BES3 binning scheme. 
 * 
 * Output is a ROOT file which stores the real and imaginary parts of the amplitudes, the 5D phase space point and the bin number. 
 * 
 * @param 1 Filename of binning scheme 
 * 
 **/

#include <array>
#include <string>
#include <iostream>
#include <algorithm>

#include "TLorentzVector.h"
#include "TRandom.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"

#include "../include/Generator.h"
#include "../include/Event.h"
#include "../include/PiPiPiPiMath.h"
#include "../include/Amplitude.h"
#include "../include/HyperPoint.h"
#include "../include/HyperHistogram.h"
#include "../include/Utilities.h"

int main(int argc, char *argv[])
{

  // Local variables //

  double mPlusPrime, mMinusPrime, cosThetaPlus, cosThetaMinus, phi, m12, m34, m13, m24;

  int BinNumber;

  double Damp_Mag, DBARamp_Mag, StrongPhaseDiff, Damp_real, Damp_imag, DBARamp_real, DBARamp_imag;

  std::complex<double> Damp;
  std::complex<double> DBARamp;

  ////////////////////////////////////////////

  // Four-momentum of D in its rest frame //
  const double D_Mass = 1.86483;
  TLorentzVector P_D(0.0, 0.0, 0.0, D_Mass);

  const double PionMass = 0.13957039;
  double mass_decay[] = {PionMass, PionMass, PionMass, PionMass};

  Generator generator(D_Mass, mass_decay, 4);

  ////// Load binning scheme //////

  const HyperHistogram hyperHistogram(argv[1], "MEMRES READ");

  TFile fOut("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/ROOT_output/500k_BesEqualV0.root", "recreate");
  TTree t1("GenEvents", "Test events binned with BesAlterV0");

  t1.Branch("mPlusPrime", &mPlusPrime, "mPlusPrime/D");
  t1.Branch("mMinusPrime", &mMinusPrime, "mMinusPrime/D");
  t1.Branch("cosThetaPlus", &cosThetaPlus, "cosThetaPlus/D");
  t1.Branch("cosThetaMinus", &cosThetaMinus, "cosThetaMinus/D");
  t1.Branch("phi", &phi, "phi/D");
  t1.Branch("BinNumber", &BinNumber);
  t1.Branch("Damp_Mag", &Damp_Mag);
  t1.Branch("DBARamp_Mag", &DBARamp_Mag);
  t1.Branch("StrongPhaseDiff", &StrongPhaseDiff);
  t1.Branch("Damp_real", &Damp_real);
  t1.Branch("Damp_imag", &Damp_imag);
  t1.Branch("DBARamp_real", &DBARamp_real);
  t1.Branch("DBARamp_imag", &DBARamp_imag);
  t1.Branch("m12", &m12);
  t1.Branch("m34", &m34);
  t1.Branch("m13", &m13);
  t1.Branch("m24", &m24);

  ////////////////////////////////////////////

  Int_t nevents = 500000;

  for (Int_t n = 0; n < nevents; n++)
  {

    Event event(generator.Generate());
    std::vector<TLorentzVector> P = PiPiPiPiMath::ConvertEventTo4Vectors(event.GetEventVector());

    std::array<TLorentzVector, 4> Daughters;
    for (std::size_t i = 0; i < 4; i++)
    {
      Daughters[i] = P[i];
    }

    // TGenPhaseSpace is independent of particle ordering (Martin). Keep the ordering the same as the one for the MC to avoid confusion. 

    m12 = (Daughters[0] + Daughters[1]).M();
    m34 = (Daughters[2] + Daughters[3]).M();
    m13 = (Daughters[0] + Daughters[2]).M();
    m24 = (Daughters[1] + Daughters[3]).M();

    const double mPlus = (Daughters[0] + Daughters[2]).M();
    const double mMinus = (Daughters[1] + Daughters[3]).M();

    cosThetaPlus = Utilities::getCosTheta(Daughters[0], Daughters[0] + Daughters[2], P_D);
    cosThetaMinus = Utilities::getCosTheta(Daughters[1], Daughters[1] + Daughters[3], P_D);

    phi = Utilities::getPhi(Daughters);

    constexpr double mMin = 2.0 * 0.13957039;

    if (mMinus > mPlus)
    {
      mPlusPrime = mPlus + (mPlus - mMin);
      mMinusPrime = mMinus + (mPlus - mMin);
    }
    else
    {
      mPlusPrime = mPlus + (mMinus - mMin);
      mMinusPrime = mMinus + (mMinus - mMin);
    }

    // Transform the variables so that cosThetaPlus > 0, cosThetaMinus > 0 and phi > 0

    if (cosThetaPlus < 0.0)
    {
      cosThetaPlus = -cosThetaPlus;
      phi = phi - TMath::Pi();
    }

    if (cosThetaMinus < 0.0)
    {
      cosThetaMinus = -cosThetaMinus;
      phi = phi - TMath::Pi();
    }

    while (phi < -TMath::Pi())
    {
      phi += 2.0 * TMath::Pi();
    }

    while (phi > TMath::Pi())
    {
      phi -= 2.0 * TMath::Pi();
    }

    bool Flip = false;
    if (phi < 0)
    {
      std::swap(cosThetaPlus, cosThetaMinus);
      std::swap(mPlusPrime, mMinusPrime);
      phi = -phi;
      Flip = true;
    }

    // Create hyperpoint and determine bin number

    HyperPoint hyperPoint(mPlusPrime, mMinusPrime, cosThetaPlus, cosThetaMinus, phi);

    BinNumber = hyperHistogram.getVal(hyperPoint) * (Flip ? -1 : 1);

    if (BinNumber == 0) {
          continue;
    }

    // Have to do this as the AmpGen model could not calculate the CP conjugated amplitudes for D24pi. Pions will now be ordered as + - + -
    std::vector<double> myEvent = event.GetEventVector();
    std::vector<double> myD0barEvent(16);
  
    myD0barEvent[0] = myEvent[4];
    myD0barEvent[1] = myEvent[5];
    myD0barEvent[2] = myEvent[6];
    myD0barEvent[3] = myEvent[7];

    myD0barEvent[4] = myEvent[0];
    myD0barEvent[5] = myEvent[1];
    myD0barEvent[6] = myEvent[2];
    myD0barEvent[7] = myEvent[3];

    myD0barEvent[8] = myEvent[12]; 
    myD0barEvent[9] = myEvent[13];
    myD0barEvent[10] = myEvent[14];
    myD0barEvent[11] = myEvent[15];

    myD0barEvent[12] = myEvent[8];
    myD0barEvent[13] = myEvent[9];
    myD0barEvent[14] = myEvent[10];
    myD0barEvent[15] = myEvent[11];
    /*
          myD0barEvent[0] = -myEvent[0];
          myD0barEvent[1] = -myEvent[1];
          myD0barEvent[2] = -myEvent[2];
          myD0barEvent[3] = myEvent[3];

          myD0barEvent[4] = -myEvent[4];
          myD0barEvent[5] = -myEvent[5];
          myD0barEvent[6] = -myEvent[6];
          myD0barEvent[7] = myEvent[7];

          myD0barEvent[8] = -myEvent[8];
          myD0barEvent[9] = -myEvent[9];
          myD0barEvent[10] = -myEvent[10];
          myD0barEvent[11] = myEvent[11];

          myD0barEvent[12] = -myEvent[12];
          myD0barEvent[13] = -myEvent[13];
          myD0barEvent[14] = -myEvent[14];
          myD0barEvent[15] = myEvent[15];
    */

    Amplitude amplitude;
    std::complex<double> Damp = amplitude(myEvent, +1);
    std::complex<double> D0_conj_Amplitude = amplitude(myD0barEvent, -1);
    // if set to -1, the result should give D0Amplitude

    DBARamp = D0_conj_Amplitude;

    Damp_real = Damp.real();
    Damp_imag = Damp.imag();
    DBARamp_real = DBARamp.real();
    DBARamp_imag = DBARamp.imag();

    if (TMath::IsNaN(Damp_real) || TMath::IsNaN(Damp_imag) || TMath::IsNaN(DBARamp_real) || TMath::IsNaN(DBARamp_imag))
    {
      return 0;
    }


    Damp_Mag = sqrt(std::norm(Damp));
    DBARamp_Mag = sqrt(std::norm(DBARamp));
    StrongPhaseDiff = std::arg(Damp) - std::arg(DBARamp);

    /*
          std::cout << "Damp: " << Damp << "\n";
          std::cout << "DBARamp: " << DBARamp << "\n\n";
    
          std::cout << "Event: " << n << "\n";
          std::cout << "Damp_Mag: " << Damp_Mag << "\n";
          std::cout << "DBARamp_Mag: " << DBARamp_Mag << "\n";
          std::cout << "StrongPhaseDiff: " << StrongPhaseDiff << "\n";
          std::cout << "BinNumber: " << BinNumber << "\n";
          std::cout << "EvtWeight: " << EventWeight << "\n";
          std::cout << "\n";
    */

    t1.Fill();
  }

  fOut.cd();
  t1.Write();

  std::cout << "DONE! \n";
  return 0;
}