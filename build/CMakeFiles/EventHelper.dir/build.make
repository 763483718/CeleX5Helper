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
CMAKE_SOURCE_DIR = /home/tuto/code/CeleX5Helper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tuto/code/CeleX5Helper/build

# Include any dependencies generated for this target.
include CMakeFiles/EventHelper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EventHelper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EventHelper.dir/flags.make

CMakeFiles/EventHelper.dir/src/main.cpp.o: CMakeFiles/EventHelper.dir/flags.make
CMakeFiles/EventHelper.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tuto/code/CeleX5Helper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EventHelper.dir/src/main.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventHelper.dir/src/main.cpp.o -c /home/tuto/code/CeleX5Helper/src/main.cpp

CMakeFiles/EventHelper.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventHelper.dir/src/main.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tuto/code/CeleX5Helper/src/main.cpp > CMakeFiles/EventHelper.dir/src/main.cpp.i

CMakeFiles/EventHelper.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventHelper.dir/src/main.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tuto/code/CeleX5Helper/src/main.cpp -o CMakeFiles/EventHelper.dir/src/main.cpp.s

CMakeFiles/EventHelper.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/EventHelper.dir/src/main.cpp.o.requires

CMakeFiles/EventHelper.dir/src/main.cpp.o.provides: CMakeFiles/EventHelper.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/EventHelper.dir/build.make CMakeFiles/EventHelper.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/EventHelper.dir/src/main.cpp.o.provides

CMakeFiles/EventHelper.dir/src/main.cpp.o.provides.build: CMakeFiles/EventHelper.dir/src/main.cpp.o


CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o: CMakeFiles/EventHelper.dir/flags.make
CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o: ../src/RecordEventData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tuto/code/CeleX5Helper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o -c /home/tuto/code/CeleX5Helper/src/RecordEventData.cpp

CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tuto/code/CeleX5Helper/src/RecordEventData.cpp > CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.i

CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tuto/code/CeleX5Helper/src/RecordEventData.cpp -o CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.s

CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.requires:

.PHONY : CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.requires

CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.provides: CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.requires
	$(MAKE) -f CMakeFiles/EventHelper.dir/build.make CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.provides.build
.PHONY : CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.provides

CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.provides.build: CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o


CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o: CMakeFiles/EventHelper.dir/flags.make
CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o: ../src/fileHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tuto/code/CeleX5Helper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o -c /home/tuto/code/CeleX5Helper/src/fileHelper.cpp

CMakeFiles/EventHelper.dir/src/fileHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventHelper.dir/src/fileHelper.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tuto/code/CeleX5Helper/src/fileHelper.cpp > CMakeFiles/EventHelper.dir/src/fileHelper.cpp.i

CMakeFiles/EventHelper.dir/src/fileHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventHelper.dir/src/fileHelper.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tuto/code/CeleX5Helper/src/fileHelper.cpp -o CMakeFiles/EventHelper.dir/src/fileHelper.cpp.s

CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.requires:

.PHONY : CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.requires

CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.provides: CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.requires
	$(MAKE) -f CMakeFiles/EventHelper.dir/build.make CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.provides.build
.PHONY : CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.provides

CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.provides.build: CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o


# Object files for target EventHelper
EventHelper_OBJECTS = \
"CMakeFiles/EventHelper.dir/src/main.cpp.o" \
"CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o" \
"CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o"

# External object files for target EventHelper
EventHelper_EXTERNAL_OBJECTS =

EventHelper: CMakeFiles/EventHelper.dir/src/main.cpp.o
EventHelper: CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o
EventHelper: CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o
EventHelper: CMakeFiles/EventHelper.dir/build.make
EventHelper: /usr/local/lib/libopencv_dnn.so.3.3.0
EventHelper: /usr/local/lib/libopencv_ml.so.3.3.0
EventHelper: /usr/local/lib/libopencv_objdetect.so.3.3.0
EventHelper: /usr/local/lib/libopencv_shape.so.3.3.0
EventHelper: /usr/local/lib/libopencv_stitching.so.3.3.0
EventHelper: /usr/local/lib/libopencv_superres.so.3.3.0
EventHelper: /usr/local/lib/libopencv_videostab.so.3.3.0
EventHelper: /usr/local/lib/libopencv_viz.so.3.3.0
EventHelper: /usr/local/lib/libopencv_calib3d.so.3.3.0
EventHelper: /usr/local/lib/libopencv_features2d.so.3.3.0
EventHelper: /usr/local/lib/libopencv_flann.so.3.3.0
EventHelper: /usr/local/lib/libopencv_highgui.so.3.3.0
EventHelper: /usr/local/lib/libopencv_photo.so.3.3.0
EventHelper: /usr/local/lib/libopencv_video.so.3.3.0
EventHelper: /usr/local/lib/libopencv_videoio.so.3.3.0
EventHelper: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
EventHelper: /usr/local/lib/libopencv_imgproc.so.3.3.0
EventHelper: /usr/local/lib/libopencv_core.so.3.3.0
EventHelper: CMakeFiles/EventHelper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tuto/code/CeleX5Helper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable EventHelper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EventHelper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EventHelper.dir/build: EventHelper

.PHONY : CMakeFiles/EventHelper.dir/build

CMakeFiles/EventHelper.dir/requires: CMakeFiles/EventHelper.dir/src/main.cpp.o.requires
CMakeFiles/EventHelper.dir/requires: CMakeFiles/EventHelper.dir/src/RecordEventData.cpp.o.requires
CMakeFiles/EventHelper.dir/requires: CMakeFiles/EventHelper.dir/src/fileHelper.cpp.o.requires

.PHONY : CMakeFiles/EventHelper.dir/requires

CMakeFiles/EventHelper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EventHelper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EventHelper.dir/clean

CMakeFiles/EventHelper.dir/depend:
	cd /home/tuto/code/CeleX5Helper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tuto/code/CeleX5Helper /home/tuto/code/CeleX5Helper /home/tuto/code/CeleX5Helper/build /home/tuto/code/CeleX5Helper/build /home/tuto/code/CeleX5Helper/build/CMakeFiles/EventHelper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EventHelper.dir/depend
