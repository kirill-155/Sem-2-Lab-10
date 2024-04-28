#pragma once
#include <iostream>
#include "Point.h"

class line {
	double a, b, c;

public:
	line(point p1, point p2) {
		p1.line(p2, a, b, c);
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	line(T k, T x) {

	}
};