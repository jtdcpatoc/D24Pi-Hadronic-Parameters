/**
 * This is code that bins D -> KKpipi data, and calculates the bin number using KKpipi binning scheme. Based of code from Daniel Cervenkov and Martin Tat.
 * 
 * No input
 * 
 * Output is a ROOT file which stores, the 5D phase space point and the bin number. 
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

#include "../include/Amplitude.h"
#include "../include/Utilities.h"

int main()
{

  TFile f("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/d4h-mixing-analysis/data/ampgen/KKPP/D0-bar-1M-CPV-s1.root");
  // Particle ordering in this ROOT file: pi+1 pi-2 pi+3 pi-4

  TTree *input_tree = (TTree *)f.Get("DalitzEventList");

  // Local variables //
  Double_t E_1, Px_1, Py_1, Pz_1;
  Double_t E_2, Px_2, Py_2, Pz_2;
  Double_t E_3, Px_3, Py_3, Pz_3;
  Double_t E_4, Px_4, Py_4, Pz_4;

  double D0_decayTime, D_decayTime;

  double m12, m23, m34, m123, m234;

  double StrongPhaseDiff, rD, Damp_real, Damp_imag, DBARamp_real, DBARamp_imag;

  int BinNumber;

  // Assign these variables to specific branch addresses//

  input_tree->SetBranchAddress("_1_K~_E", &E_1);
  input_tree->SetBranchAddress("_1_K~_Px", &Px_1);
  input_tree->SetBranchAddress("_1_K~_Py", &Py_1);
  input_tree->SetBranchAddress("_1_K~_Pz", &Pz_1);

  input_tree->SetBranchAddress("_2_K#_E", &E_2);
  input_tree->SetBranchAddress("_2_K#_Px", &Px_2);
  input_tree->SetBranchAddress("_2_K#_Py", &Py_2);
  input_tree->SetBranchAddress("_2_K#_Pz", &Pz_2);

  input_tree->SetBranchAddress("_3_pi~_E", &E_3);
  input_tree->SetBranchAddress("_3_pi~_Px", &Px_3);
  input_tree->SetBranchAddress("_3_pi~_Py", &Py_3);
  input_tree->SetBranchAddress("_3_pi~_Pz", &Pz_3);

  input_tree->SetBranchAddress("_4_pi#_E", &E_4);
  input_tree->SetBranchAddress("_4_pi#_Px", &Px_4);
  input_tree->SetBranchAddress("_4_pi#_Py", &Py_4);
  input_tree->SetBranchAddress("_4_pi#_Pz", &Pz_4);

  input_tree->SetBranchAddress("D_decayTime", &D_decayTime);

  // Make a ROOT file with flipped kinematic parameters AND the binning params

  TFile fOut("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/d4h-mixing-analysis/data/ampgen/KKPP/D0-bar-1M-CPV-s1-psbins-byME.root", "recreate");
  TTree t1("DalitzEventList", "1M D0(bar)2KKPP events binned with KKPP scheme");

  t1.Branch("D_decayTime", &D_decayTime, "D_decayTime/D");

  t1.Branch("_1_K~_E", &E_1, "_1_K~_E/D");
  t1.Branch("_1_K~_Px", &Px_1, "_1_K~_Px/D");
  t1.Branch("_1_K~_Py", &Py_1, "_1_K~_Py/D");
  t1.Branch("_1_K~_Pz", &Pz_1, "_1_K~_Pz/D");

  t1.Branch("_2_K#_E", &E_2, "_2_K#_E/D");
  t1.Branch("_2_K#_Px", &Px_2, "_2_K#_Px/D");
  t1.Branch("_2_K#_Py", &Py_2, "_2_K#_Py/D");
  t1.Branch("_2_K#_Pz", &Pz_2, "_2_K#_Pz/D");

  t1.Branch("_3_pi~_E", &E_3, "_3_pi~_E/D");
  t1.Branch("_3_pi~_Px", &Px_3, "_3_pi~_Px/D");
  t1.Branch("_3_pi~_Py", &Py_3, "_3_pi~_Py/D");
  t1.Branch("_3_pi~_Pz", &Pz_3, "_3_pi~_Pz/D");

  t1.Branch("_4_pi#_E", &E_4, "_4_pi#_E/D");
  t1.Branch("_4_pi#_Px", &Px_4, "_4_pi#_Px/D");
  t1.Branch("_4_pi#_Py", &Py_4, "_4_pi#_Py/D");
  t1.Branch("_4_pi#_Pz", &Pz_4, "_4_pi#_Pz/D");

  t1.Branch("m12", &m12, "m12/D");
  t1.Branch("m23", &m23, "m23/D");
  t1.Branch("m34", &m34, "m34/D");
  t1.Branch("m123", &m123, "m123/D");
  t1.Branch("m234", &m234, "m234/D");
  t1.Branch("ps_bin", &BinNumber, "ps_bin/I");

  ////////////////////////////////////////////

  // Four-momentum of D in its rest frame //
  TLorentzVector P_D(0.0, 0.0, 0.0, 1.86483);

  ////// Load binning scheme //////

  Int_t nevents = input_tree->GetEntries();

  for (Int_t n = 0; n < nevents; n++)
  {

    input_tree->GetEntry(n);

    TLorentzVector Pi1(Px_1, Py_1, Pz_1, E_1);
    TLorentzVector Pi2(Px_2, Py_2, Pz_2, E_2);
    TLorentzVector Pi3(Px_3, Py_3, Pz_3, E_3);
    TLorentzVector Pi4(Px_4, Py_4, Pz_4, E_4);

    m12 = (Pi1 + Pi2).M();
    m23 = (Pi2 + Pi3).M();
    m34 = (Pi3 + Pi4).M();
    m123 = (Pi1 + Pi2 + Pi3).M();
    m234 = (Pi2 + Pi3 + Pi4).M();


    std::vector<double> myEvent = {Px_1, Py_1, Pz_1, E_1, Px_2, Py_2, Pz_2, E_2,
                                   Px_3, Py_3, Pz_3, E_3, Px_4, Py_4, Pz_4, E_4};

    // Here I CP conjugate the D0 events to produce a D0bar event, of course, no CPV.

    std::vector<double> myD0barEvent(16);
    /*
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
   */
    
    std::array<TLorentzVector, 4> Daughters = {Pi1, Pi2, Pi3, Pi4};

    Amplitude amplitude;
    std::complex<double> Damp = amplitude(myEvent, +1);
    std::complex<double> D0_conj_Amplitude = amplitude(myEvent, -1);
    std::complex<double> DBARamp = D0_conj_Amplitude;

    Damp_real = Damp.real();
    Damp_imag = Damp.imag();
    DBARamp_real = DBARamp.real();
    DBARamp_imag = DBARamp.imag();

    if (TMath::IsNaN(Damp_real) || TMath::IsNaN(Damp_imag) || TMath::IsNaN(DBARamp_real) || TMath::IsNaN(DBARamp_imag))
    {
      return 0;
    }

    double Damp_Mag = sqrt(std::norm(Damp));
    double DBARamp_Mag = sqrt(std::norm(DBARamp));
    StrongPhaseDiff = std::arg(Damp * std::conj(DBARamp));
    rD = std::norm(Damp / DBARamp);
    
    int number_of_bins = 8;

    BinNumber = static_cast<int>((StrongPhaseDiff + TMath::Pi()) / (2 * TMath::Pi() / number_of_bins)) + 1;
    
    if (rD > 1) {
        BinNumber = -(number_of_bins + 1 - BinNumber);
    }

    t1.Fill();
  }

  fOut.cd();
  t1.Write();

  return 0;
}
