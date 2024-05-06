#pragma once
#include <iostream>
#include "Point.h"

class Line {
public:
	double A, B, C;

	Line(point p1, point p2) {
		p1.line(p2, A, B, C);
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	Line(T k, T b) {
		A = k;
		C = b;
		B = -1;
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	Line(point p, T k) {
		A = k;
		C = p.y - k * p.x;
		B = -1;
	}

	bool operator==(const Line& l) const {
		return A == l.A && B == l.B && C == l.C;
	}

	bool operator!=(const Line& l) const {
		return !(*this == l);
	}

};

void point::reflect(const Line& line) {
	if (line.B == 0)
	{
		x = (-line.C / line.A) * 2 - x;
		y = (-line.C / line.A) * 2 - y;
	}
	else
	{
		point P;
		P.x = -(line.A * line.C + line.B * (line.A * y - line.B * x)) / line.A * line.A + line.B * line.B;
		P.y = -(line.A * P.x + line.C) / line.B;
		*this = P * 2 - *this;
	}
}
