#include<vector>
#include<functional>
#include"PiPiPiPiMath.h"
#include"TLorentzVector.h"
#include"Event.h"
#include"TVector3.h"
#include"TMath.h"

namespace PiPiPiPiMath {

  std::vector<TLorentzVector> ConvertEventTo4Vectors(const std::vector<double> &event) {
    std::vector<TLorentzVector> momenta(4);
    for(int i = 0; i < 4; i++) {
      momenta[i] = TLorentzVector(event.data() + 4*i);
    }
    return momenta;
  }
}