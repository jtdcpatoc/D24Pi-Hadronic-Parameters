#ifndef AMPLITUDE_H
#define AMPLITUDE_H

#include<vector>
#include<string>
#include<complex>

class Amplitude {
  public:
    /**
    * Constructor that loads the shared library for D and Dbar decay amplitudes
    */
    Amplitude(const std::string &Damplitude, const std::string &DBARamplitude);
    /**
     * Default constructor that uses the standard AmpGen filenames
     */
    Amplitude();
    /**
     * Overload () operator to easily access amplitude
     * @param event Vector of four-momenta of event
     * @param conj Set to +1 for D^0 decay and -1 for DBAR^0 decay
     */
    std::complex<double> operator()(const std::vector<double> &event, const int &conj) const;
  private: 
    /**
     * Amplitude function for D^0 decay
     * @param event Event that we want to calculate the amplitude of
     * @param x1 Set to +1 for amplitude, set to -1 to get conjugate amplitude with charges of outgoing particles swapped
     * @return Ampltitude of the event
     */
    std::complex<double> (*m_Damplitude)(double const* event, const int &x1);
    /**
     * Amplitude function for DBAR^0 decay
     * @param event Event that we want to calculate the amplitude of
     * @param x1 Set to +1 for amplitude, set to -1 to get conjugate amplitude with charges of outgoing particles swapped
     * @return Ampltitude of the event
     */
    std::complex<double> (*m_DBARamplitude)(double const* event, const int &x1);
};

#endif