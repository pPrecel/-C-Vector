//
//
//    This file tests "vector.h"
//
//

#include <iostream>
#include <utility>
#include "vector.h"

void f() {
	Vector <int>v1(12);
}


int main() {
	Vector <int>v(5);
	Vector <int>vec(v);
	Vector <int>v2(std::move(v));

	vec.push_back(2);

	Vector<int>vector(1);

	vector.push_back(2);

	std::cout << vector[1] << std::endl;


	//-----------------
	Vector <int>a1(5);
	a1.reserve(20);
	std::cout << a1[24] << std::endl;


	Vector <int>a2(1);
	std::cout << a2.capacity() << std::endl;
	a2.resive(4);
	std::cout << a2.capacity() << std::endl;
	a2.resive(20);
	std::cout << a2[24] << std::endl;
	std::cout << a2[40] << std::endl;
	std::cout << a2.capacity() << std::endl;

	Vector <int>a3(-1);
	std::cout << a3.capacity() << std::endl;

	//-----------------
	Vector <int>b1(5);
	for (int i = 0; i < 5; i++)
		std::cout << b1[i] << " ";
	std::cout << std::endl;
	b1.insert(4, 4);
	for (int i = 0; i < 6; i++) {
		b1[i] = i;
		std::cout << (b1[i]) << " ";
	}
	std::cout << std::endl;

	b1.erase(1);
	for (int i = 0; i < 6; i++) {
		std::cout << (b1[i]) << " ";
	}

	b1.resive(20);
		
	std::cout << std::endl;

	Vector<int>::it zx(b1);
	for (Vector<int>::it zx(b1.begin()); zx != b1.end(); zx++) {
		std::cout << *zx << std::endl;
	}

	Vector<int>::it fi(b1.find_if(5));
	std::cout << *fi;

	Vector<int>::it fil(b1.find_if(666));

	return 0;
}