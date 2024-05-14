#pragma once
#include <iostream>
#include <cassert>
#include "Point.h"

class Line {
public:
	double A, B, C;

	Line(Point p1, Point p2) {
		p1.line(p2, A, B, C);
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	Line(T k, T b) {
		A = k;
		C = b;
		B = -1;
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	Line(Point p, T k) {
		A = k;
		C = p.y - k * p.x;
		B = -1;
	}

	void draw() {
		glPointSize(2.0);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POINTS);
		for (double x = -wGrid; x <= wGrid; x += 0.01) {
			double y = (A * x + C) / -B * 1.0;
			glVertex2f(x, y);
		}
		glEnd();
		glFlush();
	}

	bool operator==(const Line& l) const {
		return A == l.A && B == l.B && C == l.C;
	}

	bool operator!=(const Line& l) const {
		return !(*this == l);
	}

};

Line orthogonal(const Line line, const Point axis = { 0, 0 }) {
	return { Point(axis.x, axis.y), Point(axis.x + line.A, axis.y + line.B) };
}

Point intersect(const Line& first, const Line& second) {// точка пересечения
	assert(!(first.A * second.B - second.A * first.B < 0.00001));
	double x = (first.B * second.C - second.B * first.C) / (first.A * second.B - second.A * first.B);
	double y = (first.C * second.A - second.C * first.C) / (first.A * second.B - second.A * first.B);
	return { x, y };
}

void Point::reflect(const Line& line) {
	if (line.B == 0)
	{
		this->x = (-line.C / line.A) * 2 - this->x;
		this->y = (-line.C / line.A) * 2 - this->y;
	}
	else
	{
		Point P;
		P.x = -(line.A * line.C + line.B * (line.A * this->y - line.B * this->x)) / line.A * line.A + line.B * line.B;
		P.y = -(line.A * P.x + line.C) / line.B;
		*this = P * 2 - *this;
	}
}
