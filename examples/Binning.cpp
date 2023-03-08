/**
 * D->4pi binning code
 * @param 1 Filename of binning scheme
 * Code based of MinimalExample.cpp provided by Martin Tat
**/

#include<array>
#include<string>
#include<iostream>
#include<algorithm>

#include"TLorentzVector.h"
#include"TRandom.h"
#include"TROOT.h"
#include"TFile.h" 
#include"TTree.h"

#include"../include/HyperPoint.h"
#include"../include/HyperHistogram.h"
#include"../include/Utilities.h"

int main(int argc, char *argv[]){

    TFile f("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/DC_Tuples/D0-bar-100k-CPV-s1.root");
    // Particle ordering in this ROOT file: pi+1 pi-2 pi+3 pi-4

    TTree *input_tree = (TTree*)f.Get("DalitzEventList");

    // Local variables //
    Double_t E_1, Px_1, Py_1, Pz_1;

    Double_t E_2, Px_2, Py_2, Pz_2;

    Double_t E_3, Px_3, Py_3, Pz_3;

    Double_t E_4, Px_4, Py_4, Pz_4;

    double mPlusPrime, mMinusPrime, cosThetaPlus, cosThetaMinus, phi;

    int BinNumber;

    // Assign these variables to specific branch addresses//

    input_tree->SetBranchAddress("_1_pi~_E",&E_1);
    input_tree->SetBranchAddress("_1_pi~_Px",&Px_1);
    input_tree->SetBranchAddress("_1_pi~_Py",&Py_1);
    input_tree->SetBranchAddress("_1_pi~_Pz",&Pz_1);

    input_tree->SetBranchAddress("_2_pi#_E",&E_2);
    input_tree->SetBranchAddress("_2_pi#_Px",&Px_2);
    input_tree->SetBranchAddress("_2_pi#_Py",&Py_2);
    input_tree->SetBranchAddress("_2_pi#_Pz",&Pz_2);

    input_tree->SetBranchAddress("_3_pi~_E",&E_3);
    input_tree->SetBranchAddress("_3_pi~_Px",&Px_3);
    input_tree->SetBranchAddress("_3_pi~_Py",&Py_3);
    input_tree->SetBranchAddress("_3_pi~_Pz",&Pz_3);

    input_tree->SetBranchAddress("_4_pi#_E",&E_4);
    input_tree->SetBranchAddress("_4_pi#_Px",&Px_4);
    input_tree->SetBranchAddress("_4_pi#_Py",&Py_4);
    input_tree->SetBranchAddress("_4_pi#_Pz",&Pz_4);

    ////////////////////////////////////////////

    // Make a ROOT file with original Kinematic Parameters AND the binning params

    TFile fOut("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/ROOT_output/D0-bar-100k-BesOptimEqualV0.root","recreate");
    TTree t1("Events","100k D0(bar)24Pi events binned with BesOptimEqualV0");

    t1.Branch("E_1",&E_1,"E_1/D");
    t1.Branch("Px_1",&Px_1,"Px_1/D");
    t1.Branch("Py_1",&Py_1,"Py_1/D");
    t1.Branch("Pz_1",&Pz_1,"Pz_1/D");

    t1.Branch("E_2",&E_2,"E_2/D");
    t1.Branch("Px_2",&Px_2,"Px_2/D");
    t1.Branch("Py_2",&Py_2,"Py_2/D");
    t1.Branch("Pz_2",&Pz_2,"Pz_2/D");

    t1.Branch("E_3",&E_3,"E_3/D");
    t1.Branch("Px_3",&Px_3,"Px_3/D");
    t1.Branch("Py_3",&Py_3,"Py_3/D");
    t1.Branch("Pz_3",&Pz_3,"Pz_3/D");

    t1.Branch("E_4",&E_4,"E_4/D");
    t1.Branch("Px_4",&Px_4,"Px_4/D");
    t1.Branch("Py_4",&Py_4,"Py_4/D");
    t1.Branch("Pz_4",&Pz_4,"Pz_4/D");

    t1.Branch("mPlusPrime",&mPlusPrime,"mPlusPrime/D");
    t1.Branch("mMinusPrime",&mMinusPrime,"mMinusPrime/D");
    t1.Branch("cosThetaPlus",&cosThetaPlus,"cosThetaPlus/D");
    t1.Branch("cosThetaMinus",&cosThetaMinus,"cosThetaMinus/D");
    t1.Branch("phi",&phi,"phi/D");
    t1.Branch("BinNumber",&BinNumber,"BinNumber/I");

  ////////////////////////////////////////////

    // Four-momentum of D in its rest frame //
    TLorentzVector P_D(0.0, 0.0, 0.0, 1.86483);

    ////// Load binning scheme //////

    const HyperHistogram hyperHistogram(argv[1], "MEMRES READ");

    //const std::size_t nevents = 10;

    Int_t nevents = 100000;

    for(Int_t n = 0; n < nevents; n++) {

      input_tree->GetEntry(n);

      //Particle ordering: pi+1 pi-2 pi+3 pi-4
      TLorentzVector Pi1(Px_1, Py_1, Pz_1, E_1);
      TLorentzVector Pi2(Px_2, Py_2, Pz_2, E_2);
      TLorentzVector Pi3(Px_3, Py_3, Pz_3, E_3);
      TLorentzVector Pi4(Px_4, Py_4, Pz_4, E_4);

      std::array<TLorentzVector, 4> Daughters = {Pi1, Pi2, Pi3, Pi4};

      const double mPlus = (Daughters[0] + Daughters[2]).M();
      const double mMinus = (Daughters[1] + Daughters[3]).M();

      cosThetaPlus = Utilities::getCosTheta(Daughters[0], Daughters[0] + Daughters[2], P_D);

      cosThetaMinus = Utilities::getCosTheta(Daughters[1], Daughters[1] + Daughters[3], P_D);

      phi = Utilities::getPhi(Daughters);

      constexpr double mMin = 2.0*0.13957039;

      if(mMinus > mPlus) {
        mPlusPrime  = mPlus  + (mPlus - mMin);
        mMinusPrime = mMinus + (mPlus - mMin);
      }
      else {
        mPlusPrime  = mPlus  + (mMinus - mMin);
        mMinusPrime = mMinus + (mMinus - mMin);
      }

      // Transform the variables so that cosThetaPlus > 0, cosThetaMinus > 0 and phi > 0

      if (cosThetaPlus < 0.0){
        cosThetaPlus = -cosThetaPlus;
        phi = phi - TMath::Pi();
      }

      if (cosThetaMinus < 0.0){
        cosThetaMinus = -cosThetaMinus;
        phi = phi- TMath::Pi();
      }

      while (phi < - 1.0){
        phi += 2.0*TMath::Pi();
      }

      while (phi > TMath::Pi()){
        phi -= 2.0*TMath::Pi();
      }

      bool Flip = false;
      if (phi < 0){
        std::swap(cosThetaPlus, cosThetaMinus); 
        std::swap(mPlusPrime  , mMinusPrime  ); 
        phi = -phi;
        Flip = true;
      }

      // Create hyperpoint and determine bin number

      HyperPoint hyperPoint(mPlusPrime, mMinusPrime, cosThetaPlus, cosThetaMinus, phi);

      BinNumber = hyperHistogram.getVal(hyperPoint)*(Flip ? -1 : 1);
    
      // std::cout << "mPlusPrime: " << mPlusPrime << "\n";

      t1.Fill();

    }

  fOut.cd();
  t1.Write();

  return 0;
}