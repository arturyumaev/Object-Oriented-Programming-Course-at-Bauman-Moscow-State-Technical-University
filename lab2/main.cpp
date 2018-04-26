#include "stdafx.h"

template <typename T>
class ndarray
{
    public:
        ndarray() // Default constructor overload
        {
            this->_dim = 1; // Just a number
            this->_ndarray = this->allocate_and_fill_memory(this->_dim, 0);
        }

        ndarray(UI dim, const T default_value = T())
        {
            if (dim > 0) // Singularity case, dim=0
            {
                this->_dim = dim;
                this->_ndarray = this->allocate_and_fill_memory(this->_dim, default_value);
            }
            else
            {
                throw domain_error("ndarray dim <= 0");
            }
        }


        ndarray(const ndarray<T>& object) // Copy constructor
        {
            this->_ndarray = new T[object.get_dim()];
            this->_dim = object.get_dim();

            for (int i = 0; i < object.get_dim(); i++)
            {
                this->_ndarray[i] = object.at(i);
            }
        }

        ~ndarray() // Destructor
        {
            delete[] this->_ndarray;
        }


        T& operator [] (int i) // Done
        {
            if (index_is_correct(i))
            {
                return this->_ndarray[i];
            }
            else
            {
                throw overflow_error("Index out of range");
            }
        }

       const T& operator [] (int i) const // Done
        {
            if (index_is_correct(i))
            {
                return this->_ndarray[i];
            }
            else
            {
                throw overflow_error("Index out of range");
            }
        }

        void operator = (const ndarray<T>& object) // Done
        {
            if (this->_ndarray != nullptr)
            {
                delete[] this->_ndarray;
            }

            this->_ndarray = new T[object.get_dim()];
            this->_dim = object.get_dim();

            for (int i = 0; i < object.get_dim(); i++)
            {
                this->_ndarray[i] = object.at(i);
            }
        }

        template <typename N>
        bool operator == (const ndarray<N>& object) // Done
        {
            int condition_flag = 0;

            if (this->_dim != object.get_dim())
            {
                return false;
            }
            else
            {
                if (this->pth_norm(2) != object.pth_norm(2))
                {
                    return false;
                }

                return true;
            }
        }

        template <typename N>
        bool operator < (const ndarray<N>& object) // Done
        {
            int condition_flag = 0;

            if (this->_dim != object.get_dim())
            {
                return false;
            }
            else
            {
                if (this->len() >= object.len())
                {
                    return false;
                }

                return true;
            }
        }

        template <typename N>
        bool operator > (const ndarray<N>& object) // Done
        {
            int condition_flag = 0;

            if (this->_dim != object.get_dim())
            {
                return false;
            }
            else
            {
                if (this->pth_norm(2) <= object.pth_norm(2))
                {
                    return false;
                }

                return true;
            }
        }

        template <typename N>
        bool operator <= (const ndarray<N>& object) // Done
        {
            int condition_flag = 0;

            if (this->_dim != object.get_dim())
            {
                return false;
            }
            else
            {
                if (this->pth_norm(2) > object.pth_norm(2))
                {
                    return false;
                }

                return true;
            }
        }

        template <typename N>
        bool operator >= (const ndarray<N>& object) // Done
        {
            int condition_flag = 0;

            if (this->_dim != object.get_dim())
            {
                return false;
            }
            else
            {
                if (this->pth_norm(2) < object.pth_norm(2))
                {
                    return false;
                }

                return true;
            }
        }
    
        template <typename N>
        bool operator != (const ndarray<N>& object) // Done
        {
            int condition_flag = 0;

            if (this->_dim != object.get_dim())
            {
                return false;
            }
            else
            {
                if (this->pth_norm(2) == object.pth_norm(2))
                {
                    return false;
                }

                return true;
            }
        }

        template <typename N>
        void mult_by_num(N num) // Done
        {
            for (int i = 0; i < this->_dim; i++)
            {
                this->_ndarray[i] = this->_ndarray[i] * num;
            }
        }

        template <typename M>
        void increase_num(M num) // Done
        {
            for (int i = 0; i < this->_dim; i++)
            {
                this->_ndarray[i] = this->_ndarray[i] + num;
            }
        }

        float pth_norm(UI p) const // Done
        {
            if (p > 0)
            {
                float pth_norm = 0;

                for (int i = 0; i < this->_dim; i++)
                {
                    pth_norm += pow(abs(this->_ndarray[i]), p);
                }

                return pow(pth_norm, (1.0 / p));
            }
            else
            {
                throw domain_error("p is null");
            }
            
        }

        T len() const // Done
        {
            return this->pth_norm(2);
        }

        T at(int i) const // Done
        {
            if (index_is_correct(i))
            {
                return this->_ndarray[i];
            }
            else
            {
                throw overflow_error("Index out of range");
            }
        }

        void print() // Done
        {
            printf("\n%-8c a[i]\n", 'i');

            for (int i = 0; i < this->_dim; i++)
            {
                printf("%-8d %0.4f\n", i, (float) this->_ndarray[i]);
            }
        }

        UI get_dim() const // Done
        {
            return this->_dim;
        }

        float cross (const ndarray& object) // Done
        {
            if (this->_dim != object.get_dim())
            {
                throw domain_error("dim of 1st != dim of 2nd");
            }
            else
            {
                float cross = 0;

                for (int i = 0; i < this->get_dim(); i++)
                {
                    cross += (this->_ndarray[i] * object.at(i));
                }

                return cross;
            }
        }

        bool is_orthogonal_to(const ndarray& object)
        {
            if (this->cross(object) == 0.0)
            {
                return true;
            }
            
            return false;
        }

        void fill(UI index, T num) // Done
        {
            if (this->index_is_correct(index))
            {
                this->_ndarray[index] = num;
            }
            else
            {
                throw domain_error("Bad index or index out of range");
            }
        }

    private:
        T* _ndarray;
        UI _dim;

        T* allocate_and_fill_memory(UI dim, T default_value) // Done
        {
            return this->fill_memory(new T[dim], default_value);
        }

        T* fill_memory(T* memory, T value) // Done
        {
            for (int i = 0; i < this->_dim; i++)
            {
                memory[i] = value;
            }

            return memory;
        }

        bool index_is_correct(int i) const // Done
        {
            if ((i >= 0) && (i < this->_dim))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

void printStatus(int testIndex, bool status)
{
    if (status == true)
    {
        cout << "Test " << testIndex << " --- OK" << endl;
    }
    else
    {
        cout << "Test " << testIndex << " --- ERROR" << endl;
    }
}

void UnitTest()
{
    ndarray<int> a(10, 1);
    ndarray<int> b(5, 5);
    ndarray<int> c(10, 3);
    ndarray<int> d(4, 1);
    ndarray<int> o1(2, 1);
    ndarray<int> o2(o1);
    o2.fill(0, -1.0);

    (a.cross(c) == 30.0) ? printStatus(1, 1) : printStatus(1, 0);
    (a == b) ? printStatus(2, 0) : printStatus(2, 1);
    ((a[3] == 1) && (a.at(3) == 1)) ? printStatus(3, 1) : printStatus(3, 0);
    (d.len() == 2) ? printStatus(4, 1) : printStatus(4, 0);
    (~(d < a)) ? printStatus(5, 1) : printStatus(5, 0);
    (a < c) ? printStatus(6, 1) : printStatus(6, 0);
    (o1.is_orthogonal_to(o2)) ? printStatus(7, 1) : printStatus(7, 0);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    UnitTest();

    return 0;
}
