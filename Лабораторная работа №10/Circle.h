#pragma once
#include "Ellipse.h"

class Circle : public Ellipse {
public:

	Circle(point p, double r) : Ellipse(p, p, r) {}

	// ������
	double radius() const {
		return dist / 2;
	}

};