template <typename T>
MyClass<T>::MyClass(int size) // default constructor
{
    this->size = size;
    this->array = new T[this->size];  
}