#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <vector>
#include <algorithm>

namespace vect
{
    template <class T>
    class VectorOperations final
    {
    private:
        std::vector<T> vect_elements_;

    public:
        VectorOperations<T> &operator=(VectorOperations<T> const &other) = default;
        VectorOperations<T>(VectorOperations<T> &&other) = default;
        VectorOperations<T> &operator=(VectorOperations<T> &&other) = default;
        ~VectorOperations<T>() = default;

        VectorOperations<T> operator+(const VectorOperations<T> &vect_elements);
        VectorOperations<T> operator*(T scalar_value);
        VectorOperations<T>(const std::vector<T> &);
        VectorOperations<T>();
        void print_vector();
        std::vector<T> get_vector() const;
    };
} // end of namespace
#endif
