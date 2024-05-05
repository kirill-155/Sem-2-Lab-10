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
	virtual bool containsPoint(point point) const = 0;// находится ли точка внутри фигуры
	virtual bool rotate(point center, double angle) const = 0;// поворот на угол (в градусах, против часовой стрелки) относительно точки
	virtual bool reflex(point center) const = 0;// симметрию относительно точки
	virtual bool reflex(Line axis) const = 0;// симметрию относительно прямой
	virtual bool scale(point center, double coefficient) const = 0;// гомотетию с коэффициентом coefficient и центром center
};