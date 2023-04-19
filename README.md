# D24Pi-Hadronic-Parameters
Code which, mainly, is for the D -> pipipipi decay. However, there are two examples for D -> KKpipi.Based on Hyperplot by Sam Harnew and examples by Xiaodong Shi. Provided by Martin Tat.

This purpose of this code is to calculate the Hadronic parameters for a given binning scheme using MC integration of flat phase-space events. There are also scripts that are able to bin simulated data - in preperation for fitting to get measurements of the charm mixing parameters.

# Setup
- cmake version 3
- C++ compiler with C++14
- ROOT version 6.22

# Installation
First, you need to get the version of ROOT: 
```
source /cvmfs/sft.cern.ch/lcg/views/setupViews.sh LCG_102 x86_64-centos7-gcc11-opt
```

Then, to install: 

```
git clone https://github.com/jtdcpatoc/D24Pi-Hadronic-Parameters.git
cd D24Pi-Hadronic-Parameters
mkdir build
cd build
cmake ..
make install -j 4
```

# Installation
The executables are located in `build/examples`.
