cmake_minimum_required (VERSION 3.10)
project(MatrixVector)
set (CMAKE_CXX_FLAGS "-g -std=c++14")


add_executable(MatrixVector src/Matrix.cpp
                src/VectorOperations.cpp
                src/main.cpp
)

target_include_directories(MatrixVector PUBLIC ${PROJECT_SOURCE_DIR}/include)

