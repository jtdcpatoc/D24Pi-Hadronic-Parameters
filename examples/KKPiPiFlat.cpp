/**
 * This is code that creates N number of flat phase space events, calculates the bin number under the KKpipi binning scheme used by Daniel Cervenkov and Martin Tat, AND the amplitude for each event.
 * 
 * No input.
 * 
 * Output is a ROOT file which stores the real and imaginary parts of the amplitudes, the 5D phase space point and the bin number. 
 * 
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
#include "../include/Utilities.h"

int main()
{

  // Local variables //

  int BinNumber;

  double Damp_Mag, DBARamp_Mag, StrongPhaseDiff, Damp_real, Damp_imag, DBARamp_real, DBARamp_imag, rD, m12;

  std::complex<double> Damp;
  std::complex<double> DBARamp;

  ////////////////////////////////////////////

  // Four-momentum of D in its rest frame //
  const double D_Mass = 1.86483;
  TLorentzVector P_D(0.0, 0.0, 0.0, D_Mass);

  const double PionMass = 0.13957039;
  const double KaonMass = 0.493677;
  double mass_decay[] = {KaonMass, KaonMass, PionMass, PionMass};

  Generator generator(D_Mass, mass_decay, 4);

  ////// Load binning scheme //////

  TFile fOut("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/ROOT_output/2M_KKPP_8bins_KKPPScheme.root", "recreate");
  TTree t1("GenEvents", "Test events binned with KKPP binning");

  t1.Branch("BinNumber", &BinNumber, "BinNumber/I");
  t1.Branch("Damp_Mag", &Damp_Mag);
  t1.Branch("DBARamp_Mag", &DBARamp_Mag);
  t1.Branch("StrongPhaseDiff", &StrongPhaseDiff);
  t1.Branch("Damp_real", &Damp_real);
  t1.Branch("Damp_imag", &Damp_imag);
  t1.Branch("DBARamp_real", &DBARamp_real);
  t1.Branch("DBARamp_imag", &DBARamp_imag);
  t1.Branch("m12", &m12, "m12/D");

  ////////////////////////////////////////////

  Int_t nevents = 2000000;

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

    // Have to do this as the AmpGen model could not calculate the CP conjugated amplitudes. Pions ordered as + - + -
    std::vector<double> myEvent = event.GetEventVector();

    Amplitude amplitude;
    std::complex<double> Damp = amplitude(myEvent, +1);
    std::complex<double> D0_conj_Amplitude = amplitude(myEvent, -1);
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
    StrongPhaseDiff = std::arg(Damp * std::conj(DBARamp));
    rD = std::norm(Damp / DBARamp);
    
    int number_of_bins = 8;

    BinNumber = static_cast<int>((StrongPhaseDiff + TMath::Pi()) / (2 * TMath::Pi() / number_of_bins)) + 1;
    
    if (rD > 1) {
        BinNumber = -(number_of_bins + 1 - BinNumber);
    }

    //std::cout << "BinNumber: " << BinNumber << "\n";
    
    t1.Fill();
  }

  fOut.cd();
  t1.Write();

  std::cout << "DONE! \n";
  return 0;
}