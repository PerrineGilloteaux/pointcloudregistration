# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/stephan/huang_registration

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stephan/huang_registration

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/stephan/huang_registration/CMakeFiles /home/stephan/huang_registration/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/stephan/huang_registration/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named register_pointclouds

# Build rule for target.
register_pointclouds: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 register_pointclouds
.PHONY : register_pointclouds

# fast build rule for target.
register_pointclouds/fast:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/build
.PHONY : register_pointclouds/fast

src/cpr_clustering.o: src/cpr_clustering.cpp.o

.PHONY : src/cpr_clustering.o

# target to build an object file
src/cpr_clustering.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_clustering.cpp.o
.PHONY : src/cpr_clustering.cpp.o

src/cpr_clustering.i: src/cpr_clustering.cpp.i

.PHONY : src/cpr_clustering.i

# target to preprocess a source file
src/cpr_clustering.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_clustering.cpp.i
.PHONY : src/cpr_clustering.cpp.i

src/cpr_clustering.s: src/cpr_clustering.cpp.s

.PHONY : src/cpr_clustering.s

# target to generate assembly for a file
src/cpr_clustering.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_clustering.cpp.s
.PHONY : src/cpr_clustering.cpp.s

src/cpr_connectedcomponents.o: src/cpr_connectedcomponents.cpp.o

.PHONY : src/cpr_connectedcomponents.o

# target to build an object file
src/cpr_connectedcomponents.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_connectedcomponents.cpp.o
.PHONY : src/cpr_connectedcomponents.cpp.o

src/cpr_connectedcomponents.i: src/cpr_connectedcomponents.cpp.i

.PHONY : src/cpr_connectedcomponents.i

# target to preprocess a source file
src/cpr_connectedcomponents.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_connectedcomponents.cpp.i
.PHONY : src/cpr_connectedcomponents.cpp.i

src/cpr_connectedcomponents.s: src/cpr_connectedcomponents.cpp.s

.PHONY : src/cpr_connectedcomponents.s

# target to generate assembly for a file
src/cpr_connectedcomponents.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_connectedcomponents.cpp.s
.PHONY : src/cpr_connectedcomponents.cpp.s

src/cpr_debugprint.o: src/cpr_debugprint.cpp.o

.PHONY : src/cpr_debugprint.o

# target to build an object file
src/cpr_debugprint.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_debugprint.cpp.o
.PHONY : src/cpr_debugprint.cpp.o

src/cpr_debugprint.i: src/cpr_debugprint.cpp.i

.PHONY : src/cpr_debugprint.i

# target to preprocess a source file
src/cpr_debugprint.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_debugprint.cpp.i
.PHONY : src/cpr_debugprint.cpp.i

src/cpr_debugprint.s: src/cpr_debugprint.cpp.s

.PHONY : src/cpr_debugprint.s

# target to generate assembly for a file
src/cpr_debugprint.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_debugprint.cpp.s
.PHONY : src/cpr_debugprint.cpp.s

src/cpr_features.o: src/cpr_features.cpp.o

.PHONY : src/cpr_features.o

# target to build an object file
src/cpr_features.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_features.cpp.o
.PHONY : src/cpr_features.cpp.o

src/cpr_features.i: src/cpr_features.cpp.i

.PHONY : src/cpr_features.i

# target to preprocess a source file
src/cpr_features.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_features.cpp.i
.PHONY : src/cpr_features.cpp.i

src/cpr_features.s: src/cpr_features.cpp.s

.PHONY : src/cpr_features.s

# target to generate assembly for a file
src/cpr_features.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_features.cpp.s
.PHONY : src/cpr_features.cpp.s

src/cpr_graphmatching.o: src/cpr_graphmatching.cpp.o

.PHONY : src/cpr_graphmatching.o

# target to build an object file
src/cpr_graphmatching.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching.cpp.o
.PHONY : src/cpr_graphmatching.cpp.o

src/cpr_graphmatching.i: src/cpr_graphmatching.cpp.i

.PHONY : src/cpr_graphmatching.i

# target to preprocess a source file
src/cpr_graphmatching.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching.cpp.i
.PHONY : src/cpr_graphmatching.cpp.i

src/cpr_graphmatching.s: src/cpr_graphmatching.cpp.s

.PHONY : src/cpr_graphmatching.s

# target to generate assembly for a file
src/cpr_graphmatching.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching.cpp.s
.PHONY : src/cpr_graphmatching.cpp.s

src/cpr_graphmatching_cgal.o: src/cpr_graphmatching_cgal.cpp.o

.PHONY : src/cpr_graphmatching_cgal.o

# target to build an object file
src/cpr_graphmatching_cgal.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching_cgal.cpp.o
.PHONY : src/cpr_graphmatching_cgal.cpp.o

src/cpr_graphmatching_cgal.i: src/cpr_graphmatching_cgal.cpp.i

.PHONY : src/cpr_graphmatching_cgal.i

# target to preprocess a source file
src/cpr_graphmatching_cgal.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching_cgal.cpp.i
.PHONY : src/cpr_graphmatching_cgal.cpp.i

src/cpr_graphmatching_cgal.s: src/cpr_graphmatching_cgal.cpp.s

.PHONY : src/cpr_graphmatching_cgal.s

# target to generate assembly for a file
src/cpr_graphmatching_cgal.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching_cgal.cpp.s
.PHONY : src/cpr_graphmatching_cgal.cpp.s

src/cpr_graphmatching_path.o: src/cpr_graphmatching_path.cpp.o

.PHONY : src/cpr_graphmatching_path.o

# target to build an object file
src/cpr_graphmatching_path.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching_path.cpp.o
.PHONY : src/cpr_graphmatching_path.cpp.o

src/cpr_graphmatching_path.i: src/cpr_graphmatching_path.cpp.i

.PHONY : src/cpr_graphmatching_path.i

# target to preprocess a source file
src/cpr_graphmatching_path.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching_path.cpp.i
.PHONY : src/cpr_graphmatching_path.cpp.i

src/cpr_graphmatching_path.s: src/cpr_graphmatching_path.cpp.s

.PHONY : src/cpr_graphmatching_path.s

# target to generate assembly for a file
src/cpr_graphmatching_path.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_graphmatching_path.cpp.s
.PHONY : src/cpr_graphmatching_path.cpp.s

src/cpr_loadfiles.o: src/cpr_loadfiles.cpp.o

.PHONY : src/cpr_loadfiles.o

# target to build an object file
src/cpr_loadfiles.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_loadfiles.cpp.o
.PHONY : src/cpr_loadfiles.cpp.o

src/cpr_loadfiles.i: src/cpr_loadfiles.cpp.i

.PHONY : src/cpr_loadfiles.i

# target to preprocess a source file
src/cpr_loadfiles.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_loadfiles.cpp.i
.PHONY : src/cpr_loadfiles.cpp.i

src/cpr_loadfiles.s: src/cpr_loadfiles.cpp.s

.PHONY : src/cpr_loadfiles.s

# target to generate assembly for a file
src/cpr_loadfiles.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_loadfiles.cpp.s
.PHONY : src/cpr_loadfiles.cpp.s

src/cpr_main.o: src/cpr_main.cpp.o

.PHONY : src/cpr_main.o

# target to build an object file
src/cpr_main.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_main.cpp.o
.PHONY : src/cpr_main.cpp.o

src/cpr_main.i: src/cpr_main.cpp.i

.PHONY : src/cpr_main.i

# target to preprocess a source file
src/cpr_main.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_main.cpp.i
.PHONY : src/cpr_main.cpp.i

src/cpr_main.s: src/cpr_main.cpp.s

.PHONY : src/cpr_main.s

# target to generate assembly for a file
src/cpr_main.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_main.cpp.s
.PHONY : src/cpr_main.cpp.s

src/cpr_matrices.o: src/cpr_matrices.cpp.o

.PHONY : src/cpr_matrices.o

# target to build an object file
src/cpr_matrices.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_matrices.cpp.o
.PHONY : src/cpr_matrices.cpp.o

src/cpr_matrices.i: src/cpr_matrices.cpp.i

.PHONY : src/cpr_matrices.i

# target to preprocess a source file
src/cpr_matrices.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_matrices.cpp.i
.PHONY : src/cpr_matrices.cpp.i

src/cpr_matrices.s: src/cpr_matrices.cpp.s

.PHONY : src/cpr_matrices.s

# target to generate assembly for a file
src/cpr_matrices.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_matrices.cpp.s
.PHONY : src/cpr_matrices.cpp.s

src/cpr_params.o: src/cpr_params.cpp.o

.PHONY : src/cpr_params.o

# target to build an object file
src/cpr_params.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_params.cpp.o
.PHONY : src/cpr_params.cpp.o

src/cpr_params.i: src/cpr_params.cpp.i

.PHONY : src/cpr_params.i

# target to preprocess a source file
src/cpr_params.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_params.cpp.i
.PHONY : src/cpr_params.cpp.i

src/cpr_params.s: src/cpr_params.cpp.s

.PHONY : src/cpr_params.s

# target to generate assembly for a file
src/cpr_params.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_params.cpp.s
.PHONY : src/cpr_params.cpp.s

src/cpr_processedpointcloud.o: src/cpr_processedpointcloud.cpp.o

.PHONY : src/cpr_processedpointcloud.o

# target to build an object file
src/cpr_processedpointcloud.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_processedpointcloud.cpp.o
.PHONY : src/cpr_processedpointcloud.cpp.o

src/cpr_processedpointcloud.i: src/cpr_processedpointcloud.cpp.i

.PHONY : src/cpr_processedpointcloud.i

# target to preprocess a source file
src/cpr_processedpointcloud.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_processedpointcloud.cpp.i
.PHONY : src/cpr_processedpointcloud.cpp.i

src/cpr_processedpointcloud.s: src/cpr_processedpointcloud.cpp.s

.PHONY : src/cpr_processedpointcloud.s

# target to generate assembly for a file
src/cpr_processedpointcloud.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_processedpointcloud.cpp.s
.PHONY : src/cpr_processedpointcloud.cpp.s

src/cpr_visualisation.o: src/cpr_visualisation.cpp.o

.PHONY : src/cpr_visualisation.o

# target to build an object file
src/cpr_visualisation.cpp.o:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_visualisation.cpp.o
.PHONY : src/cpr_visualisation.cpp.o

src/cpr_visualisation.i: src/cpr_visualisation.cpp.i

.PHONY : src/cpr_visualisation.i

# target to preprocess a source file
src/cpr_visualisation.cpp.i:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_visualisation.cpp.i
.PHONY : src/cpr_visualisation.cpp.i

src/cpr_visualisation.s: src/cpr_visualisation.cpp.s

.PHONY : src/cpr_visualisation.s

# target to generate assembly for a file
src/cpr_visualisation.cpp.s:
	$(MAKE) -f CMakeFiles/register_pointclouds.dir/build.make CMakeFiles/register_pointclouds.dir/src/cpr_visualisation.cpp.s
.PHONY : src/cpr_visualisation.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... register_pointclouds"
	@echo "... edit_cache"
	@echo "... src/cpr_clustering.o"
	@echo "... src/cpr_clustering.i"
	@echo "... src/cpr_clustering.s"
	@echo "... src/cpr_connectedcomponents.o"
	@echo "... src/cpr_connectedcomponents.i"
	@echo "... src/cpr_connectedcomponents.s"
	@echo "... src/cpr_debugprint.o"
	@echo "... src/cpr_debugprint.i"
	@echo "... src/cpr_debugprint.s"
	@echo "... src/cpr_features.o"
	@echo "... src/cpr_features.i"
	@echo "... src/cpr_features.s"
	@echo "... src/cpr_graphmatching.o"
	@echo "... src/cpr_graphmatching.i"
	@echo "... src/cpr_graphmatching.s"
	@echo "... src/cpr_graphmatching_cgal.o"
	@echo "... src/cpr_graphmatching_cgal.i"
	@echo "... src/cpr_graphmatching_cgal.s"
	@echo "... src/cpr_graphmatching_path.o"
	@echo "... src/cpr_graphmatching_path.i"
	@echo "... src/cpr_graphmatching_path.s"
	@echo "... src/cpr_loadfiles.o"
	@echo "... src/cpr_loadfiles.i"
	@echo "... src/cpr_loadfiles.s"
	@echo "... src/cpr_main.o"
	@echo "... src/cpr_main.i"
	@echo "... src/cpr_main.s"
	@echo "... src/cpr_matrices.o"
	@echo "... src/cpr_matrices.i"
	@echo "... src/cpr_matrices.s"
	@echo "... src/cpr_params.o"
	@echo "... src/cpr_params.i"
	@echo "... src/cpr_params.s"
	@echo "... src/cpr_processedpointcloud.o"
	@echo "... src/cpr_processedpointcloud.i"
	@echo "... src/cpr_processedpointcloud.s"
	@echo "... src/cpr_visualisation.o"
	@echo "... src/cpr_visualisation.i"
	@echo "... src/cpr_visualisation.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

