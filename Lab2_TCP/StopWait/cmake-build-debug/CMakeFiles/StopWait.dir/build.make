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
include CMakeFiles/StopWait.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StopWait.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StopWait.dir/flags.make

CMakeFiles/StopWait.dir/src/StopWait.cpp.o: CMakeFiles/StopWait.dir/flags.make
CMakeFiles/StopWait.dir/src/StopWait.cpp.o: ../src/StopWait.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StopWait.dir/src/StopWait.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StopWait.dir/src/StopWait.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWait.cpp

CMakeFiles/StopWait.dir/src/StopWait.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StopWait.dir/src/StopWait.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWait.cpp > CMakeFiles/StopWait.dir/src/StopWait.cpp.i

CMakeFiles/StopWait.dir/src/StopWait.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StopWait.dir/src/StopWait.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWait.cpp -o CMakeFiles/StopWait.dir/src/StopWait.cpp.s

CMakeFiles/StopWait.dir/src/StopWait.cpp.o.requires:

.PHONY : CMakeFiles/StopWait.dir/src/StopWait.cpp.o.requires

CMakeFiles/StopWait.dir/src/StopWait.cpp.o.provides: CMakeFiles/StopWait.dir/src/StopWait.cpp.o.requires
	$(MAKE) -f CMakeFiles/StopWait.dir/build.make CMakeFiles/StopWait.dir/src/StopWait.cpp.o.provides.build
.PHONY : CMakeFiles/StopWait.dir/src/StopWait.cpp.o.provides

CMakeFiles/StopWait.dir/src/StopWait.cpp.o.provides.build: CMakeFiles/StopWait.dir/src/StopWait.cpp.o


CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o: CMakeFiles/StopWait.dir/flags.make
CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o: ../src/StopWaitRdtReceiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWaitRdtReceiver.cpp

CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWaitRdtReceiver.cpp > CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.i

CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWaitRdtReceiver.cpp -o CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.s

CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.requires:

.PHONY : CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.requires

CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.provides: CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.requires
	$(MAKE) -f CMakeFiles/StopWait.dir/build.make CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.provides.build
.PHONY : CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.provides

CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.provides.build: CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o


CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o: CMakeFiles/StopWait.dir/flags.make
CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o: ../src/StopWaitRdtSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWaitRdtSender.cpp

CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWaitRdtSender.cpp > CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.i

CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/StopWaitRdtSender.cpp -o CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.s

CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.requires:

.PHONY : CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.requires

CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.provides: CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.requires
	$(MAKE) -f CMakeFiles/StopWait.dir/build.make CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.provides.build
.PHONY : CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.provides

CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.provides.build: CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o


CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o: CMakeFiles/StopWait.dir/flags.make
CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o: ../src/GBNRdtSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/GBNRdtSender.cpp

CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/GBNRdtSender.cpp > CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.i

CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/GBNRdtSender.cpp -o CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.s

CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.requires:

.PHONY : CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.requires

CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.provides: CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.requires
	$(MAKE) -f CMakeFiles/StopWait.dir/build.make CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.provides.build
.PHONY : CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.provides

CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.provides.build: CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o


CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o: CMakeFiles/StopWait.dir/flags.make
CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o: ../src/GBNRdtReceiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o -c /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/GBNRdtReceiver.cpp

CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/GBNRdtReceiver.cpp > CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.i

CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/src/GBNRdtReceiver.cpp -o CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.s

CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.requires:

.PHONY : CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.requires

CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.provides: CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.requires
	$(MAKE) -f CMakeFiles/StopWait.dir/build.make CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.provides.build
.PHONY : CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.provides

CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.provides.build: CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o


# Object files for target StopWait
StopWait_OBJECTS = \
"CMakeFiles/StopWait.dir/src/StopWait.cpp.o" \
"CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o" \
"CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o" \
"CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o" \
"CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o"

# External object files for target StopWait
StopWait_EXTERNAL_OBJECTS =

../bin/StopWait: CMakeFiles/StopWait.dir/src/StopWait.cpp.o
../bin/StopWait: CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o
../bin/StopWait: CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o
../bin/StopWait: CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o
../bin/StopWait: CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o
../bin/StopWait: CMakeFiles/StopWait.dir/build.make
../bin/StopWait: CMakeFiles/StopWait.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/StopWait"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StopWait.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StopWait.dir/build: ../bin/StopWait

.PHONY : CMakeFiles/StopWait.dir/build

CMakeFiles/StopWait.dir/requires: CMakeFiles/StopWait.dir/src/StopWait.cpp.o.requires
CMakeFiles/StopWait.dir/requires: CMakeFiles/StopWait.dir/src/StopWaitRdtReceiver.cpp.o.requires
CMakeFiles/StopWait.dir/requires: CMakeFiles/StopWait.dir/src/StopWaitRdtSender.cpp.o.requires
CMakeFiles/StopWait.dir/requires: CMakeFiles/StopWait.dir/src/GBNRdtSender.cpp.o.requires
CMakeFiles/StopWait.dir/requires: CMakeFiles/StopWait.dir/src/GBNRdtReceiver.cpp.o.requires

.PHONY : CMakeFiles/StopWait.dir/requires

CMakeFiles/StopWait.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StopWait.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StopWait.dir/clean

CMakeFiles/StopWait.dir/depend:
	cd /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug /home/narrow/Computer_Network_Lab/Lab2_TCP/StopWait/cmake-build-debug/CMakeFiles/StopWait.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StopWait.dir/depend
