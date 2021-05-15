#include <iostream>
#include "VectorOperations.h"

using namespace vect;

template <class T>
VectorOperations<T>::VectorOperations()
{
}

template <class T>
std::vector<T> VectorOperations<T>::get_vector() const
{
    return vect_elements_;
}

template <class T>
VectorOperations<T>::VectorOperations(const std::vector<T> &vector_data)
{
    std::copy(vector_data.begin(), vector_data.end(), std::back_inserter(vect_elements_));
}

template <class T>
VectorOperations<T> VectorOperations<T>::operator+(const VectorOperations<T> &vect_obj2)
{
    VectorOperations<T> vect_addition;

    if (this->vect_elements_.size() != vect_obj2.vect_elements_.size())
        throw std::length_error("vectors must be same size to add");

    //resize the vector to match size of input data
    vect_addition.vect_elements_.resize(vect_obj2.vect_elements_.size());

    std::transform(vect_obj2.vect_elements_.begin(), vect_obj2.vect_elements_.end(),
                   this->vect_elements_.begin(), vect_addition.vect_elements_.begin(), std::plus<T>());

    return vect_addition;
}

template <class T>
VectorOperations<T> VectorOperations<T>::operator*(T scalar_value)
{
    VectorOperations<T> vect_multiplication;

    //resize the vector to match size of input data
    vect_multiplication.vect_elements_.resize(this->vect_elements_.size());

    std::transform(this->vect_elements_.begin(), this->vect_elements_.end(),
                   vect_multiplication.vect_elements_.begin(), [scalar_value](T value) { return value * scalar_value; });

    return vect_multiplication;
}

template <class T>
void VectorOperations<T>::print_vector()
{
    for (const auto &i : vect_elements_)
        std::cout << i << std::endl;
}

//Explicit template instantiation
template class VectorOperations<int>;
template class VectorOperations<double>;
template class VectorOperations<float>;