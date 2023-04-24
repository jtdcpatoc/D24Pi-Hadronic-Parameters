#include<vector>
#include<string>
#include<complex>
#include<algorithm>
#include<dlfcn.h>
#include<iostream>
#include"../include/Amplitude.h"

#if defined __APPLE__
    #define D0LIB "libD0toKKpipi.dylib"
    #define DBAR0LIB "libDbar0toKKpipi.dylib"
#elif __linux__
    #define D0LIB "libD0toKKpipi.so"
    #define DBAR0LIB "libDbar0toKKpipi.so"
#else
#   error "Unknown compiler"
#endif

Amplitude::Amplitude(const std::string &Damplitude, const std::string &DBARamplitude) {
  void *my_lib_handle_d = dlopen(Damplitude.c_str(), RTLD_NOW);
  void *my_lib_handle_dbar = dlopen(DBARamplitude.c_str(), RTLD_NOW);
  if(my_lib_handle_d == nullptr || my_lib_handle_dbar == nullptr) {
    std::cout << "Cannot find shared libraries\n";
    return;
  }
  m_Damplitude = (std::complex<double> (*)(double const *event, const int &x1)) dlsym(my_lib_handle_d, "AMP");
  m_DBARamplitude = (std::complex<double> (*)(double const *event, const int &x1)) dlsym(my_lib_handle_dbar, "AMP");
  if(m_Damplitude == nullptr || m_DBARamplitude == nullptr) {
    std::cout << "Cannot find function AMP\n";
    return;
  }
}

Amplitude::Amplitude() : Amplitude(D0LIB, DBAR0LIB) {}


std::complex<double> Amplitude::operator()(const std::vector<double> &event, const int &conj) const {
  if(conj == +1) {
    return m_Damplitude(event.data(), +1);
  } else if(conj == -1) {
    return m_DBARamplitude(event.data(), +1);
  }
  return std::complex<double>(0, 0);
}
