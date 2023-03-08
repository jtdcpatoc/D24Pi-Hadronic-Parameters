# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.20.0-790a8/x86_64-centos7-gcc11-opt/bin/cmake

# The command to remove a file.
RM = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.20.0-790a8/x86_64-centos7-gcc11-opt/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/MinimalExample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/MinimalExample.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/MinimalExample.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/MinimalExample.dir/flags.make

examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o: examples/CMakeFiles/MinimalExample.dir/flags.make
examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o: ../examples/MinimalExample.cpp
examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o: examples/CMakeFiles/MinimalExample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && /cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o -MF CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o.d -o CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o -c /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples/MinimalExample.cpp

examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MinimalExample.dir/MinimalExample.cpp.i"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && /cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples/MinimalExample.cpp > CMakeFiles/MinimalExample.dir/MinimalExample.cpp.i

examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MinimalExample.dir/MinimalExample.cpp.s"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && /cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples/MinimalExample.cpp -o CMakeFiles/MinimalExample.dir/MinimalExample.cpp.s

# Object files for target MinimalExample
MinimalExample_OBJECTS = \
"CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o"

# External object files for target MinimalExample
MinimalExample_EXTERNAL_OBJECTS =

examples/MinimalExample: examples/CMakeFiles/MinimalExample.dir/MinimalExample.cpp.o
examples/MinimalExample: examples/CMakeFiles/MinimalExample.dir/build.make
examples/MinimalExample: src/libD02pipipipi_binning_scheme.a
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libPhysics.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libTree.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libGpad.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libGraf.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libHist.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMatrix.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMathMore.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMathCore.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libImt.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMultiProc.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libNet.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libRIO.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libThread.so
examples/MinimalExample: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libCore.so
examples/MinimalExample: examples/CMakeFiles/MinimalExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MinimalExample"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MinimalExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/MinimalExample.dir/build: examples/MinimalExample
.PHONY : examples/CMakeFiles/MinimalExample.dir/build

examples/CMakeFiles/MinimalExample.dir/clean:
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/MinimalExample.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/MinimalExample.dir/clean

examples/CMakeFiles/MinimalExample.dir/depend:
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/CMakeFiles/MinimalExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/MinimalExample.dir/depend

