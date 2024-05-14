#pragma once
#include "Polygon.h"

class Rectangle : public Polygon {

public:
	Rectangle(Point a, Point b, double k) : Polygon({ a, Point(0, 0), b, Point(0, 0) }) {
		double angle = M_PI - 2 * atan(k);
		Point middle = (a + b) / 2;
		a.rotate(middle, angle);
		Vertices[1] = a;
		b.rotate(middle, angle);
		Vertices[3] = b;
	}

	// Ìועמהû 
	Point center() const {
		vector<Point> ver = getVertices();
		return { (ver[0].x + ver[2].x) / 2, (ver[0].y + ver[2].y) / 2 };
	}

	std::pair<Line, Line> diagonals() const {
		vector<Point> ver = getVertices();
		return { Line(ver[0], ver[2]), Line(ver[1], ver[3]) };
	}
};