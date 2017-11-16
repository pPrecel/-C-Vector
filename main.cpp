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

	vec.push_back();
	return 0;
}