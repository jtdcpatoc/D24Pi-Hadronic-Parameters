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
include examples/CMakeFiles/Parameters.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/Parameters.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/Parameters.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/Parameters.dir/flags.make

examples/CMakeFiles/Parameters.dir/Parameters.cpp.o: examples/CMakeFiles/Parameters.dir/flags.make
examples/CMakeFiles/Parameters.dir/Parameters.cpp.o: ../examples/Parameters.cpp
examples/CMakeFiles/Parameters.dir/Parameters.cpp.o: examples/CMakeFiles/Parameters.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/Parameters.dir/Parameters.cpp.o"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && /cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/Parameters.dir/Parameters.cpp.o -MF CMakeFiles/Parameters.dir/Parameters.cpp.o.d -o CMakeFiles/Parameters.dir/Parameters.cpp.o -c /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples/Parameters.cpp

examples/CMakeFiles/Parameters.dir/Parameters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parameters.dir/Parameters.cpp.i"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && /cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples/Parameters.cpp > CMakeFiles/Parameters.dir/Parameters.cpp.i

examples/CMakeFiles/Parameters.dir/Parameters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parameters.dir/Parameters.cpp.s"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && /cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples/Parameters.cpp -o CMakeFiles/Parameters.dir/Parameters.cpp.s

# Object files for target Parameters
Parameters_OBJECTS = \
"CMakeFiles/Parameters.dir/Parameters.cpp.o"

# External object files for target Parameters
Parameters_EXTERNAL_OBJECTS =

examples/Parameters: examples/CMakeFiles/Parameters.dir/Parameters.cpp.o
examples/Parameters: examples/CMakeFiles/Parameters.dir/build.make
examples/Parameters: src/libD02pipipipi_binning_scheme.a
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libPhysics.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libTree.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libGpad.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libGraf.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libHist.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMatrix.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMathMore.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMathCore.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libImt.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libMultiProc.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libNet.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libRIO.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libThread.so
examples/Parameters: /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/lib/libCore.so
examples/Parameters: examples/CMakeFiles/Parameters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Parameters"
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parameters.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/Parameters.dir/build: examples/Parameters
.PHONY : examples/CMakeFiles/Parameters.dir/build

examples/CMakeFiles/Parameters.dir/clean:
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/Parameters.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/Parameters.dir/clean

examples/CMakeFiles/Parameters.dir/depend:
	cd /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/examples /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples /home/patoc/work/DPhil1/D0_Mixing_Generator_Studies/for_jairus/D02pipipipi_binning_scheme/build/examples/CMakeFiles/Parameters.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/Parameters.dir/depend

