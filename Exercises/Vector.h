#ifndef VECTOR
#define VECTOR

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
	for (int i = 0; i < v.size(); i++)
		*(buffer + i) = v.at(i);
	bufferSize = v.size();
}
#endif
