# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/baskin/icub-friends/head_motor_calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baskin/icub-friends/head_motor_calculator

# Include any dependencies generated for this target.
include CMakeFiles/head_motor_calculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/head_motor_calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/head_motor_calculator.dir/flags.make

CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o: CMakeFiles/head_motor_calculator.dir/flags.make
CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o: head_motor_calculator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/baskin/icub-friends/head_motor_calculator/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o -c /home/baskin/icub-friends/head_motor_calculator/head_motor_calculator.cpp

CMakeFiles/head_motor_calculator.dir/head_motor_calculator.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/head_motor_calculator.dir/head_motor_calculator.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/baskin/icub-friends/head_motor_calculator/head_motor_calculator.cpp > CMakeFiles/head_motor_calculator.dir/head_motor_calculator.i

CMakeFiles/head_motor_calculator.dir/head_motor_calculator.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/head_motor_calculator.dir/head_motor_calculator.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/baskin/icub-friends/head_motor_calculator/head_motor_calculator.cpp -o CMakeFiles/head_motor_calculator.dir/head_motor_calculator.s

CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.requires:
.PHONY : CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.requires

CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.provides: CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.requires
	$(MAKE) -f CMakeFiles/head_motor_calculator.dir/build.make CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.provides.build
.PHONY : CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.provides

CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.provides.build: CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o

CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o: CMakeFiles/head_motor_calculator.dir/flags.make
CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o: /home/baskin/icub-friends/class/ObjPosServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/baskin/icub-friends/head_motor_calculator/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o -c /home/baskin/icub-friends/class/ObjPosServer.cpp

CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/baskin/icub-friends/class/ObjPosServer.cpp > CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.i

CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/baskin/icub-friends/class/ObjPosServer.cpp -o CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.s

CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.requires:
.PHONY : CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.requires

CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.provides: CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.requires
	$(MAKE) -f CMakeFiles/head_motor_calculator.dir/build.make CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.provides.build
.PHONY : CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.provides

CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.provides.build: CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o

# Object files for target head_motor_calculator
head_motor_calculator_OBJECTS = \
"CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o" \
"CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o"

# External object files for target head_motor_calculator
head_motor_calculator_EXTERNAL_OBJECTS =

head_motor_calculator: CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o
head_motor_calculator: CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o
head_motor_calculator: CMakeFiles/head_motor_calculator.dir/build.make
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_OS.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_sig.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_math.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_dev.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_init.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_name.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_sig.so.2.3.66
head_motor_calculator: /usr/lib/x86_64-linux-gnu/libYARP_OS.so.2.3.66
head_motor_calculator: CMakeFiles/head_motor_calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable head_motor_calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/head_motor_calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/head_motor_calculator.dir/build: head_motor_calculator
.PHONY : CMakeFiles/head_motor_calculator.dir/build

CMakeFiles/head_motor_calculator.dir/requires: CMakeFiles/head_motor_calculator.dir/head_motor_calculator.o.requires
CMakeFiles/head_motor_calculator.dir/requires: CMakeFiles/head_motor_calculator.dir/home/baskin/icub-friends/class/ObjPosServer.o.requires
.PHONY : CMakeFiles/head_motor_calculator.dir/requires

CMakeFiles/head_motor_calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/head_motor_calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/head_motor_calculator.dir/clean

CMakeFiles/head_motor_calculator.dir/depend:
	cd /home/baskin/icub-friends/head_motor_calculator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baskin/icub-friends/head_motor_calculator /home/baskin/icub-friends/head_motor_calculator /home/baskin/icub-friends/head_motor_calculator /home/baskin/icub-friends/head_motor_calculator /home/baskin/icub-friends/head_motor_calculator/CMakeFiles/head_motor_calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/head_motor_calculator.dir/depend

