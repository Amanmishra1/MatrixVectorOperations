cmake_minimum_required(VERSION 3.10)

project(MatrixVectorOperations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

enable_testing()
add_subdirectory(googletest)

set(HEADERS
  include/Matrix.h
  include/VectorOperations.h
)

set(SOURCES 
  src/Matrix.cpp
  src/VectorOperations.cpp
)

add_library(MatrixVectorOperations ${HEADERS} ${SOURCES})

target_include_directories(MatrixVectorOperations
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(MatrixVectorExecutable main.cpp)

target_link_libraries(MatrixVectorExecutable
MatrixVectorOperations
)

add_subdirectory(test)