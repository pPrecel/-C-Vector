#pragma once
#include<iostream>


//Header
template <class dataType>
class Vector {
private:
	//Main types
	dataType *data;
	int length;
	int curPos;

	//Private methods
	dataType* alloc(const int& len);
	dataType* expand_data(dataType* myData, const int& myDataLen, const int& howMany);
	void fill_data(dataType* myData, const int& startPos, const int& finalPos, dataType arg);
	dataType* copy_data(dataType* oldData, dataType* newData, const int* len, const int& startPos = 0);

public:
	//Constructors and destructor
	Vector();
	Vector(const int tmp);
	Vector(const Vector& othVec);
	Vector(Vector&& othVec);
	~Vector();

	//Operators
	Vector& operator=(const Vector& othVec);
	Vector& operator=(Vector&& othVec);
	dataType operator[](const int& iter);

	//Methods
	dataType at(const int& iter);
	bool push_back(const dataType& newElem);
	bool reserve(const int& howMany);
	bool resive(const int& howMany);
	bool inrest(const int& which);
	bool erase(const int& which);


	//Tmp things
	friend int main();
};

	
//Constructors and destructor

template <class dataType>
Vector<dataType>::Vector() : length{ 0 }, data{ nullptr }, curPos{ 0 } {
}

template <class dataType>
Vector<dataType>::Vector(const int tmp) : length{ tmp }, data{ alloc(tmp) }, curPos{ 0 } {
	if (tmp < 1 || data == nullptr) {
		std::cout << "FATAL ERROR! CLASS VECTOR CANT CREATE NEW ELEMENT! BAD INPUT DATA!" << std::endl;
		length = NULL; curPos = NULL;
	}
	else {
		for (int i = 0; i < tmp; i++) data[i] = 0;
	}
}

template <class dataType>
Vector<dataType>::Vector(const Vector& othVec) : data{ alloc(othVec.length) }, length{ othVec.length }, curPos{ othVec.curPos } {
	if (data == nullptr) {
		std::cout << "FATAL ERROR! CLASS VECTOR CANT CREATE NEW ELEMENT!" << std::endl;
		length = NULL; curPos = NULL;
	}
	else {
		for (int i = 0 - othVec.curPos; i < othVec.length - othVec.curPos; i++) {
			data[i] = othVec.data[i];
		}
	}
}

template <class dataType>
Vector<dataType>::Vector(Vector&& othVec) : length{ othVec.length }, curPos{ othVec.curPos }, data{ othVec.data } {
	othVec.data = nullptr;
	othVec.length = NULL;
	othVec.curPos = NULL;
}

template <class dataType>
Vector<dataType>::~Vector() {
	if (data != nullptr) {
		delete[] data;
	}
	length = NULL;
	curPos = NULL;
}


//Public operators
template<class dataType>
Vector<dataType> & Vector<dataType>::operator=(const Vector & othVec){
	data = alloc(othVec.length);
	if (data != nullptr) {
		length = othVec.length;
		curPos = othVec.curPos;

		for (int i = 0 - othVec.curPos; i < othVec.length - othVec.curPos; i++) {
			data[i] = othVec.data[i];
		}
	}
	return *this;
}

template<class dataType>
Vector<dataType> & Vector<dataType>::operator=(Vector && othVec){
	data = othVec.data;
	length = othVec.length;
	curPos = othVec.curPos;

	othVec.curPos = NULL;
	othVec.length = NULL;
	othVec.data = nullptr;

	return *this;
}

template<class dataType>
dataType Vector<dataType>::operator[](const int& iter) {
	if (iter >= 0 - curPos && iter < length - curPos)
		return data[iter];
	return NULL;
}


//Public methods
template<class dataType>
dataType Vector<dataType>::at(const int& iter) {
	if (iter >= 0 - curPos && iter < length - curPos)
		return data[iter];
	return NULL;
}

template<class dataType>
bool Vector<dataType>::push_back(const dataType& newElem) {
	dataType* newData;
	if (!(newData = alloc(length+1)))
		return false;
	delete[]data;
	data = newData;
	data[length - 1] = newElem;

	return true;
}

template<class dataType>
bool Vector<dataType>::reserve(const int & howMany){
	dataType* newData;
	if (!(newData = alloc(length + howMany)))
		return false;
	length += howMany;

	for (int i = 0; i < length; i++)
		newData[i] = data[i - curPos];

	delete[]data;
	data = newData;

	return true;
}


//Private methods
template<class dataType>
dataType* Vector<dataType>::alloc(const int& len) {
	dataType* newData;
	try {
		newData = new dataType[len];
	}
	catch (std::bad_alloc b_a) {
	}
	return newData;
}

template<class dataType>
inline dataType * Vector<dataType>::expand_data(dataType * myData, const int & myDataLen, const int & howMany){
	dataType* newData;
	if (!(newData = alloc(howMany + myDataLen))) return NULL;
	copy_data(myData, newData, myDataLen);

	return newData;
}

template<class dataType>
inline void Vector<dataType>::fill_data(dataType* myData, const int & startPos, const int & finalPos, dataType arg){
	for (int i = startPos; i <= finalPos; i++)
		myData[i] = arg;
}

template<class dataType>
inline dataType * Vector<dataType>::copy_data(dataType * oldData, dataType * newData, const int * finalPos, const int& startPos = 0)
{
	for (int i = startPos; i <= finalPos; i++) newData[i] = oldData[i];
	return newData;
}
