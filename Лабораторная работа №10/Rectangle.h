#pragma once
#include "Polygon.h"

class Rectangle : public Polygon {

public:
	Rectangle(point a, point b, double k) : Polygon({ a, point(0, 0), b, point(0, 0) }) {
		double angle = M_PI - 2 * atan(k);
		point middle = (a + b) / 2;
		a.rotate(middle, angle);
		Vertices[1] = a;
		b.rotate(middle, angle);
		Vertices[3] = b;
	}

	// Ìועמהû 
	point center() const {
		vector<point> ver = getVertices();
		return { (ver[0].x + ver[2].x) / 2, (ver[0].y + ver[2].y) / 2 };
	}

	std::pair<Line, Line> diagonals() const {
		vector<point> ver = getVertices();
		return { Line(ver[0], ver[2]), Line(ver[1], ver[3]) };
	}
};