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
CMAKE_SOURCE_DIR = /home/kpit/Downloads/Walkie-Talkie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kpit/Downloads/Walkie-Talkie/build

# Include any dependencies generated for this target.
include Client/CMakeFiles/ClientMain.dir/depend.make

# Include the progress variables for this target.
include Client/CMakeFiles/ClientMain.dir/progress.make

# Include the compile flags for this target's objects.
include Client/CMakeFiles/ClientMain.dir/flags.make

Client/CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.o: Client/CMakeFiles/ClientMain.dir/flags.make
Client/CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.o: ../Client/src/ClientSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kpit/Downloads/Walkie-Talkie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Client/CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.o"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.o -c /home/kpit/Downloads/Walkie-Talkie/Client/src/ClientSocket.cpp

Client/CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.i"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kpit/Downloads/Walkie-Talkie/Client/src/ClientSocket.cpp > CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.i

Client/CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.s"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kpit/Downloads/Walkie-Talkie/Client/src/ClientSocket.cpp -o CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.s

Client/CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.o: Client/CMakeFiles/ClientMain.dir/flags.make
Client/CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.o: ../Client/src/ClientSocketMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kpit/Downloads/Walkie-Talkie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Client/CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.o"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.o -c /home/kpit/Downloads/Walkie-Talkie/Client/src/ClientSocketMain.cpp

Client/CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.i"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kpit/Downloads/Walkie-Talkie/Client/src/ClientSocketMain.cpp > CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.i

Client/CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.s"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kpit/Downloads/Walkie-Talkie/Client/src/ClientSocketMain.cpp -o CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.s

# Object files for target ClientMain
ClientMain_OBJECTS = \
"CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.o" \
"CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.o"

# External object files for target ClientMain
ClientMain_EXTERNAL_OBJECTS =

Client/ClientMain: Client/CMakeFiles/ClientMain.dir/src/ClientSocket.cpp.o
Client/ClientMain: Client/CMakeFiles/ClientMain.dir/src/ClientSocketMain.cpp.o
Client/ClientMain: Client/CMakeFiles/ClientMain.dir/build.make
Client/ClientMain: Client/CMakeFiles/ClientMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kpit/Downloads/Walkie-Talkie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ClientMain"
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClientMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Client/CMakeFiles/ClientMain.dir/build: Client/ClientMain

.PHONY : Client/CMakeFiles/ClientMain.dir/build

Client/CMakeFiles/ClientMain.dir/clean:
	cd /home/kpit/Downloads/Walkie-Talkie/build/Client && $(CMAKE_COMMAND) -P CMakeFiles/ClientMain.dir/cmake_clean.cmake
.PHONY : Client/CMakeFiles/ClientMain.dir/clean

Client/CMakeFiles/ClientMain.dir/depend:
	cd /home/kpit/Downloads/Walkie-Talkie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kpit/Downloads/Walkie-Talkie /home/kpit/Downloads/Walkie-Talkie/Client /home/kpit/Downloads/Walkie-Talkie/build /home/kpit/Downloads/Walkie-Talkie/build/Client /home/kpit/Downloads/Walkie-Talkie/build/Client/CMakeFiles/ClientMain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Client/CMakeFiles/ClientMain.dir/depend
