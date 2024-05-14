#pragma once
#include "Point.h"
#include "Line.h"

// Абстрактный класс Shape — фигура.
class Shape {
public:
	virtual double perimeter() const = 0;// периметр
	virtual double area() const = 0;// площадь
	virtual bool operator==(const Shape& another) const = 0;// совпадает ли эта фигура с другой
	bool operator!=(const Shape& another) const {
		return !(*this == another);
	}
	virtual bool isCongruentTo(const Shape& another) const = 0;// равна ли эта фигура другой в геометрическом смысле
	virtual bool isSimilarTo(const Shape& another) const = 0;  // подобна ли эта фигура другой
	virtual bool containsPoint(Point point) const = 0;// находится ли точка внутри фигуры
	virtual void rotate(Point center, double angle) = 0;// поворот на угол (в градусах, против часовой стрелки) относительно точки
	virtual void reflex(Point center) = 0;// симметрию относительно точки
	virtual void reflex(Line axis) = 0;// симметрию относительно прямой
	virtual void scale(Point center, double coefficient) = 0;// гомотетию с коэффициентом coefficient и центром center
};