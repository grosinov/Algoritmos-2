# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2019.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej4.dir/flags.make

CMakeFiles/ej4.dir/tests/mapa_tests.cpp.o: CMakeFiles/ej4.dir/flags.make
CMakeFiles/ej4.dir/tests/mapa_tests.cpp.o: ../tests/mapa_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej4.dir/tests/mapa_tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej4.dir/tests/mapa_tests.cpp.o -c /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/tests/mapa_tests.cpp

CMakeFiles/ej4.dir/tests/mapa_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej4.dir/tests/mapa_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/tests/mapa_tests.cpp > CMakeFiles/ej4.dir/tests/mapa_tests.cpp.i

CMakeFiles/ej4.dir/tests/mapa_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej4.dir/tests/mapa_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/tests/mapa_tests.cpp -o CMakeFiles/ej4.dir/tests/mapa_tests.cpp.s

# Object files for target ej4
ej4_OBJECTS = \
"CMakeFiles/ej4.dir/tests/mapa_tests.cpp.o"

# External object files for target ej4
ej4_EXTERNAL_OBJECTS =

ej4: CMakeFiles/ej4.dir/tests/mapa_tests.cpp.o
ej4: CMakeFiles/ej4.dir/build.make
ej4: tests/google-test/libgtest.a
ej4: tests/google-test/libgtest_main.a
ej4: tests/google-test/libgtest.a
ej4: CMakeFiles/ej4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej4.dir/build: ej4

.PHONY : CMakeFiles/ej4.dir/build

CMakeFiles/ej4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej4.dir/clean

CMakeFiles/ej4.dir/depend:
	cd /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug /home/grosinov/Rosinov/Algoritmos2/ejerciciosPunteros/alumnos/cmake-build-debug/CMakeFiles/ej4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej4.dir/depend

