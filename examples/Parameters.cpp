/**
 * This code calculates the  Hadronic parameters AND the CP-even fraction from a
 *given binning scheme based of code from Martin Tat.
 *
 * The input is a ROOT file (produced from either KKPiPiFlat.cpp or
 *GenerateFlat.cpp) where each event is given a bin number from the given
 *scheme. The ROOT file should have the real and imaginary parts of the
 *amplitude.
 *
 * Output are the hadronic parameters; given in the terminal.
 *
 * Note: At the moment, the bin number is hard-coded (line 91). 5 for the BES3
 *schemes.
 *
 * @param 1 ROOT filename of the binned flat phase space events.
 *
 **/

#include <algorithm>
#include <complex>
#include <fstream>
#include <iostream>
#include <numeric>
#include <omp.h>
#include <sstream>
#include <string>
#include <vector>

#include "../include/Amplitude.h"
#include "../include/Event.h"

#include "TAxis.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TROOT.h"
#include "TTree.h"

//____________________________________________//

int main(int argc, char *argv[]) {

  double Damp_Mag, DBARamp_Mag, StrongPhaseDiff, Damp_real, Damp_imag,
      DBARamp_real, DBARamp_imag;

  int BinNumber;

  std::complex<double> Damp;
  std::complex<double> DBARamp;

  TFile f(argv[1], "READ");
  TTree *input_tree = (TTree *)f.Get("GenEvents");

  input_tree->SetBranchAddress("BinNumber", &BinNumber);
  input_tree->SetBranchAddress("Damp_Mag", &Damp_Mag);
  input_tree->SetBranchAddress("DBARamp_Mag", &DBARamp_Mag);
  // input_tree->SetBranchAddress("StrongPhaseDiff",&StrongPhaseDiff);
  input_tree->SetBranchAddress("Damp_real", &Damp_real);
  input_tree->SetBranchAddress("Damp_imag", &Damp_imag);
  input_tree->SetBranchAddress("DBARamp_real", &DBARamp_real);
  input_tree->SetBranchAddress("DBARamp_imag", &DBARamp_imag);
  // input_tree->SetBranchAddress("EventWeight",&EventWeight);

  //____________________________________________//

  /**
   * Vector of fractional yields of D0 events
   */
  std::vector<double> m_K;

  /**
   * Vector of fractional yields of DBAR0 events
   */
  std::vector<double> m_Kbar;

  /**
   * Vector of cosine of strong phases
   */
  std::vector<double> m_c;

  /**
   * Vector of sine of strong phases
   */
  std::vector<double> m_s;

  /**
   * Vector of bin areas of positive bins
   */
  std::vector<double> m_AreaPlus;

  /**
   * Vector of bin areas of negative bins
   */
  std::vector<double> m_AreaMinus;

  //____________________________________________//

  int NumberBins = 8; // Number of bin pairs

  m_K = std::vector<double>(NumberBins, 0.0);
  m_Kbar = std::vector<double>(NumberBins, 0.0);
  m_c = std::vector<double>(NumberBins, 0.0);
  m_s = std::vector<double>(NumberBins, 0.0);
  m_AreaPlus = std::vector<double>(NumberBins, 0.0);
  m_AreaMinus = std::vector<double>(NumberBins, 0.0);

  double F_P_nom = 0.0;
  double F_P_denom = 0.0;
  double EventWeight = 1.0;

  Int_t nevents = input_tree->GetEntries();
  for (Int_t n = 0; n < nevents; n++) {

    input_tree->GetEntry(n);

    Damp = std::complex<double>(Damp_real, Damp_imag);
    DBARamp = std::complex<double>(DBARamp_real, DBARamp_imag);

    if (BinNumber == 0) {
      continue;
    }

    if (BinNumber < 0) {
      std::swap(Damp, DBARamp);
    }

    StrongPhaseDiff = std::arg(Damp) - std::arg(DBARamp);

    // F+, CP Even fraction, used as a cross-check that the model is correct
    F_P_nom += (pow(Damp_Mag, 2) + pow(DBARamp_Mag, 2) +
                2 * Damp_Mag * DBARamp_Mag * TMath::Cos(StrongPhaseDiff)) *
               EventWeight;

    F_P_denom += 2 * (pow(Damp_Mag, 2) + pow(DBARamp_Mag, 2)) * EventWeight;

    // Bin index, starting from 0
    const double BinIndex = TMath::Abs(BinNumber) - 1;

    // Calculate fractional yield

    m_K[BinIndex] += std::norm(Damp) * EventWeight;

    m_Kbar[BinIndex] += std::norm(DBARamp) * EventWeight;

    // Calculate c_i and s_i

    m_c[BinIndex] += TMath::Sqrt(std::norm(Damp) * std::norm(DBARamp)) *
                     TMath::Cos(StrongPhaseDiff) * EventWeight;

    m_s[BinIndex] += TMath::Sqrt(std::norm(Damp) * std::norm(DBARamp)) *
                     TMath::Sin(StrongPhaseDiff) * EventWeight;

    // Calculate bin area
    if (BinNumber > 0) {
      m_AreaPlus[BinIndex] += EventWeight;
    } else {
      m_AreaMinus[BinIndex] += EventWeight;
    }
  }

  double sumK = 0.0, sumArea = 0.0;
  for (int i = 0; i < NumberBins; i++) {
    // Amplitude averaged strong phase variation normalisation
    m_c[i] /= TMath::Sqrt(m_K[i] * m_Kbar[i]);
    m_s[i] /= TMath::Sqrt(m_K[i] * m_Kbar[i]);

    // Sum factional yields for normalisation
    sumK += m_K[i];
    sumK += m_Kbar[i];

    // Sum bin area
    sumArea += m_AreaPlus[i];
    sumArea += m_AreaMinus[i];
  }

  // Divide fractional yields by total to normalise to 1

  std::transform(
      m_K.begin(), m_K.end(), m_K.begin(),
      std::bind(std::divides<double>(), std::placeholders::_1, sumK));

  std::transform(
      m_Kbar.begin(), m_Kbar.end(), m_Kbar.begin(),
      std::bind(std::divides<double>(), std::placeholders::_1, sumK));

  // Divide area by total to normalise to 1

  std::transform(
      m_AreaPlus.begin(), m_AreaPlus.end(), m_AreaPlus.begin(),
      std::bind(std::divides<double>(), std::placeholders::_1, sumArea));

  std::transform(
      m_AreaMinus.begin(), m_AreaMinus.end(), m_AreaMinus.begin(),
      std::bind(std::divides<double>(), std::placeholders::_1, sumArea));

  //____________________________________________//

  double F_P = F_P_nom / F_P_denom;

  std::cout << "m_c[0]: " << m_c[0] << "\n";
  std::cout << "m_c[1]: " << m_c[1] << "\n";
  std::cout << "m_c[2]: " << m_c[2] << "\n";
  std::cout << "m_c[3]: " << m_c[3] << "\n";
  std::cout << "m_c[4]: " << m_c[4] << "\n";
  std::cout << "m_c[5]: " << m_c[5] << "\n";
  std::cout << "m_c[6]: " << m_c[6] << "\n";
  std::cout << "m_c[7]: " << m_c[7] << "\n\n";

  std::cout << "m_s[0]: " << m_s[0] << "\n";
  std::cout << "m_s[1]: " << m_s[1] << "\n";
  std::cout << "m_s[2]: " << m_s[2] << "\n";
  std::cout << "m_s[3]: " << m_s[3] << "\n";
  std::cout << "m_s[4]: " << m_s[4] << "\n";
  std::cout << "m_s[5]: " << m_s[5] << "\n";
  std::cout << "m_s[6]: " << m_s[6] << "\n";
  std::cout << "m_s[7]: " << m_s[7] << "\n\n";

  std::cout << "m_K[0]: " << m_K[0] << "\n";
  std::cout << "m_K[1]: " << m_K[1] << "\n";
  std::cout << "m_K[2]: " << m_K[2] << "\n";
  std::cout << "m_K[3]: " << m_K[3] << "\n";
  std::cout << "m_K[4]: " << m_K[4] << "\n";
  std::cout << "m_K[5]: " << m_K[5] << "\n";
  std::cout << "m_K[6]: " << m_K[6] << "\n";
  std::cout << "m_K[7]: " << m_K[7] << "\n\n";

  std::cout << "m_Kbar[0]: " << m_Kbar[0] << "\n";
  std::cout << "m_Kbar[1]: " << m_Kbar[1] << "\n";
  std::cout << "m_Kbar[2]: " << m_Kbar[2] << "\n";
  std::cout << "m_Kbar[3]: " << m_Kbar[3] << "\n";
  std::cout << "m_Kbar[4]: " << m_Kbar[4] << "\n";
  std::cout << "m_Kbar[5]: " << m_Kbar[5] << "\n";
  std::cout << "m_Kbar[6]: " << m_Kbar[6] << "\n";
  std::cout << "m_Kbar[7]: " << m_Kbar[7] << "\n\n";

  std::cout << "F_P: " << F_P << "\n\n";

  return 0;
}
