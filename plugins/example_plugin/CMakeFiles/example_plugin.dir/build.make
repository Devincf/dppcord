# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/lumi/code/cpp/d++cord/plugins/example_plugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lumi/code/cpp/d++cord/plugins/example_plugin

# Include any dependencies generated for this target.
include CMakeFiles/example_plugin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_plugin.dir/flags.make

CMakeFiles/example_plugin.dir/plugin.cpp.o: CMakeFiles/example_plugin.dir/flags.make
CMakeFiles/example_plugin.dir/plugin.cpp.o: plugin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lumi/code/cpp/d++cord/plugins/example_plugin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_plugin.dir/plugin.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_plugin.dir/plugin.cpp.o -c /home/lumi/code/cpp/d++cord/plugins/example_plugin/plugin.cpp

CMakeFiles/example_plugin.dir/plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_plugin.dir/plugin.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lumi/code/cpp/d++cord/plugins/example_plugin/plugin.cpp > CMakeFiles/example_plugin.dir/plugin.cpp.i

CMakeFiles/example_plugin.dir/plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_plugin.dir/plugin.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lumi/code/cpp/d++cord/plugins/example_plugin/plugin.cpp -o CMakeFiles/example_plugin.dir/plugin.cpp.s

# Object files for target example_plugin
example_plugin_OBJECTS = \
"CMakeFiles/example_plugin.dir/plugin.cpp.o"

# External object files for target example_plugin
example_plugin_EXTERNAL_OBJECTS =

libexample_plugin.so.1.0.0: CMakeFiles/example_plugin.dir/plugin.cpp.o
libexample_plugin.so.1.0.0: CMakeFiles/example_plugin.dir/build.make
libexample_plugin.so.1.0.0: CMakeFiles/example_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lumi/code/cpp/d++cord/plugins/example_plugin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libexample_plugin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_plugin.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libexample_plugin.so.1.0.0 libexample_plugin.so.1 libexample_plugin.so

libexample_plugin.so.1: libexample_plugin.so.1.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate libexample_plugin.so.1

libexample_plugin.so: libexample_plugin.so.1.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate libexample_plugin.so

# Rule to build all files generated by this target.
CMakeFiles/example_plugin.dir/build: libexample_plugin.so

.PHONY : CMakeFiles/example_plugin.dir/build

CMakeFiles/example_plugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_plugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_plugin.dir/clean

CMakeFiles/example_plugin.dir/depend:
	cd /home/lumi/code/cpp/d++cord/plugins/example_plugin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lumi/code/cpp/d++cord/plugins/example_plugin /home/lumi/code/cpp/d++cord/plugins/example_plugin /home/lumi/code/cpp/d++cord/plugins/example_plugin /home/lumi/code/cpp/d++cord/plugins/example_plugin /home/lumi/code/cpp/d++cord/plugins/example_plugin/CMakeFiles/example_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_plugin.dir/depend
