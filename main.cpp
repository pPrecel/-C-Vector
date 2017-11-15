#include <iostream>
#include <utility>
#include "vector.h"



int main() {
	
	Vector v1(12);
	Vector v2(v1);
	Vector v3(std::move(v1));

	Vector vv1(5);
	Vector vv2 = vv1;
	Vector vv3 = std::move(vv1);

	vv3[1] = 1;
	int x = vv3[1];

	return 0;
}