#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <VectorOperations.h>

using namespace vect;

namespace mat
{
  template <class T>
  class Matrix
  {
  private:
    std::vector<std::vector<T>> matrix_;
    int rows_;
    int cols_;

  public:
    Matrix(int _rows, int _cols, const T &);
    Matrix(const Matrix<T> &);

    Matrix<T> operator+(const Matrix<T> &);
    Matrix<T> operator*(const Matrix<T> &);

    Matrix<T> operator+(const T &);
    Matrix<T> operator*(const T &);

    std::vector<T> operator*(const VectorOperations<T> &);

    // Access the individual elements
    T &operator()(const int &row, const int &col);
    const T &operator()(const int &row, const int &col) const;

    // Access the row and column sizes
    int get_rows() const;
    int get_cols() const;

    void print_matrix();
  };
} //end of namespace
#endif
