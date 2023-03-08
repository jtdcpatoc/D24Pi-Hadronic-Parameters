#ifndef PIPIPIPIMATH
#define PIPIPIPIMATH

#include<vector>
#include"TLorentzVector.h"
#include"Event.h"

namespace PiPiPiPiMath {
  /**
   * Function that converts a vector into a vector of TLorentzVector objects
   * @param event A vector with four-momenta, in the order \f$(K^+, K^-, \pi^+, \pi^-)\f$
   * @return A vector of TLorentzVector objects
   */
  std::vector<TLorentzVector> ConvertEventTo4Vectors(const std::vector<double> &event);
  /**
   * Function that determines the rectangular coordinates of an event
   * @param event Vector of four-momenta of the final states in the event, in the order \f$(K^+, K^-, \pi^+, \pi^-)\f$
   * @return A vector with the five rectangular coordinates
   */
};

#endif