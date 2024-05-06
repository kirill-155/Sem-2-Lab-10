#pragma once
#include "Polygon.h"
#include "Circle.h"

class Triangle : public Polygon {
    using Polygon::Polygon;

public:
    Circle circumscribedCircle() const {// ���� ���������
        Line first = orthogonal(Line(Vertices[0], Vertices[1]), point((Vertices[0].x + Vertices[1].x) / 2, (Vertices[0].y + Vertices[1].y) / 2));
        Line second = orthogonal(Line(Vertices[1], Vertices[2]), point((Vertices[1].x + Vertices[2].x) / 2, (Vertices[1].y + Vertices[2].y) / 2));
        point center = intersect(first, second);
        return { center, (center, Vertices[0]).dist()};
    }

    Circle inscribedCircle() const {// ���� ���������
        double a = (Vertices[0], Vertices[1]).dist();
        double b = (Vertices[1], Vertices[2]).dist();
        double c = (Vertices[2], Vertices[0]).dist();
        point tmp;
        tmp.x = (Vertices[2].x * a + Vertices[0].x * b + Vertices[1].x * c) / (a + b + c);
        tmp.y = (Vertices[2].y * a + Vertices[0].y * b + Vertices[1].y * c) / (a + b + c);
        return { tmp, 2 * area() / (a + b + c) };
    }

    point centroid() const {
        double x = (Vertices[0].x + Vertices[1].x + Vertices[2].x) / 3;
        double y = (Vertices[0].y + Vertices[1].y + Vertices[2].y) / 3;
        return { x, y };
    }

    point orthocenter() const {
        Line first = orthogonal(Line(Vertices[0], Vertices[1]), Vertices[2]);
        Line second = orthogonal(Line(Vertices[1], Vertices[2]), Vertices[0]);
        return intersect(first, second);
    }

    Line EulerLine() const {
        return { circumscribedCircle().center(), orthocenter() };
    }

    Circle ninePointsCircle() const {
        point first = circumscribedCircle().center();
        point second = orthocenter();
        point center = point((first.x + second.x) / 2, (first.y + second.y) / 2);
        return { center, circumscribedCircle().radius() / 2 };
    }
};