#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {
    template < typename T >
    class Vector
    {
        public:
            /*--- CON/DE_STRUCTORS ---*/
            
            Vector(void): _Vector(NULL), _size(0)
            {}

            Vector(unsigned int n): _Vector(new T[n]()), _size(n)
            {}

            Vector(const Vector &Vector): _Vector(new T[Vector._size]), _size(Vector._size)
            {
                for (unsigned int i = 0 ; i < Vector._size; i ++)
                    _Vector[i] = Vector._Vector[i];
            }

            ~Vector(void)
            {
                if (_size > 0)
                    delete[] _Vector;
            }

            /*--- OPERATORS ---*/
            
            Vector	&operator =(Vector const &Vector)
            {
                for (int i = 0 ; i < Vector._size; i ++)
                    _Vector = Vector._Vector[i];
                _size = Vector._size;
                return(*this);
            }

            T	&operator[](unsigned int index)
            {
                if (index < _size)
                    return(_Vector[index]);
                else
                    throw Vector::InvalidRead();	
            }

            /*--- ACCESSORS ---*/

            unsigned int size() const
            {
                return(_size);
            }

        private:
            T				*_Vector;
            unsigned int	_size;
    };
}

#endif
