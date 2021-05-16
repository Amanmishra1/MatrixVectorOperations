#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "Matrix.h"
#include <VectorOperations.h>

using namespace vect;
using namespace mat;

int main(int argc, char **argv)
{
    //-------------------------------------TEST - 1------------------------------
    //vector data initialization ---INT data (test data 1 -- addtion tests)
    const std::vector<int> vector1{10, 20, 30};
    const std::vector<int> vector2{40, 50, 60};

    //class data initialization
    VectorOperations<int> obj_vect1(vector1);
    VectorOperations<int> obj_vect2(vector2);

    VectorOperations<int> obj_vect3;
    obj_vect3 = obj_vect1 + obj_vect2;
    std::cout << "Vector addition: type int::" << std::endl;
    obj_vect3.print_vector();

    //-------------------------------------TEST - 2------------------------------

    //vector data initialization ---FLOAT data (test data 2 --- addition tests)
    const std::vector<float> vector3{10.6, 20.3, 30.4};
    const std::vector<float> vector4{40.2, 50.2, 60.77};

    //class data initialization
    VectorOperations<float> obj_vect4(vector3);
    VectorOperations<float> obj_vect5(vector4);

    VectorOperations<float> obj_vect6;
    obj_vect6 = obj_vect4 + obj_vect5;
    std::cout << "Vector addition: type float" << std::endl;
    obj_vect6.print_vector();

    //-------------------------------------TEST - 3------------------------------

    //vector data initialization ---int data (test data 3 --- scalar multiplication tests of int)
    const std::vector<int> vector7{10, 20, 30};
    int scalar_value = 5;

    //class data initialization
    VectorOperations<int> obj_vect7(vector7);

    VectorOperations<int> obj_vect8;
    obj_vect8 = obj_vect7 * scalar_value;
    std::cout << "Vector multiplication with scalar value: type int" << std::endl;
    obj_vect8.print_vector();

    //-------------------------------------TEST - 4------------------------------

    //vector data initialization ---int data (test data 4 --- scalar multiplication tests of float)
    const std::vector<float> vector8{10.2, 20.3, 30.5};
    float float_value = 6.4;

    //class data initialization
    VectorOperations<float> obj_vect9(vector8);

    VectorOperations<float> obj_vect10;
    obj_vect10 = obj_vect9 * float_value;
    std::cout << "Vector multiplication with scalar value: type float" << std::endl;
    obj_vect10.print_vector();

    std::cout << std::endl;

    //-------------------------------TEST - 5 matrix addition -----------------------------------

    Matrix<int> matrix1(10, 10, 77); //10 * 10 matrix with value 77
    Matrix<int> matrix2(10, 10, 10); //10 * 10 matrix with value 10

    Matrix<int> matrix3 = matrix1 + matrix2;
    std::cout << "Addition of 2 matrix::" << std::endl;
    matrix3.print_matrix();

    std::cout << std::endl;

    //-------------------------------TEST - 6 scalar matrix addition -----------------------------------

    Matrix<int> matrix4(10, 10, 77); //10 * 10 matrix with value 77

    Matrix<int> matrix5 = matrix4 + 5;
    std::cout << "Matrix addition with scalar value::" << std::endl;
    matrix5.print_matrix();

    std::cout << std::endl;
    //-------------------------------TEST - 7 scalar matrix multiplication -----------------------------------

    Matrix<int> matrix6(10, 10, 77); //10 * 10 matrix with value 77

    Matrix<int> matrix7 = matrix6 * 7;
    std::cout << "Matrix multiplication with scalar value::" << std::endl;
    matrix7.print_matrix();

    //-------------------------------TEST - 8 matrix and vector multiplication -----------------------------------

    Matrix<int> matrix8(4, 3, 10); //4 * 3 matrix with value 10
    const std::vector<int> vector_multiply{10, 20, 30};
    VectorOperations<int> vect_multiply_obj(vector_multiply);

    std::vector<int> result_multiply(std::move(matrix8 * vect_multiply_obj));

    std::cout << "Matrix and vector multiplication::" << std::endl;
    for (const auto &i : result_multiply)
        std::cout << i << std::endl;
}
