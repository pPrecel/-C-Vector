#pragma once
#include<iostream>

//Header
class Vector {
private:
	//Main types
	int *data;
	int length;
	int curPos;

public:
	//Constructors and destructor
	Vector();
	Vector(int tmp);
	Vector(const Vector& othVec);
	Vector(Vector&& othVec);
	virtual ~Vector();

	//Operators
	Vector& operator=(const Vector& othVec);
	Vector& operator=(Vector&& othVec);
	int& operator[](const int& iter);

	//Methods
	int at(const int iter);

	
	//Tmp things
	friend int main();
};
