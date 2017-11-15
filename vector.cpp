#include "vector.h"

//Constructors class Vector
Vector::Vector() { length = 0; data = nullptr; curPos = 0; }
Vector::Vector(int tmp) :length{ tmp }, data{ new int[tmp] }, curPos{ 0 } {
	if (tmp < 1) {
		std::cout << "FATAL ERROR! CLASS VECTOR CANT CREATE NEW ELEMENT! LENGTH IS SMALLER THAN 1!" << std::endl;
		length = NULL;
		curPos = NULL;
		delete[] data;
		data = nullptr;		
	}
	else {
		for (int i = 0; i < tmp; i++)
			data[i] = 0;
	}
}
Vector::Vector(const Vector &othVec) : data{ new int[othVec.length] }, length{ othVec.length }, curPos{ othVec.curPos } {
	for (int i = 0; i < othVec.length - othVec.curPos; i++) {
		data[i] = othVec.data[i];
	}	
}
Vector::Vector(Vector&& othVec){
	length = othVec.length;
	curPos = othVec.curPos;
	data = othVec.data;
	
	othVec.data = nullptr;
	othVec.length = NULL;
	othVec.curPos = NULL;
}
Vector::~Vector() { delete[] data; length = NULL; curPos = NULL; }

//Public operators
Vector & Vector::operator=(const Vector & othVec)
{
	data = new int[othVec.length];
	length = othVec.length;
	curPos = othVec.curPos;

	for (int i = 0; i < othVec.length - othVec.curPos; i++) {
		data[i] = othVec.data[i];
	}

	return *this;
}
Vector & Vector::operator=(Vector && othVec)
{
	data = othVec.data;
	length = othVec.length;
	curPos = othVec.curPos;

	othVec.curPos = NULL;
	othVec.length = NULL;
	othVec.data = nullptr;

	return *this;
}
int & Vector::operator[](const int& iter) {
	if (iter >= 0 && iter < length - curPos)
		return data[iter];
}

//Public methods return private types
int Vector::at(const int iter) { return data[iter]; }