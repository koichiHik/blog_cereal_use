
cmake_minimum_required(VERSION 3.8)
project(vlfeat_sample)

# CXX Version.
set_property(GLOBAL
    PROPERTY 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/${ADDITIONAL_CMAKE_MODULE_DIR}")

FIND_PACKAGE(OpenCV)
FIND_PACKAGE(Glog)
FIND_PACKAGE(Gflags)
FIND_PACKAGE(Eigen3)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/extern/lib/include)
link_directories(${CMAKE_SOURCE_DIR}/extern/lib)

############# Test for vlfeat sift detector. #################

set(TARGET "cereal_sample")
set(SRC src/cereal_sample.cc)

# Generate Exe Files
add_executable(${TARGET} ${SRC})
target_link_libraries(${TARGET} ${GFLAGS_LIBRARIES})
target_link_libraries(${TARGET} ${GLOG_LIBRARIES})
target_link_libraries(${TARGET} ${OpenCV_LIBS})

# Macro Definition
target_compile_definitions(${TARGET}
    PRIVATE PRJ_FOLDER_PATH="${CMAKE_SOURCE_DIR}")
