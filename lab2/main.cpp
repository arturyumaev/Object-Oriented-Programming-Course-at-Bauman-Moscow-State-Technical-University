#include "stdafx.h"

template <typename T>
class ndarray
{
public:
    ndarray()
    {

    }

    ndarray(UI dim, UI* shape, const T& val = T())
    {
        // Setting args
        this->_dim = dim;
        this->_shape = shape; // We do not check shapes array besause of the <unsigned int> type

        create_ndarray(dim, shape, val);
    }

    ~ndarray() // Destructor
    {
        if (this->_ndarray != nullptr)
        {
            delete[] this->_ndarray;
        }
    }

    template <typename N>
    T* mult_by_num(N num)
    {
        T* new_ndarray = new T[this->_ndarray_size];

        for (int i = 0; i < this->_ndarray_size; i++)
        {
            new_ndarray[i] = this->_ndarray[i] * num;
        }

        return new_ndarray;
    }

private:
    /* Members */
    T* _ndarray;
    UI _dim;
    UI* _shape; // shape, e.g. shape=[5, 3] which means 2x2 (len([5,3] == 2)) matrix with 5 rows and 3 columns
    UI _ndarray_size; // Equals S = mult(from i to max(shape) : shape[i])

    /* Member functions */
    T* alloc_memory_filled_by_value(UI dim, UI* shape, const T& val)
    {
        UI mult_shape = this->get_multiplicated_shape(dim, shape);

        this->_ndarray_size = mult_shape;

        T* ndarray = new T[mult_shape];

        for (UI i = 0; i < mult_shape; i++)
        {
            ndarray[i] = val;
        }

        return ndarray; // Return allocated memory
    }

    // Calculate multiplicated shape
    UI get_multiplicated_shape(UI dim, UI* shape)
    {
        int shape_mult = 1;

        for (UI i = 0; i < dim; i++)
        {
            shape_mult *= shape[i];
        }

        return shape_mult; // ndarray members count
    }

    // Initial ndarray
    void create_ndarray(UI dim, UI* shape, const T& val)
    {
        this->_ndarray = this->alloc_memory_filled_by_value(dim, shape, val);
    }
};

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest)
{  
    cout << first << ", ";  
    print(rest...); // recursive call using pack expansion syntax  
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    UI shape[2] = {3, 3};

    ndarray<int> a(2, shape, 4);

    //print(100, 200, 300);

    return 0;
}

/*
    ND access
    reference operator() (const unsigned *subs) const
    {
        return data()[sub2ind<N>(subs, m_size, m_strides)];
    }

    reference operator()(std::initializer_list<unsigned> subs) const
    {
        #ifdef ND_ARRAY_SAFE_ACCESS
            if (subs.size() != N) 
                throw std::length_error("Invalid coordinates length.");
        #endif
        
        return data()[ sub2ind<N>(subs.begin(), m_size, m_strides) ];
    }

    // Coordinates access
    reference operator() (unsigned i, ...) const
    { 
        va_list vl; va_start(vl,i); 
        return data()[i + sub2ind<N>(vl, m_size, m_strides)];
    }
*/