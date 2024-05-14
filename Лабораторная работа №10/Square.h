#pragma once
#include "Circle.h"
#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(Point a, Point b) : Rectangle(a, b, 1) {}

	// Методы
    Circle circumscribedCircle() const {// Круг описанный
        vector<Point> ver = getVertices();
        return { center(), (ver[0], ver[1]).dist() / 2 };
    }

    Circle inscribedCircle() const {// Круг вписанный
        vector<Point> ver = getVertices();
        return { center(), (ver[0], ver[2]).dist() / 2 };
    }
};