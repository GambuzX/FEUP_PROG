#ifndef VECTOR
#define VECTOR

#include <stdlib.h>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T & initial);
	Vector(const Vector<T> & v);
	~Vector();
	size_t size() const;
	bool empty() const;
	T & front();
	T & back();
	T & at(size_t index);
	void push_back(const T & value);
	void pop_back();
	void clear();
private:
	T * buffer;
	size_t bufferSize;
};

template <typename T>
Vector::Vector()
{
	buffer = NULL;
	bufferSize = 0;
}

template <typename T>
Vector::Vector(unsigned int size)
{
	buffer = new T[size];
	bufferSize = size;
}

template <typename T>
Vector::Vector(unsigned int size, const T & initial)
{
	buffer = new T[size];
	for (T * pointer = buffer; pointer < buffer + size; pointer++)
		*pointer = initial;
	bufferSize = size;
}

template <typename T>
Vector::Vector(const Vector<T> & v)
{
	buffer = new T[v.size()];
	for (size_t i = 0; i < v.size(); i++)
		*(buffer + i) = v.at(i);
	bufferSize = v.size();
}

template <typename T>
Vector::~Vector()
{
	delete [] buffer;
}

template <typename T>
size_t Vector::size() const
{
	return bufferSize;
}

template <typename T>
bool empty() const
{
	return buffer == NULL;
}

template <typename T>
T & Vector::front()
{
	return *buffer;
}

template < typename T>
T & Vector::back()
{
	return *(buffer + bufferSize - 1);
}

template <typename T>
T & Vector::at(size_t index)
{
	return *(buffer + index);
}

template <typename T>
void Vector::push_back(const T & value)
{
	T * newBuffer = realloc(buffer, bufferSize + 1);
	bufferSize++;
	*(newBuffer + bufferSize - 1) = value;
	buffer = newBuffer;
}

template <typename T>
void Vector::pop_back()
{
	if (bufferSize = 1)
	{
		bufferSize = 0;
		buffer = NULL;
	}
	else
	{
		T * newBuffer = realloc(buffer, bufferSize - 1);
		bufferSize--;
		buffer = newBuffer;
	}
}

template <typename T>
void Vector::clear()
{
	delete[] buffer;
	buffer = NULL;
	bufferSize = 0;
}

#endif
