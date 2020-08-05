cmake_minimum_required (VERSION 2.6)

project (trajectory_calculator)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_executable(trajectory_calculator 
main.cpp 
myMathDll.cpp
PhysObject.cpp
Position.cpp
TrajectoryCalculator.cpp
)

target_link_libraries (trajectory_calculator ${CMAKE_THREAD_LIBS_INIT})
