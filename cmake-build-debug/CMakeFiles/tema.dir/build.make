# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/tema.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tema.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tema.dir/flags.make

CMakeFiles/tema.dir/main.cpp.obj: CMakeFiles/tema.dir/flags.make
CMakeFiles/tema.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tema.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tema.dir\main.cpp.obj -c "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\main.cpp"

CMakeFiles/tema.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tema.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\main.cpp" > CMakeFiles\tema.dir\main.cpp.i

CMakeFiles/tema.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tema.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\main.cpp" -o CMakeFiles\tema.dir\main.cpp.s

# Object files for target tema
tema_OBJECTS = \
"CMakeFiles/tema.dir/main.cpp.obj"

# External object files for target tema
tema_EXTERNAL_OBJECTS =

tema.exe: CMakeFiles/tema.dir/main.cpp.obj
tema.exe: CMakeFiles/tema.dir/build.make
tema.exe: CMakeFiles/tema.dir/linklibs.rsp
tema.exe: CMakeFiles/tema.dir/objects1.rsp
tema.exe: CMakeFiles/tema.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tema.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tema.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tema.dir/build: tema.exe

.PHONY : CMakeFiles/tema.dir/build

CMakeFiles/tema.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tema.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tema.dir/clean

CMakeFiles/tema.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema" "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema" "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\cmake-build-debug" "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\cmake-build-debug" "C:\Users\jchiv\OneDrive\Desktop\ANUL 2\SEM1\POO\Laborator-Marius\tema\cmake-build-debug\CMakeFiles\tema.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tema.dir/depend
