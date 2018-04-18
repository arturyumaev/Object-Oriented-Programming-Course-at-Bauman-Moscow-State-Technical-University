#include "stdafx.h"

template <typename T> class MyVector
{
    private:
        T* _array;
        int _arraySize;
    public:
        MyVector()
        {
            this->_arraySize = 0;
            this->_array = new T[this->_arraySize];
        }

        // Vector with size <size>, filled by <defaultValue>
        MyVector(__SIZE_TYPE__ num, const T& val = T())
        {
            this->_arraySize = num;
            this->_array = new T[num];

            // Filling array by <val> values
            for (int i = 0; i < num; i++)
            {
                this->_array[i] = val;
            }
        }

        ~MyVector()
        {
            if (_array != nullptr)
            {
                delete[] _array;
            }
        }

        void push_back()
        {

        }

        void pop_back()
        {

        }

        int size()
        {

        }

        int capacity()
        {

        }

        // Remove unusable memory
        void shrink_to_fit()
        {

        }

        bool empty()
        {

        }

        void clear()
        {

        }

        void reserve()
        {

        }

        void resize(int newSize)
        {

        }

        T at(int i)
        {
            if (i < this->_arraySize)
            {
                return _array[i];
            }
            else
            {
                throw out_of_range("Out of range error.");
            }

        }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");    

    return 0;
}