# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matthewalgo/DATA/linux-projects/Synth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matthewalgo/DATA/linux-projects/Synth

# Include any dependencies generated for this target.
include INCLUDE/CMakeFiles/INCLUDE.dir/depend.make

# Include the progress variables for this target.
include INCLUDE/CMakeFiles/INCLUDE.dir/progress.make

# Include the compile flags for this target's objects.
include INCLUDE/CMakeFiles/INCLUDE.dir/flags.make

INCLUDE/CMakeFiles/INCLUDE.dir/CPP.cpp.o: INCLUDE/CMakeFiles/INCLUDE.dir/flags.make
INCLUDE/CMakeFiles/INCLUDE.dir/CPP.cpp.o: INCLUDE/CPP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthewalgo/DATA/linux-projects/Synth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object INCLUDE/CMakeFiles/INCLUDE.dir/CPP.cpp.o"
	cd /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/INCLUDE.dir/CPP.cpp.o -c /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE/CPP.cpp

INCLUDE/CMakeFiles/INCLUDE.dir/CPP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/INCLUDE.dir/CPP.cpp.i"
	cd /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE/CPP.cpp > CMakeFiles/INCLUDE.dir/CPP.cpp.i

INCLUDE/CMakeFiles/INCLUDE.dir/CPP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/INCLUDE.dir/CPP.cpp.s"
	cd /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE/CPP.cpp -o CMakeFiles/INCLUDE.dir/CPP.cpp.s

# Object files for target INCLUDE
INCLUDE_OBJECTS = \
"CMakeFiles/INCLUDE.dir/CPP.cpp.o"

# External object files for target INCLUDE
INCLUDE_EXTERNAL_OBJECTS =

INCLUDE/libINCLUDE.a: INCLUDE/CMakeFiles/INCLUDE.dir/CPP.cpp.o
INCLUDE/libINCLUDE.a: INCLUDE/CMakeFiles/INCLUDE.dir/build.make
INCLUDE/libINCLUDE.a: INCLUDE/CMakeFiles/INCLUDE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matthewalgo/DATA/linux-projects/Synth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libINCLUDE.a"
	cd /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE && $(CMAKE_COMMAND) -P CMakeFiles/INCLUDE.dir/cmake_clean_target.cmake
	cd /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/INCLUDE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
INCLUDE/CMakeFiles/INCLUDE.dir/build: INCLUDE/libINCLUDE.a

.PHONY : INCLUDE/CMakeFiles/INCLUDE.dir/build

INCLUDE/CMakeFiles/INCLUDE.dir/clean:
	cd /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE && $(CMAKE_COMMAND) -P CMakeFiles/INCLUDE.dir/cmake_clean.cmake
.PHONY : INCLUDE/CMakeFiles/INCLUDE.dir/clean

INCLUDE/CMakeFiles/INCLUDE.dir/depend:
	cd /home/matthewalgo/DATA/linux-projects/Synth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matthewalgo/DATA/linux-projects/Synth /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE /home/matthewalgo/DATA/linux-projects/Synth /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE /home/matthewalgo/DATA/linux-projects/Synth/INCLUDE/CMakeFiles/INCLUDE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : INCLUDE/CMakeFiles/INCLUDE.dir/depend

