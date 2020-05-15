cmake_minimum_required(VERSION 3.8)
project(convex_hull)

set(CMAKE_CXX_STANDARD 14)
find_package( Eigen3  REQUIRED )
include_directories(${EIGEN3_INCLUDE_DIR}) 
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/convex_hull ${PROJECT_SOURCE_DIR}/line_segments_intersect ${PROJECT_SOURCE_DIR}/common)

add_executable(linesegments_intersect main.cc line_segments_intersect/line_segments_intersect.cc convex_hull/convex_hull.cc)
target_link_libraries(linesegments_intersect boost_system boost_filesystem boost_iostreams ${Eigen3_LIBRARIES})

