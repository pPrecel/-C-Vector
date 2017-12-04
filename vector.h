#ifndef _VECTOR_H
#define _VECTOR_H
#include <xutility>

//Header
template <class dataType>
class Vector {
private:
	//Main types
	dataType *data;
	unsigned length;

	//Private methods
	dataType* alloc(const int& len);
	dataType* expand_data(dataType* myData, const int& myDataLen, const int& howMany);
	void fill_data(dataType* myData, const int& startPos, const int& finalPos, dataType arg = 0);
	dataType* copy_data(dataType* oldData, dataType* newData, const int& len, const int& startPos = 0);
	void delete_if(dataType* myData);

public:
	//Constructors and destructor
	Vector();
	Vector(const unsigned& tmp);
	Vector(const Vector& othVec);
	Vector(Vector&& othVec);
	~Vector();

	//Operators
	Vector& operator=(const Vector& othVec);
	Vector& operator=(Vector&& othVec);
	dataType& operator[](const unsigned& iter) const;

	//Methods
	dataType at(const int& iter) const;
	bool push_back(const dataType& newElem);
	bool reserve(const int& howMany);
	bool resive(const int& howMany);
	int capacity() const;
	bool insert(const int& which, const dataType& arg);
	bool erase(const int& which);

	//Iterator class
	class it{
	private:
		size_t curPos = 0;
		Vector& container;
	public:
		it(Vector& con, size_t curP = 0) :container{ con }, curPos{ curP } {
		}
		dataType& operator*() const {
			return container[curPos];
		}
		it& operator++() {
			curPos++;
			return *this;
		}
		it operator++(int) {
			curPos++;
			return *this;
		}
		it& operator--() {
			curPos--;
			return *this;
		}
		it operator--(int) {
			curPos--;
			return *this;
		}
		bool operator==(const it & iterClass) const {
			return curPos == iterClass.curPos;
		}
		bool operator!=(const it & iterClass) const {
			return curPos != iterClass.curPos;
		}
	};

	//methods with it mechanics
	it begin() {
		return it(*this, 0);
	}
	it end() {
		return it(*this, length);
	}
	template <typename predicate>
	it find_if(predicate pre) {
		it first = begin();
		it last = end();
		while (first != last) {
			if (predicate(*first) == pre) return first;
			++first;
		}
		Vector<int>NULLptr(-1);
		return it(NULLptr);
	}
};

//Constructors and destructor

template <class dataType>
Vector<dataType>::Vector() : length{ 0 }, data{ nullptr } {
}

template <class dataType>
Vector<dataType>::Vector(const unsigned& tmp) : length{ tmp }, data{ alloc(tmp) } {
	if (tmp < 1 || data == nullptr) {
		length = NULL;
	}
	else {
		for (int i = 0; i < tmp; i++) data[i] = 0;
	}
}

template <class dataType>
Vector<dataType>::Vector(const Vector& othVec) : data{ alloc(othVec.length) }, length{ othVec.length } {
	if (data == nullptr) {
		length = NULL;
	}
	else {
		for (int i = 0; i < othVec.length; i++) {
			data[i] = othVec.data[i];
		}
	}
}

template <class dataType>
Vector<dataType>::Vector(Vector&& othVec) : length{ othVec.length }, data{ othVec.data } {
	othVec.data = nullptr;
	othVec.length = NULL;
}

template <class dataType>
Vector<dataType>::~Vector() {
	if (data != nullptr) {
		delete_if(data);
	}
	length = NULL;
}


//Public operators
template<class dataType>
inline Vector<dataType> & Vector<dataType>::operator=(const Vector & othVec) {
	data = alloc(othVec.length);
	if (data != nullptr) {
		length = othVec.length;

		for (int i = 0; i < othVec.length; i++) {
			data[i] = othVec.data[i];
		}
	}
	return *this;
}

template<class dataType>
inline Vector<dataType> & Vector<dataType>::operator=(Vector && othVec) {
	data = othVec.data;
	length = othVec.length;

	othVec.length = NULL;
	othVec.data = nullptr;

	return *this;
}

template<class dataType>
inline dataType& Vector<dataType>::operator[](const unsigned& iter) const {
	return data[iter];
}


//Public methods
template<class dataType>
inline dataType Vector<dataType>::at(const int& iter) const {
	return data[iter];
}

template<class dataType>
inline bool Vector<dataType>::push_back(const dataType& newElem) {
	dataType* newData = nullptr;
	if (!(newData = expand_data(data, length, 1)))
		return false;
	length++;
	delete_if(data);
	data = newData;
	data[length - 1] = newElem;

	return true;
}

template<class dataType>
inline bool Vector<dataType>::reserve(const int & howMany) {
	dataType* newData;
	if (!(newData = expand_data(data, length, howMany)))
		return false;
	length += howMany;
	delete_if(data);
	data = newData;

	return true;
}

template<class dataType>
inline bool Vector<dataType>::resive(const int & howMany) {
	if (!(reserve(howMany)))
		return false;
	fill_data(data, length - howMany, length - 1);
	return true;
}

template<class dataType>
inline int Vector<dataType>::capacity() const {
	return (sizeof(dataType)*length + sizeof(length));
}

template<class dataType>
inline bool Vector<dataType>::insert(const int & which, const dataType & arg)
{
	dataType* newData = nullptr;
	if (!(newData = alloc(length + 1)) || which < 0 || which > length - 1)
		return false;
	copy_data(data, newData, which - 1);
	copy_data(data, newData, length - 1, which + 1);
	newData[which] = arg;
	length++;

	delete_if(data);
	data = newData;
	return true;
}

template<class dataType>
inline bool Vector<dataType>::erase(const int & which) {
	dataType* newData;
	if (!(newData = alloc(length - 1)) || which < 0 || which > length - 1)
		return false;
	copy_data(data, newData, which - 1);
	copy_data(data + 1, newData, length - 1, which);
	length--;

	delete_if(data);
	data = newData;
	return false;
}

//Private methods
template<class dataType>
inline dataType* Vector<dataType>::alloc(const int& len) {
	dataType* newData;
	try {
		newData = new dataType[len];
	}
	catch (std::bad_alloc b_a) {
		newData = nullptr;
	}
	return newData;
}

template<class dataType>
inline dataType * Vector<dataType>::expand_data(dataType * myData, const int & myDataLen, const int & howMany) {
	dataType* newData;
	if (!(newData = alloc(howMany + myDataLen))) return NULL;
	copy_data(myData, newData, myDataLen);

	return newData;
}

template<class dataType>
inline void Vector<dataType>::fill_data(dataType* myData, const int & startPos, const int & finalPos, dataType arg = 0) {
	for (int i = startPos; i <= finalPos; i++)
		myData[i] = arg;
}

template<class dataType>
inline dataType * Vector<dataType>::copy_data(dataType * oldData, dataType * newData, const int& finalPos, const int& startPos = 0) {
	for (int i = startPos; i <= finalPos; i++)
		newData[i] = oldData[i];
	return newData;
}

template<class dataType>
inline void Vector<dataType>::delete_if(dataType* myData) {
	if (myData)
		delete[] myData;
}

#endif	