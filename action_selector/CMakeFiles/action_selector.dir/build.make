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
CMAKE_SOURCE_DIR = /home/baskin/icub-friends/action_selector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baskin/icub-friends/action_selector

# Include any dependencies generated for this target.
include CMakeFiles/action_selector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/action_selector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/action_selector.dir/flags.make

CMakeFiles/action_selector.dir/action_selector.o: CMakeFiles/action_selector.dir/flags.make
CMakeFiles/action_selector.dir/action_selector.o: action_selector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/baskin/icub-friends/action_selector/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/action_selector.dir/action_selector.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/action_selector.dir/action_selector.o -c /home/baskin/icub-friends/action_selector/action_selector.cpp

CMakeFiles/action_selector.dir/action_selector.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/action_selector.dir/action_selector.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/baskin/icub-friends/action_selector/action_selector.cpp > CMakeFiles/action_selector.dir/action_selector.i

CMakeFiles/action_selector.dir/action_selector.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/action_selector.dir/action_selector.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/baskin/icub-friends/action_selector/action_selector.cpp -o CMakeFiles/action_selector.dir/action_selector.s

CMakeFiles/action_selector.dir/action_selector.o.requires:
.PHONY : CMakeFiles/action_selector.dir/action_selector.o.requires

CMakeFiles/action_selector.dir/action_selector.o.provides: CMakeFiles/action_selector.dir/action_selector.o.requires
	$(MAKE) -f CMakeFiles/action_selector.dir/build.make CMakeFiles/action_selector.dir/action_selector.o.provides.build
.PHONY : CMakeFiles/action_selector.dir/action_selector.o.provides

CMakeFiles/action_selector.dir/action_selector.o.provides.build: CMakeFiles/action_selector.dir/action_selector.o

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o: CMakeFiles/action_selector.dir/flags.make
CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o: /home/baskin/icub-friends/class/YarpPortReader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/baskin/icub-friends/action_selector/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o -c /home/baskin/icub-friends/class/YarpPortReader.cpp

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/baskin/icub-friends/class/YarpPortReader.cpp > CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.i

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/baskin/icub-friends/class/YarpPortReader.cpp -o CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.s

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.requires:
.PHONY : CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.requires

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.provides: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.requires
	$(MAKE) -f CMakeFiles/action_selector.dir/build.make CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.provides.build
.PHONY : CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.provides

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.provides.build: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o: CMakeFiles/action_selector.dir/flags.make
CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o: /home/baskin/icub-friends/class/MotorController.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/baskin/icub-friends/action_selector/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o -c /home/baskin/icub-friends/class/MotorController.cpp

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/baskin/icub-friends/class/MotorController.cpp > CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.i

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/baskin/icub-friends/class/MotorController.cpp -o CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.s

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.requires:
.PHONY : CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.requires

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.provides: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.requires
	$(MAKE) -f CMakeFiles/action_selector.dir/build.make CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.provides.build
.PHONY : CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.provides

CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.provides.build: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o

# Object files for target action_selector
action_selector_OBJECTS = \
"CMakeFiles/action_selector.dir/action_selector.o" \
"CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o" \
"CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o"

# External object files for target action_selector
action_selector_EXTERNAL_OBJECTS =

action_selector: CMakeFiles/action_selector.dir/action_selector.o
action_selector: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o
action_selector: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o
action_selector: CMakeFiles/action_selector.dir/build.make
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_OS.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_sig.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_math.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_dev.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_init.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_name.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_sig.so.2.3.66
action_selector: /usr/lib/x86_64-linux-gnu/libYARP_OS.so.2.3.66
action_selector: CMakeFiles/action_selector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable action_selector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/action_selector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/action_selector.dir/build: action_selector
.PHONY : CMakeFiles/action_selector.dir/build

CMakeFiles/action_selector.dir/requires: CMakeFiles/action_selector.dir/action_selector.o.requires
CMakeFiles/action_selector.dir/requires: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/YarpPortReader.o.requires
CMakeFiles/action_selector.dir/requires: CMakeFiles/action_selector.dir/home/baskin/icub-friends/class/MotorController.o.requires
.PHONY : CMakeFiles/action_selector.dir/requires

CMakeFiles/action_selector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/action_selector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/action_selector.dir/clean

CMakeFiles/action_selector.dir/depend:
	cd /home/baskin/icub-friends/action_selector && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baskin/icub-friends/action_selector /home/baskin/icub-friends/action_selector /home/baskin/icub-friends/action_selector /home/baskin/icub-friends/action_selector /home/baskin/icub-friends/action_selector/CMakeFiles/action_selector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/action_selector.dir/depend

