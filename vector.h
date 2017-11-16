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
	dataType& operator[](const int& iter);

	//Methods
	dataType at(const int& iter);
	bool push_back();
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
Vector<dataType>::Vector(const int tmp) :length{ tmp }, data{ new dataType[tmp] }, curPos{ 0 } {
	if (tmp < 1) {
		std::cout << "FATAL ERROR! CLASS VECTOR CANT CREATE NEW ELEMENT! LENGTH IS SMALLER THAN 1!" << std::endl;
		length = NULL; curPos = NULL;
		delete[] data; data = nullptr;
	}
	else {
		for (int i = 0; i < tmp; i++)
			data[i] = 0;
	}
}

template <class dataType>
Vector<dataType>::Vector(const Vector& othVec) : data{ new int[othVec.length] }, length{ othVec.length }, curPos{ othVec.curPos } {
	for (int i = 0 - othVec.curPos; i < othVec.length - othVec.curPos; i++) {
		data[i] = othVec.data[i];
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
	delete[] data;
	length = NULL;
	curPos = NULL;
}


//Public operators
template<class dataType>
Vector<dataType> & Vector<dataType>::operator=(const Vector & othVec)
{
	data = new int[othVec.length];
	length = othVec.length;
	curPos = othVec.curPos;

	for (int i = 0 - othVec.curPos; i < othVec.length - othVec.curPos; i++) {
		data[i] = othVec.data[i];
	}

	return *this;
}

template<class dataType>
Vector<dataType> & Vector<dataType>::operator=(Vector && othVec)
{
	data = othVec.data;
	length = othVec.length;
	curPos = othVec.curPos;

	othVec.curPos = NULL;
	othVec.length = NULL;
	othVec.data = nullptr;

	return *this;
}

template<class dataType>
dataType & Vector<dataType>::operator[](const int& iter) {
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
bool Vector<dataType>::push_back() {
	dataType* newData = new dataType[length + 1];
	length++;

	for (int i = 0; i < length; i++) {
		newData[i] == data[i - curPos];
	}
	delete[]data;
	data = newData;

	return true;
}

template<class dataType>
bool Vector<dataType>::reserve(const int & howMany)
{
	return false;
}
