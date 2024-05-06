#pragma once
#include "Circle.h"
#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(point a, point b) : Rectangle(a, b, 1) {}

	// Методы
    Circle circumscribedCircle() const {// Круг описанный
        vector<point> ver = getVertices();
        return { center(), (ver[0], ver[1]).dist() / 2 };
    }

    Circle inscribedCircle() const {// Круг вписанный
        vector<point> ver = getVertices();
        return { center(), (ver[0], ver[2]).dist() / 2 };
    }
};