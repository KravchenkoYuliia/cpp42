//
//CONSTRUCTORS
//

template <typename T>
Array<T>::Array(): _array(NULL), _size(0) {}


template <typename T>
Array<T>::Array( unsigned int n ): _size(n) {

	_array = new T[this->_size]();
//	for (unsigned int i = 0; i < this->_size; i++) {  this->_array[i] = ;  }
}

template <typename T>
Array<T>::Array( const Array<T>& other ) {
	
	*this = other;
}

template <typename T>
Array<T>::~Array() {  delete [] this->_array;  }

//
//OPERATORS
//

template <typename T>
Array<T>&	Array<T>::operator = ( const Array<T>& other ) {

	if (this != &other) {
		this->_array = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++) {  this->_array[i] = other._array[i];  }
		this->_size = other._size;
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator [] ( unsigned int i ) {

	if (i < 0 || i > this->_size - 1) {  throw std::out_of_range("Error: index is out of range");  }

	return (this->_array[i]);
}

template <typename T>
const T&	Array<T>::operator [] ( unsigned int i ) const {

	if (i < 0 || i > this->_size - 1) {  throw std::out_of_range("Error: index is out of range");  }

	return (this->_array[i]);
}


//
//GETTERS
template <typename T>
T*	Array<T>::getArray() const {  return _array;  }

template <typename T>
unsigned int	Array<T>::size() const {  return _size;  }
