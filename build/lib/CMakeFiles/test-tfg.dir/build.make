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
CMAKE_SOURCE_DIR = /home/zigbee/gr-tfg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zigbee/gr-tfg/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/test-tfg.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/test-tfg.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/test-tfg.dir/flags.make

lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o: lib/CMakeFiles/test-tfg.dir/flags.make
lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o: ../lib/test_tfg.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zigbee/gr-tfg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o"
	cd /home/zigbee/gr-tfg/build/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-tfg.dir/test_tfg.cc.o -c /home/zigbee/gr-tfg/lib/test_tfg.cc

lib/CMakeFiles/test-tfg.dir/test_tfg.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-tfg.dir/test_tfg.cc.i"
	cd /home/zigbee/gr-tfg/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zigbee/gr-tfg/lib/test_tfg.cc > CMakeFiles/test-tfg.dir/test_tfg.cc.i

lib/CMakeFiles/test-tfg.dir/test_tfg.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-tfg.dir/test_tfg.cc.s"
	cd /home/zigbee/gr-tfg/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zigbee/gr-tfg/lib/test_tfg.cc -o CMakeFiles/test-tfg.dir/test_tfg.cc.s

lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.requires:

.PHONY : lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.requires

lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.provides: lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.requires
	$(MAKE) -f lib/CMakeFiles/test-tfg.dir/build.make lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.provides.build
.PHONY : lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.provides

lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.provides.build: lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o


lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o: lib/CMakeFiles/test-tfg.dir/flags.make
lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o: ../lib/qa_tfg.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zigbee/gr-tfg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o"
	cd /home/zigbee/gr-tfg/build/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-tfg.dir/qa_tfg.cc.o -c /home/zigbee/gr-tfg/lib/qa_tfg.cc

lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-tfg.dir/qa_tfg.cc.i"
	cd /home/zigbee/gr-tfg/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zigbee/gr-tfg/lib/qa_tfg.cc > CMakeFiles/test-tfg.dir/qa_tfg.cc.i

lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-tfg.dir/qa_tfg.cc.s"
	cd /home/zigbee/gr-tfg/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zigbee/gr-tfg/lib/qa_tfg.cc -o CMakeFiles/test-tfg.dir/qa_tfg.cc.s

lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.requires:

.PHONY : lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.requires

lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.provides: lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.requires
	$(MAKE) -f lib/CMakeFiles/test-tfg.dir/build.make lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.provides.build
.PHONY : lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.provides

lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.provides.build: lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o


# Object files for target test-tfg
test__tfg_OBJECTS = \
"CMakeFiles/test-tfg.dir/test_tfg.cc.o" \
"CMakeFiles/test-tfg.dir/qa_tfg.cc.o"

# External object files for target test-tfg
test__tfg_EXTERNAL_OBJECTS =

lib/test-tfg: lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o
lib/test-tfg: lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o
lib/test-tfg: lib/CMakeFiles/test-tfg.dir/build.make
lib/test-tfg: /usr/local/lib/libgnuradio-runtime.so
lib/test-tfg: /usr/local/lib/libgnuradio-pmt.so
lib/test-tfg: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
lib/test-tfg: /usr/lib/x86_64-linux-gnu/libboost_system.so
lib/test-tfg: /usr/lib/x86_64-linux-gnu/libcppunit.so
lib/test-tfg: lib/libgnuradio-tfg-1.0.0git.so.0.0.0
lib/test-tfg: /usr/local/lib/libgnuradio-runtime.so
lib/test-tfg: /usr/local/lib/libgnuradio-pmt.so
lib/test-tfg: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
lib/test-tfg: /usr/lib/x86_64-linux-gnu/libboost_system.so
lib/test-tfg: lib/CMakeFiles/test-tfg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zigbee/gr-tfg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test-tfg"
	cd /home/zigbee/gr-tfg/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-tfg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/test-tfg.dir/build: lib/test-tfg

.PHONY : lib/CMakeFiles/test-tfg.dir/build

lib/CMakeFiles/test-tfg.dir/requires: lib/CMakeFiles/test-tfg.dir/test_tfg.cc.o.requires
lib/CMakeFiles/test-tfg.dir/requires: lib/CMakeFiles/test-tfg.dir/qa_tfg.cc.o.requires

.PHONY : lib/CMakeFiles/test-tfg.dir/requires

lib/CMakeFiles/test-tfg.dir/clean:
	cd /home/zigbee/gr-tfg/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/test-tfg.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/test-tfg.dir/clean

lib/CMakeFiles/test-tfg.dir/depend:
	cd /home/zigbee/gr-tfg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zigbee/gr-tfg /home/zigbee/gr-tfg/lib /home/zigbee/gr-tfg/build /home/zigbee/gr-tfg/build/lib /home/zigbee/gr-tfg/build/lib/CMakeFiles/test-tfg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/test-tfg.dir/depend

