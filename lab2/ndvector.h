#ifndef NDVECTOR_H
#define NDVECTOR_H

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

#endif