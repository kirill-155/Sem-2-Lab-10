#pragma once
#include <iostream>
#include <cassert>
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

	Line orthogonal(const Line line, const point axis = { 0, 0 }) {
		return { point(axis.x, axis.y), point(axis.x + line.A, axis.y + line.B) };
	}

	point intersect(const Line& first, const Line& second) {// точка пересечения
		assert(!(first.A * second.B - second.A * first.B < 0.00001));
		double x = (first.B * second.C - second.B * first.C) / (first.A * second.B - second.A * first.B);
		double y = (first.C * second.A - second.C * first.C) / (first.A * second.B - second.A * first.B);
		return { x, y };
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
