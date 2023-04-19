/**
 * This is code that bins D24pi data, and calculates the bin number using the BES3 schemes. Code based of MinimalExample.cpp provided by Martin Tat & Xiaodong Shi
 * 
 * Here, the code is able either C, P, or CP conjugate events for the D0bar simulation.
 * 
 * The input is a ROOT file of a BES3 binning scheme. 
 * 
 * Output is a ROOT file which stores, the 5D phase space point and the bin number. 
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

#include "../include/HyperPoint.h"
#include "../include/HyperHistogram.h"
#include "../include/Utilities.h"

int main(int argc, char *argv[])
{

  TFile f("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/DC_Tuples/D0-bar-1M-CPV-s1.root");
  // Particle ordering in this ROOT file: pi+1 pi-2 pi+3 pi-4

  TTree *input_tree = (TTree *)f.Get("DalitzEventList");

  // Local variables //
  Double_t E_1, Px_1, Py_1, Pz_1;
  Double_t E_2, Px_2, Py_2, Pz_2;
  Double_t E_3, Px_3, Py_3, Pz_3;
  Double_t E_4, Px_4, Py_4, Pz_4;

  Double_t Flip_E_1, Flip_Px_1, Flip_Py_1, Flip_Pz_1;
  Double_t Flip_E_2, Flip_Px_2, Flip_Py_2, Flip_Pz_2;
  Double_t Flip_E_3, Flip_Px_3, Flip_Py_3, Flip_Pz_3;
  Double_t Flip_E_4, Flip_Px_4, Flip_Py_4, Flip_Pz_4;

  double mPlusPrime, mMinusPrime, cosThetaPlus, cosThetaMinus, phi, D0_decayTime;

  int BinNumber;

  // Assign these variables to specific branch addresses//

  input_tree->SetBranchAddress("_1_pi~_E", &E_1);
  input_tree->SetBranchAddress("_1_pi~_Px", &Px_1);
  input_tree->SetBranchAddress("_1_pi~_Py", &Py_1);
  input_tree->SetBranchAddress("_1_pi~_Pz", &Pz_1);

  input_tree->SetBranchAddress("_2_pi#_E", &E_2);
  input_tree->SetBranchAddress("_2_pi#_Px", &Px_2);
  input_tree->SetBranchAddress("_2_pi#_Py", &Py_2);
  input_tree->SetBranchAddress("_2_pi#_Pz", &Pz_2);

  input_tree->SetBranchAddress("_3_pi~_E", &E_3);
  input_tree->SetBranchAddress("_3_pi~_Px", &Px_3);
  input_tree->SetBranchAddress("_3_pi~_Py", &Py_3);
  input_tree->SetBranchAddress("_3_pi~_Pz", &Pz_3);

  input_tree->SetBranchAddress("_4_pi#_E", &E_4);
  input_tree->SetBranchAddress("_4_pi#_Px", &Px_4);
  input_tree->SetBranchAddress("_4_pi#_Py", &Py_4);
  input_tree->SetBranchAddress("_4_pi#_Pz", &Pz_4);

  input_tree->SetBranchAddress("D0_decayTime", &D0_decayTime);



  // Make a ROOT file with flipped kinematic parameters AND the binning params

  TFile fOut("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/d4h-mixing-analysis/data/ampgen/FLIP-C-D0-bar-1M-CPV-s1-psbins-BesEqualV0.root", "recreate");
  TTree t1("DalitzEventList", "1M D0(bar)24Pi events binned with BesEqualV0");

  t1.Branch("D_decayTime", &D0_decayTime, "D_decayTime/D");

  t1.Branch("_1_pi~_E", &Flip_E_1, "_1_pi~_E/D");
  t1.Branch("_1_pi~_Px", &Flip_Px_1, "_1_pi~_Px/D");
  t1.Branch("_1_pi~_Py", &Flip_Py_1, "_1_pi~_Py/D");
  t1.Branch("_1_pi~_Pz", &Flip_Pz_1, "_1_pi~_Pz/D");

  t1.Branch("_2_pi#_E", &Flip_E_2, "_2_pi#_E/D");
  t1.Branch("_2_pi#_Px", &Flip_Px_2, "_2_pi#_Px/D");
  t1.Branch("_2_pi#_Py", &Flip_Py_2, "_2_pi#_Py/D");
  t1.Branch("_2_pi#_Pz", &Flip_Pz_2, "_2_pi#_Pz/D");

  t1.Branch("_3_pi~_E", &Flip_E_3, "_3_pi~_E/D");
  t1.Branch("_3_pi~_Px", &Flip_Px_3, "_3_pi~_Px/D");
  t1.Branch("_3_pi~_Py", &Flip_Py_3, "_3_pi~_Py/D");
  t1.Branch("_3_pi~_Pz", &Flip_Pz_3, "_3_pi~_Pz/D");

  t1.Branch("_4_pi#_E", &Flip_E_4, "_4_pi#_E/D");
  t1.Branch("_4_pi#_Px", &Flip_Px_4, "_4_pi#_Px/D");
  t1.Branch("_4_pi#_Py", &Flip_Py_4, "_4_pi#_Py/D");
  t1.Branch("_4_pi#_Pz", &Flip_Pz_4, "_4_pi#_Pz/D");

  t1.Branch("mPlusPrime", &mPlusPrime, "mPlusPrime/D");
  t1.Branch("mMinusPrime", &mMinusPrime, "mMinusPrime/D");
  t1.Branch("cosThetaPlus", &cosThetaPlus, "cosThetaPlus/D");
  t1.Branch("cosThetaMinus", &cosThetaMinus, "cosThetaMinus/D");
  t1.Branch("phi", &phi, "phi/D");
  t1.Branch("ps_bin", &BinNumber, "ps_bin/I");

  ////////////////////////////////////////////

  // Four-momentum of D in its rest frame //
  TLorentzVector P_D(0.0, 0.0, 0.0, 1.86483);

  ////// Load binning scheme //////

  const HyperHistogram hyperHistogram(argv[1], "MEMRES READ");

  Int_t nevents = input_tree->GetEntries();

  for (Int_t n = 0; n < nevents; n++)
  {

    input_tree->GetEntry(n);

    // Here I C conjugate the D0 events to produce a D0bar event, of course, no CPV.
 
    Flip_E_1 = E_2;
    Flip_Px_1 = Px_2;
    Flip_Py_1 = Py_2;
    Flip_Pz_1 = Pz_2;

    Flip_E_2 = E_1;
    Flip_Px_2 = Px_1;
    Flip_Py_2 = Py_1;
    Flip_Pz_2 = Pz_1;

    Flip_E_3 = E_4;
    Flip_Px_3 = Px_4;
    Flip_Py_3 = Py_4;
    Flip_Pz_3 = Pz_4;

    Flip_E_4 = E_3;
    Flip_Px_4 = Px_3;
    Flip_Py_4 = Py_3;
    Flip_Pz_4 = Pz_3;
   
/* CP Conjuagting
    Flip_E_1 = E_1;
    Flip_Px_1 = -Px_1;
    Flip_Py_1 = -Py_1;
    Flip_Pz_1 = -Pz_1;

    Flip_E_2 = E_2;
    Flip_Px_2 = -Px_2;
    Flip_Py_2 = -Py_2;
    Flip_Pz_2 = -Pz_2;

    Flip_E_3 = E_3;
    Flip_Px_3 = -Px_3;
    Flip_Py_3 = -Py_3;
    Flip_Pz_3 = -Pz_3;

    Flip_E_4 = E_4;
    Flip_Px_4 = -Px_4;
    Flip_Py_4 = -Py_4;
    Flip_Pz_4 = -Pz_4;
*/ 
    // Particle ordering: pi+1 pi-2 pi+3 pi-4, with (P, E) as the 4-vector
  
    TLorentzVector Pi1(Flip_Px_1, Flip_Py_1, Flip_Pz_1, Flip_E_1);
    TLorentzVector Pi2(Flip_Px_2, Flip_Py_2, Flip_Pz_2, Flip_E_2);
    TLorentzVector Pi3(Flip_Px_3, Flip_Py_3, Flip_Pz_3, Flip_E_3);
    TLorentzVector Pi4(Flip_Px_4, Flip_Py_4, Flip_Pz_4, Flip_E_4);
    
 /* 
    TLorentzVector Pi1(Px_1, Py_1, Pz_1, E_1);
    TLorentzVector Pi2(Px_2, Py_2, Pz_2, E_2);
    TLorentzVector Pi3(Px_3, Py_3, Pz_3, E_3);
    TLorentzVector Pi4(Px_4, Py_4, Pz_4, E_4);
*/ 
    std::array<TLorentzVector, 4> Daughters = {Pi1, Pi2, Pi3, Pi4};

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
/*    
    std::cout << "Px_1: " << Px_1 << "\n";
    std::cout << "Flip_Px_2: " << Flip_Px_2 << "\n";
    std::cout << "E_1: " << E_1 << "\n";
    std::cout << "Flip_E_2: " << Flip_E_2 << "\n\n";
*/
    t1.Fill();
  }

  fOut.cd();
  t1.Write();

  return 0;
}