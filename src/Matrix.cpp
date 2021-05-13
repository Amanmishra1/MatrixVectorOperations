#include <iostream>
#include "Matrix.h"

template<class T>
inline Matrix<T>::Matrix(int rows, int cols, const T& value) 
{
  matrix_.resize(rows);
  for (unsigned i=0; i < matrix_.size(); i++) 
  {
    matrix_[i].resize(cols, value);
  }
  rows_ = rows;
  cols_ = cols;
}

template<class T>
inline Matrix<T>::Matrix(const Matrix<T>& matrix_obj) 
{
    matrix_ = matrix_obj.matrix_;
    rows_   = matrix_obj.get_rows();
    cols_   = matrix_obj.get_cols();
}
                                                                                                                 
template<class T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& matrix_obj) 
{
    Matrix result(rows_, cols_, 0);

    for (int i=0; i<rows_; i++) 
    {
        for (int j=0; j<cols_; j++) 
        {
            result(i,j) = this->matrix_[i][j] + matrix_obj(i,j);
        }
    }
    
  return result;
}

// Scalar addition of matrix                                                                                                                                                    
template<class T>
inline Matrix<T> Matrix<T>::operator+(const T& scalar_value) 
{
  Matrix result(rows_, cols_, 0);

  for (int i=0; i<rows_; i++) 
  {
    for (int j=0; j<cols_; j++) 
    {
      result(i,j) = this->matrix_[i][j] + scalar_value;
    }
  }
  
  return result;
}


//scalar multiplication of matrix                                                                                                                                              
template<class T>
inline Matrix<T> Matrix<T>::operator*(const T& scalar_value) 
{
  Matrix result(rows_, cols_, 0);

  for (int i=0; i<rows_; i++) 
  {
    for (int j=0; j<cols_; j++) 
    {
      result(i,j) = this->matrix_[i][j] * scalar_value;
    }
  }
  
  return result;
}

// Multiply a matrix with a vector                                                                                                                                            
template<class T>
inline std::vector<T> Matrix<T>::operator*(const VectorOperations<T>& vect_obj) 
{
  std::vector<T> vect_elements(std::move(vect_obj.get_vector()));
    
   if ( vect_elements.size() != static_cast<std::vector<int>::size_type>(this->cols_) )
        throw std::length_error("matrix colums and vectors row do not match");
   
     
  std::vector<T> result(this->rows_, 0);
  
  for (int i=0; i< rows_; i++) 
  {
    for (int j=0; j< cols_; j++) 
    {
      result[i] = result[i] + this->matrix_[i][j] * vect_elements[j];
    }
  }
  
  return result;
}

// Access the individual elements                                                                                                                                             
template<class T>
inline T& Matrix<T>::operator()(const int& row, const int& col) 
{
  return this->matrix_[row][col];
}

// Access the individual elements (const)                                                                                                                                     
template<class T>
inline const T& Matrix<T>::operator()(const int& row, const int& col) const 
{
  return this->matrix_[row][col];
}

// Get the number of rows of the matrix                                                                                                                                       
template<class T>
inline int Matrix<T>::get_rows() const 
{
  return this->rows_;
}

// Get the number of columns of the matrix                                                                                                                                    
template<class T>
inline int Matrix<T>::get_cols() const 
{
  return this->cols_;
}

template<class T>
inline void Matrix<T>::print_matrix()
{
  for (int i=0; i<this->get_rows(); i++) 
  {
    for (int j=0; j<this->get_cols(); j++) 
    {
      std::cout << matrix_[i][j] << ", ";
    }
    std::cout << std::endl;
  }
}

//Explicit template instantiation
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;