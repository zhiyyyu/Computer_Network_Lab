# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SR.dir/flags.make

CMakeFiles/SR.dir/src/SR.cpp.o: CMakeFiles/SR.dir/flags.make
CMakeFiles/SR.dir/src/SR.cpp.o: ../src/SR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SR.dir/src/SR.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SR.dir/src/SR.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SR.cpp

CMakeFiles/SR.dir/src/SR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SR.dir/src/SR.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SR.cpp > CMakeFiles/SR.dir/src/SR.cpp.i

CMakeFiles/SR.dir/src/SR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SR.dir/src/SR.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SR.cpp -o CMakeFiles/SR.dir/src/SR.cpp.s

CMakeFiles/SR.dir/src/SR.cpp.o.requires:

.PHONY : CMakeFiles/SR.dir/src/SR.cpp.o.requires

CMakeFiles/SR.dir/src/SR.cpp.o.provides: CMakeFiles/SR.dir/src/SR.cpp.o.requires
	$(MAKE) -f CMakeFiles/SR.dir/build.make CMakeFiles/SR.dir/src/SR.cpp.o.provides.build
.PHONY : CMakeFiles/SR.dir/src/SR.cpp.o.provides

CMakeFiles/SR.dir/src/SR.cpp.o.provides.build: CMakeFiles/SR.dir/src/SR.cpp.o


CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o: CMakeFiles/SR.dir/flags.make
CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o: ../src/SRRdtReceiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SRRdtReceiver.cpp

CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SRRdtReceiver.cpp > CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.i

CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SRRdtReceiver.cpp -o CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.s

CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.requires:

.PHONY : CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.requires

CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.provides: CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.requires
	$(MAKE) -f CMakeFiles/SR.dir/build.make CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.provides.build
.PHONY : CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.provides

CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.provides.build: CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o


CMakeFiles/SR.dir/src/SRRdtSender.cpp.o: CMakeFiles/SR.dir/flags.make
CMakeFiles/SR.dir/src/SRRdtSender.cpp.o: ../src/SRRdtSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SR.dir/src/SRRdtSender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SR.dir/src/SRRdtSender.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SRRdtSender.cpp

CMakeFiles/SR.dir/src/SRRdtSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SR.dir/src/SRRdtSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SRRdtSender.cpp > CMakeFiles/SR.dir/src/SRRdtSender.cpp.i

CMakeFiles/SR.dir/src/SRRdtSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SR.dir/src/SRRdtSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/SRRdtSender.cpp -o CMakeFiles/SR.dir/src/SRRdtSender.cpp.s

CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.requires:

.PHONY : CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.requires

CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.provides: CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.requires
	$(MAKE) -f CMakeFiles/SR.dir/build.make CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.provides.build
.PHONY : CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.provides

CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.provides.build: CMakeFiles/SR.dir/src/SRRdtSender.cpp.o


# Object files for target SR
SR_OBJECTS = \
"CMakeFiles/SR.dir/src/SR.cpp.o" \
"CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o" \
"CMakeFiles/SR.dir/src/SRRdtSender.cpp.o"

# External object files for target SR
SR_EXTERNAL_OBJECTS =

../bin/SR: CMakeFiles/SR.dir/src/SR.cpp.o
../bin/SR: CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o
../bin/SR: CMakeFiles/SR.dir/src/SRRdtSender.cpp.o
../bin/SR: CMakeFiles/SR.dir/build.make
../bin/SR: CMakeFiles/SR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/SR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SR.dir/build: ../bin/SR

.PHONY : CMakeFiles/SR.dir/build

CMakeFiles/SR.dir/requires: CMakeFiles/SR.dir/src/SR.cpp.o.requires
CMakeFiles/SR.dir/requires: CMakeFiles/SR.dir/src/SRRdtReceiver.cpp.o.requires
CMakeFiles/SR.dir/requires: CMakeFiles/SR.dir/src/SRRdtSender.cpp.o.requires

.PHONY : CMakeFiles/SR.dir/requires

CMakeFiles/SR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SR.dir/clean

CMakeFiles/SR.dir/depend:
	cd /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles/SR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SR.dir/depend

