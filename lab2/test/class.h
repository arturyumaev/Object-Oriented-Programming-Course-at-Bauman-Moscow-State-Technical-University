#ifndef CLASS_H
#define CLASS_H

template <typename T>
class MyClass
{
    public:
        MyClass(int size);

        ~MyClass() // destructor
        {
            delete[] this->array;   
        }

        int getSize()
        {
            return this->size;
        }

        T& operator [] (int size)
        {
            return this->array[size];
        }

    private:
        T* array;
        int size;
};

#endif
