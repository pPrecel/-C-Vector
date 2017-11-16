#include <iostream>
#include <utility>
#include "vector.h"
#include <vector>

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

	std::cout << vector[1];
	return 0;
}