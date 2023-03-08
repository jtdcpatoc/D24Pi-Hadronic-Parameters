#include<vector>
#include<string>
#include<complex>
#include<algorithm>
#include<dlfcn.h>
#include<iostream>
#include"../include/Amplitude.h"

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
/*
// This is for the full D0 amplitude model 
Amplitude::Amplitude(): Amplitude("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/DC_Tuples/new3_0.1_D0-nor-4pi-mixing_CPV.so", "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/DC_Tuples/new3_0.1_D0-bar-4pi-mixing_CPV.so") {
}
*/


Amplitude::Amplitude(): Amplitude("/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/DC_Tuples/NotConj.so", "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/DC_Tuples/Conj.so") {
}


std::complex<double> Amplitude::operator()(const std::vector<double> &event, const int &conj) const {
  if(conj == +1) {
    return m_Damplitude(event.data(), +1);
  } else if(conj == -1) {
    return m_DBARamplitude(event.data(), +1);
  }
  return std::complex<double>(0, 0);
}