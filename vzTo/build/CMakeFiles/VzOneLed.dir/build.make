# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/tarik/vzTo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tarik/vzTo/build

# Include any dependencies generated for this target.
include CMakeFiles/VzOneLed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VzOneLed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VzOneLed.dir/flags.make

CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o: CMakeFiles/VzOneLed.dir/flags.make
CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o: ../VzOneLed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tarik/vzTo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o -c /home/tarik/vzTo/VzOneLed.cpp

CMakeFiles/VzOneLed.dir/VzOneLed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VzOneLed.dir/VzOneLed.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tarik/vzTo/VzOneLed.cpp > CMakeFiles/VzOneLed.dir/VzOneLed.cpp.i

CMakeFiles/VzOneLed.dir/VzOneLed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VzOneLed.dir/VzOneLed.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tarik/vzTo/VzOneLed.cpp -o CMakeFiles/VzOneLed.dir/VzOneLed.cpp.s

CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.requires:

.PHONY : CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.requires

CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.provides: CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.requires
	$(MAKE) -f CMakeFiles/VzOneLed.dir/build.make CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.provides.build
.PHONY : CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.provides

CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.provides.build: CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o


# Object files for target VzOneLed
VzOneLed_OBJECTS = \
"CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o"

# External object files for target VzOneLed
VzOneLed_EXTERNAL_OBJECTS =

VzOneLed: CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o
VzOneLed: CMakeFiles/VzOneLed.dir/build.make
VzOneLed: /usr/local/lib/libYARP_math.so.2.3.66
VzOneLed: /usr/local/lib/libYARP_dev.so.2.3.66
VzOneLed: /usr/local/lib/libYARP_init.so.2.3.66
VzOneLed: /usr/local/lib/libYARP_name.so.2.3.66
VzOneLed: /usr/local/lib/libYARP_sig.so.2.3.66
VzOneLed: /usr/local/lib/libYARP_OS.so.2.3.66
VzOneLed: CMakeFiles/VzOneLed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tarik/vzTo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VzOneLed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VzOneLed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VzOneLed.dir/build: VzOneLed

.PHONY : CMakeFiles/VzOneLed.dir/build

CMakeFiles/VzOneLed.dir/requires: CMakeFiles/VzOneLed.dir/VzOneLed.cpp.o.requires

.PHONY : CMakeFiles/VzOneLed.dir/requires

CMakeFiles/VzOneLed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VzOneLed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VzOneLed.dir/clean

CMakeFiles/VzOneLed.dir/depend:
	cd /home/tarik/vzTo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tarik/vzTo /home/tarik/vzTo /home/tarik/vzTo/build /home/tarik/vzTo/build /home/tarik/vzTo/build/CMakeFiles/VzOneLed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VzOneLed.dir/depend

