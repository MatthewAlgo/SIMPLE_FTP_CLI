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
include CMakeFiles/MyProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProject.dir/flags.make

CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.o: SOURCES/Mysource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthewalgo/DATA/linux-projects/Synth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.o -c /home/matthewalgo/DATA/linux-projects/Synth/SOURCES/Mysource.cpp

CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthewalgo/DATA/linux-projects/Synth/SOURCES/Mysource.cpp > CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.i

CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthewalgo/DATA/linux-projects/Synth/SOURCES/Mysource.cpp -o CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.s

CMakeFiles/MyProject.dir/SOURCES/Source.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/SOURCES/Source.cpp.o: SOURCES/Source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthewalgo/DATA/linux-projects/Synth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyProject.dir/SOURCES/Source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/SOURCES/Source.cpp.o -c /home/matthewalgo/DATA/linux-projects/Synth/SOURCES/Source.cpp

CMakeFiles/MyProject.dir/SOURCES/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/SOURCES/Source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthewalgo/DATA/linux-projects/Synth/SOURCES/Source.cpp > CMakeFiles/MyProject.dir/SOURCES/Source.cpp.i

CMakeFiles/MyProject.dir/SOURCES/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/SOURCES/Source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthewalgo/DATA/linux-projects/Synth/SOURCES/Source.cpp -o CMakeFiles/MyProject.dir/SOURCES/Source.cpp.s

# Object files for target MyProject
MyProject_OBJECTS = \
"CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.o" \
"CMakeFiles/MyProject.dir/SOURCES/Source.cpp.o"

# External object files for target MyProject
MyProject_EXTERNAL_OBJECTS =

MyProject: CMakeFiles/MyProject.dir/SOURCES/Mysource.cpp.o
MyProject: CMakeFiles/MyProject.dir/SOURCES/Source.cpp.o
MyProject: CMakeFiles/MyProject.dir/build.make
MyProject: INCLUDE/libINCLUDE.a
MyProject: CMakeFiles/MyProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matthewalgo/DATA/linux-projects/Synth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MyProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProject.dir/build: MyProject

.PHONY : CMakeFiles/MyProject.dir/build

CMakeFiles/MyProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProject.dir/clean

CMakeFiles/MyProject.dir/depend:
	cd /home/matthewalgo/DATA/linux-projects/Synth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matthewalgo/DATA/linux-projects/Synth /home/matthewalgo/DATA/linux-projects/Synth /home/matthewalgo/DATA/linux-projects/Synth /home/matthewalgo/DATA/linux-projects/Synth /home/matthewalgo/DATA/linux-projects/Synth/CMakeFiles/MyProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyProject.dir/depend

