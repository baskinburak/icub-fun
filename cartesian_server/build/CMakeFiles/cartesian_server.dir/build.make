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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fatih/Desktop/icub-pusher/cartesian_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fatih/Desktop/icub-pusher/cartesian_server/build

# Include any dependencies generated for this target.
include CMakeFiles/cartesian_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cartesian_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cartesian_server.dir/flags.make

CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o: CMakeFiles/cartesian_server.dir/flags.make
CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o: ../cartesian_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fatih/Desktop/icub-pusher/cartesian_server/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o -c /home/fatih/Desktop/icub-pusher/cartesian_server/cartesian_server.cpp

CMakeFiles/cartesian_server.dir/cartesian_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cartesian_server.dir/cartesian_server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fatih/Desktop/icub-pusher/cartesian_server/cartesian_server.cpp > CMakeFiles/cartesian_server.dir/cartesian_server.cpp.i

CMakeFiles/cartesian_server.dir/cartesian_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cartesian_server.dir/cartesian_server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fatih/Desktop/icub-pusher/cartesian_server/cartesian_server.cpp -o CMakeFiles/cartesian_server.dir/cartesian_server.cpp.s

CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.requires:
.PHONY : CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.requires

CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.provides: CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/cartesian_server.dir/build.make CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.provides.build
.PHONY : CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.provides

CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.provides.build: CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o

CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o: CMakeFiles/cartesian_server.dir/flags.make
CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o: /home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fatih/Desktop/icub-pusher/cartesian_server/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o -c /home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp

CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp > CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.i

CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp -o CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.s

CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.requires:
.PHONY : CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.requires

CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.provides: CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/cartesian_server.dir/build.make CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.provides.build
.PHONY : CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.provides

CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.provides.build: CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o

# Object files for target cartesian_server
cartesian_server_OBJECTS = \
"CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o" \
"CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o"

# External object files for target cartesian_server
cartesian_server_EXTERNAL_OBJECTS =

cartesian_server: CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o
cartesian_server: CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o
cartesian_server: CMakeFiles/cartesian_server.dir/build.make
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_OS.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_sig.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_math.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_dev.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_init.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_name.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_sig.so.2.3.66
cartesian_server: /usr/lib/x86_64-linux-gnu/libYARP_OS.so.2.3.66
cartesian_server: CMakeFiles/cartesian_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cartesian_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cartesian_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cartesian_server.dir/build: cartesian_server
.PHONY : CMakeFiles/cartesian_server.dir/build

CMakeFiles/cartesian_server.dir/requires: CMakeFiles/cartesian_server.dir/cartesian_server.cpp.o.requires
CMakeFiles/cartesian_server.dir/requires: CMakeFiles/cartesian_server.dir/home/fatih/Desktop/icub-pusher/class/ObjPosServer.cpp.o.requires
.PHONY : CMakeFiles/cartesian_server.dir/requires

CMakeFiles/cartesian_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cartesian_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cartesian_server.dir/clean

CMakeFiles/cartesian_server.dir/depend:
	cd /home/fatih/Desktop/icub-pusher/cartesian_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fatih/Desktop/icub-pusher/cartesian_server /home/fatih/Desktop/icub-pusher/cartesian_server /home/fatih/Desktop/icub-pusher/cartesian_server/build /home/fatih/Desktop/icub-pusher/cartesian_server/build /home/fatih/Desktop/icub-pusher/cartesian_server/build/CMakeFiles/cartesian_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cartesian_server.dir/depend
