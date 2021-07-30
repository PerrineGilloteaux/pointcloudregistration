cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


set(NAME register_pointclouds)

project(${NAME})

set(IPOPT_INCLUDE_DIR ~/ipopt/include/coin/)
set(IPOPT_LIBRARY_DIR ~/ipopt/lib)
set(PCL_LIBRARIES_DIRS C:/dev/vcpkg/packages/pcl_x86-windows/lib)


link_directories(${PCL_LIBRARY_DIRS} ${IPOPT_LIBRARY_DIR})

set(SRC src/cpr_main.cpp src/cpr_debugprint.cpp src/cpr_processedpointcloud.cpp src/cpr_clustering.cpp src/cpr_connectedcomponents.cpp src/cpr_features.cpp src/cpr_matrices.cpp src/cpr_graphmatching.cpp src/cpr_graphmatching_frankwolfe.cpp src/cpr_graphmatching_nonlin.cpp src/cpr_ransac.cpp src/cpr_visualisation.cpp src/cpr_params.cpp src/cpr_loadfiles.cpp)

include_directories("includes")

add_executable (${NAME} ${SRC})
target_link_libraries (${NAME} PUBLIC ${PCL_LIBRARIES})
target_link_libraries (${NAME} PUBLIC glpk)
target_link_libraries (${NAME} PUBLIC ipopt)
target_compile_options(${NAME} PRIVATE -Wall -Wextra -Wfloat-conversion -Wfloat-equal)
