# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/bin/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/march/CLionProjects/Sandbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/march/CLionProjects/Sandbox/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sandbox.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sandbox.dir/flags.make

CMakeFiles/Sandbox.dir/main.c.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/march/CLionProjects/Sandbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Sandbox.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Sandbox.dir/main.c.o   -c /home/march/CLionProjects/Sandbox/main.c

CMakeFiles/Sandbox.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sandbox.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/march/CLionProjects/Sandbox/main.c > CMakeFiles/Sandbox.dir/main.c.i

CMakeFiles/Sandbox.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sandbox.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/march/CLionProjects/Sandbox/main.c -o CMakeFiles/Sandbox.dir/main.c.s

CMakeFiles/Sandbox.dir/main.c.o.requires:

.PHONY : CMakeFiles/Sandbox.dir/main.c.o.requires

CMakeFiles/Sandbox.dir/main.c.o.provides: CMakeFiles/Sandbox.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Sandbox.dir/build.make CMakeFiles/Sandbox.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Sandbox.dir/main.c.o.provides

CMakeFiles/Sandbox.dir/main.c.o.provides.build: CMakeFiles/Sandbox.dir/main.c.o


# Object files for target Sandbox
Sandbox_OBJECTS = \
"CMakeFiles/Sandbox.dir/main.c.o"

# External object files for target Sandbox
Sandbox_EXTERNAL_OBJECTS =

Sandbox: CMakeFiles/Sandbox.dir/main.c.o
Sandbox: CMakeFiles/Sandbox.dir/build.make
Sandbox: CMakeFiles/Sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/march/CLionProjects/Sandbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Sandbox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sandbox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sandbox.dir/build: Sandbox

.PHONY : CMakeFiles/Sandbox.dir/build

CMakeFiles/Sandbox.dir/requires: CMakeFiles/Sandbox.dir/main.c.o.requires

.PHONY : CMakeFiles/Sandbox.dir/requires

CMakeFiles/Sandbox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sandbox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sandbox.dir/clean

CMakeFiles/Sandbox.dir/depend:
	cd /home/march/CLionProjects/Sandbox/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/march/CLionProjects/Sandbox /home/march/CLionProjects/Sandbox /home/march/CLionProjects/Sandbox/cmake-build-debug /home/march/CLionProjects/Sandbox/cmake-build-debug /home/march/CLionProjects/Sandbox/cmake-build-debug/CMakeFiles/Sandbox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sandbox.dir/depend

