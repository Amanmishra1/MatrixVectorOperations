#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <vector>
#include <memory>
#include <algorithm>
#include <cctype>

template <class T>
class VectorOperations
{
private:
    std::vector<T> vect_elements_;
public:   
    VectorOperations<T> operator+(const VectorOperations<T> &vect_elements); 
    VectorOperations<T> operator*(T scalar_value); 
    VectorOperations<T>(const std::vector<T>&);
    VectorOperations<T>();
    void print_vector();
    std::vector<T> get_vector() const;
};

#endif
