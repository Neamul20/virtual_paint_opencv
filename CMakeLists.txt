cmake_minimum_required(VERSION 3.22)

set(executable "VirtualPaint")
project(
    CppProjectTemplate 
    VERSION 1.0.0
    LANGUAGES CXX  # Use just CXX if you're only using C++
)

find_package(OpenCV REQUIRED)

# Define source files (no need to list headers here)
set(SRCS
    src/main.cpp
    src/VirtualPaint.cpp
)

# Include directories (now with better organization)
set(INCLUDES
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src  # Full path to src directory
)

add_executable(${executable} ${SRCS})

target_link_libraries(${executable} PRIVATE ${OpenCV_LIBS})
target_include_directories(${executable} PRIVATE ${INCLUDES})