# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/gw/Documents/opengl_snake/opengl_snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/opengl_snake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl_snake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl_snake.dir/flags.make

CMakeFiles/opengl_snake.dir/canvas.cpp.o: CMakeFiles/opengl_snake.dir/flags.make
CMakeFiles/opengl_snake.dir/canvas.cpp.o: /home/gw/Documents/opengl_snake/opengl_snake/canvas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl_snake.dir/canvas.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_snake.dir/canvas.cpp.o -c /home/gw/Documents/opengl_snake/opengl_snake/canvas.cpp

CMakeFiles/opengl_snake.dir/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_snake.dir/canvas.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gw/Documents/opengl_snake/opengl_snake/canvas.cpp > CMakeFiles/opengl_snake.dir/canvas.cpp.i

CMakeFiles/opengl_snake.dir/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_snake.dir/canvas.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gw/Documents/opengl_snake/opengl_snake/canvas.cpp -o CMakeFiles/opengl_snake.dir/canvas.cpp.s

CMakeFiles/opengl_snake.dir/canvas.cpp.o.requires:

.PHONY : CMakeFiles/opengl_snake.dir/canvas.cpp.o.requires

CMakeFiles/opengl_snake.dir/canvas.cpp.o.provides: CMakeFiles/opengl_snake.dir/canvas.cpp.o.requires
	$(MAKE) -f CMakeFiles/opengl_snake.dir/build.make CMakeFiles/opengl_snake.dir/canvas.cpp.o.provides.build
.PHONY : CMakeFiles/opengl_snake.dir/canvas.cpp.o.provides

CMakeFiles/opengl_snake.dir/canvas.cpp.o.provides.build: CMakeFiles/opengl_snake.dir/canvas.cpp.o


CMakeFiles/opengl_snake.dir/game.cpp.o: CMakeFiles/opengl_snake.dir/flags.make
CMakeFiles/opengl_snake.dir/game.cpp.o: /home/gw/Documents/opengl_snake/opengl_snake/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/opengl_snake.dir/game.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_snake.dir/game.cpp.o -c /home/gw/Documents/opengl_snake/opengl_snake/game.cpp

CMakeFiles/opengl_snake.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_snake.dir/game.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gw/Documents/opengl_snake/opengl_snake/game.cpp > CMakeFiles/opengl_snake.dir/game.cpp.i

CMakeFiles/opengl_snake.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_snake.dir/game.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gw/Documents/opengl_snake/opengl_snake/game.cpp -o CMakeFiles/opengl_snake.dir/game.cpp.s

CMakeFiles/opengl_snake.dir/game.cpp.o.requires:

.PHONY : CMakeFiles/opengl_snake.dir/game.cpp.o.requires

CMakeFiles/opengl_snake.dir/game.cpp.o.provides: CMakeFiles/opengl_snake.dir/game.cpp.o.requires
	$(MAKE) -f CMakeFiles/opengl_snake.dir/build.make CMakeFiles/opengl_snake.dir/game.cpp.o.provides.build
.PHONY : CMakeFiles/opengl_snake.dir/game.cpp.o.provides

CMakeFiles/opengl_snake.dir/game.cpp.o.provides.build: CMakeFiles/opengl_snake.dir/game.cpp.o


CMakeFiles/opengl_snake.dir/main.cpp.o: CMakeFiles/opengl_snake.dir/flags.make
CMakeFiles/opengl_snake.dir/main.cpp.o: /home/gw/Documents/opengl_snake/opengl_snake/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/opengl_snake.dir/main.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_snake.dir/main.cpp.o -c /home/gw/Documents/opengl_snake/opengl_snake/main.cpp

CMakeFiles/opengl_snake.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_snake.dir/main.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gw/Documents/opengl_snake/opengl_snake/main.cpp > CMakeFiles/opengl_snake.dir/main.cpp.i

CMakeFiles/opengl_snake.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_snake.dir/main.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gw/Documents/opengl_snake/opengl_snake/main.cpp -o CMakeFiles/opengl_snake.dir/main.cpp.s

CMakeFiles/opengl_snake.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/opengl_snake.dir/main.cpp.o.requires

CMakeFiles/opengl_snake.dir/main.cpp.o.provides: CMakeFiles/opengl_snake.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/opengl_snake.dir/build.make CMakeFiles/opengl_snake.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/opengl_snake.dir/main.cpp.o.provides

CMakeFiles/opengl_snake.dir/main.cpp.o.provides.build: CMakeFiles/opengl_snake.dir/main.cpp.o


CMakeFiles/opengl_snake.dir/shader.cpp.o: CMakeFiles/opengl_snake.dir/flags.make
CMakeFiles/opengl_snake.dir/shader.cpp.o: /home/gw/Documents/opengl_snake/opengl_snake/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/opengl_snake.dir/shader.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_snake.dir/shader.cpp.o -c /home/gw/Documents/opengl_snake/opengl_snake/shader.cpp

CMakeFiles/opengl_snake.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_snake.dir/shader.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gw/Documents/opengl_snake/opengl_snake/shader.cpp > CMakeFiles/opengl_snake.dir/shader.cpp.i

CMakeFiles/opengl_snake.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_snake.dir/shader.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gw/Documents/opengl_snake/opengl_snake/shader.cpp -o CMakeFiles/opengl_snake.dir/shader.cpp.s

CMakeFiles/opengl_snake.dir/shader.cpp.o.requires:

.PHONY : CMakeFiles/opengl_snake.dir/shader.cpp.o.requires

CMakeFiles/opengl_snake.dir/shader.cpp.o.provides: CMakeFiles/opengl_snake.dir/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/opengl_snake.dir/build.make CMakeFiles/opengl_snake.dir/shader.cpp.o.provides.build
.PHONY : CMakeFiles/opengl_snake.dir/shader.cpp.o.provides

CMakeFiles/opengl_snake.dir/shader.cpp.o.provides.build: CMakeFiles/opengl_snake.dir/shader.cpp.o


# Object files for target opengl_snake
opengl_snake_OBJECTS = \
"CMakeFiles/opengl_snake.dir/canvas.cpp.o" \
"CMakeFiles/opengl_snake.dir/game.cpp.o" \
"CMakeFiles/opengl_snake.dir/main.cpp.o" \
"CMakeFiles/opengl_snake.dir/shader.cpp.o"

# External object files for target opengl_snake
opengl_snake_EXTERNAL_OBJECTS =

opengl_snake: CMakeFiles/opengl_snake.dir/canvas.cpp.o
opengl_snake: CMakeFiles/opengl_snake.dir/game.cpp.o
opengl_snake: CMakeFiles/opengl_snake.dir/main.cpp.o
opengl_snake: CMakeFiles/opengl_snake.dir/shader.cpp.o
opengl_snake: CMakeFiles/opengl_snake.dir/build.make
opengl_snake: /usr/lib/x86_64-linux-gnu/libGL.so
opengl_snake: /usr/lib/x86_64-linux-gnu/libGLEW.so
opengl_snake: CMakeFiles/opengl_snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable opengl_snake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl_snake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl_snake.dir/build: opengl_snake

.PHONY : CMakeFiles/opengl_snake.dir/build

CMakeFiles/opengl_snake.dir/requires: CMakeFiles/opengl_snake.dir/canvas.cpp.o.requires
CMakeFiles/opengl_snake.dir/requires: CMakeFiles/opengl_snake.dir/game.cpp.o.requires
CMakeFiles/opengl_snake.dir/requires: CMakeFiles/opengl_snake.dir/main.cpp.o.requires
CMakeFiles/opengl_snake.dir/requires: CMakeFiles/opengl_snake.dir/shader.cpp.o.requires

.PHONY : CMakeFiles/opengl_snake.dir/requires

CMakeFiles/opengl_snake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl_snake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl_snake.dir/clean

CMakeFiles/opengl_snake.dir/depend:
	cd /home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gw/Documents/opengl_snake/opengl_snake /home/gw/Documents/opengl_snake/opengl_snake /home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default /home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default /home/gw/Documents/opengl_snake/build-opengl_snake-Desktop-Default/CMakeFiles/opengl_snake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl_snake.dir/depend

