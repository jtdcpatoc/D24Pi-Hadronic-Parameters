# Install script for directory: /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.37-355ed/x86_64-centos7/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin" TYPE EXECUTABLE FILES "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/MinimalExample")
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample"
         OLD_RPATH "/cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.37-355ed/x86_64-centos7/bin/strip" "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/MinimalExample")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin" TYPE EXECUTABLE FILES "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/BinningScheme")
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme"
         OLD_RPATH "/cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.37-355ed/x86_64-centos7/bin/strip" "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/BinningScheme")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin" TYPE EXECUTABLE FILES "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/GenerateFlat")
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat"
         OLD_RPATH "/cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.37-355ed/x86_64-centos7/bin/strip" "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/GenerateFlat")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin" TYPE EXECUTABLE FILES "/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/Parameters")
  if(EXISTS "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters"
         OLD_RPATH "/cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.37-355ed/x86_64-centos7/bin/strip" "$ENV{DESTDIR}/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/../bin/Parameters")
    endif()
  endif()
endif()

