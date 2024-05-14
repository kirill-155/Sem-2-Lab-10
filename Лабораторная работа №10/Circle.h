#pragma once
#include "Ellipse.h"

class Circle : public Ellipse {
public:

	Circle(Point p, double r) : Ellipse(p, p, r*2) {}

	// ������
	double radius() const {
		return dist / 2;
	}

};