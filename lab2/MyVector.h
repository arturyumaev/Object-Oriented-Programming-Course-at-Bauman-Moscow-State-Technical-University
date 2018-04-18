#ifndef MYVECTOR_H
#define MYVECTOR_H

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

        ~MyVector() // Maybe also done..
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

        T* reference_back() // Done
        {
            return &(this->_array[this->_arraySize - 1]);
        }

        T* reference_at(__SIZE_TYPE__ i) // Done
        {
            if (i < this->_arraySize)
            {
                return &(this->_array[i]);
            }
            else
            {
                throw out_of_range("In MyVector::reference_at Out of range error");
            }
        }

        int size() // Done
        {
            return this->_arraySize;
        }

        int capacity()
        {

        }

        // Remove unusable memory
        void shrink_to_fit()
        {

        }

        bool empty() // Done
        {
            if (this->size())
            {
                return false;
            }
            else
            {
                return true;
            }
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

        T at(int i) // Done
        {
            if (i < this->_arraySize)
            {
                return this->_array[i];
            }
            else
            {
                throw out_of_range("In MyVector::at Out of range error.");
            }
        }
};

#endif