#pragma once
#include <iostream>
#include <vector>
#include "Shape.h"

const double epsilon = 1e-3;

class Ellipse : public Shape {
	point f1, f2;

protected:
	double dist;

	std::pair<double,double> abc() const {
		double a = dist / 2;
		double b = sqrt(pow(a, 2) - pow((f1, f2).dist() / 2, 2));
		return { a, b };
	}
public:

	Ellipse(point f1, point f2, double dist) : f1(f1), f2(f2), dist(dist) {}

	// Методы
	std::pair<point, point> focuses() {// фокусы
		return { f1,f2 };
	}

	std::pair<Line, Line> directrices() {// директрисы
		auto params = abc();
		Line line = Line(f1, f2);
		point d_1 = (f1 - f2) * (params.first + params.first / eccentricity()) / (2 * params.first) + f2;
		point d_2 = (f2 - f1) * (params.first + params.first / eccentricity()) / (2 * params.first) + f1;
		return { Line(d_1, d_1 + point(line.A, line.B)), Line(d_2, d_2 + point(line.A, line.B)) };
	}

	double eccentricity() {// эксцентроситет
		auto params = abc();
		return sqrt(1 - (params.second * params.second) / (params.first * params.first));
	}

	point center() {
		return (f1 + f2) / 2;
	}

	//Методы из Shape 
	double perimeter() const override {// периметр
		auto params = abc();
		return M_PI * (3 * (params.first + params.second) - sqrtl((3 * params.first + params.second) * (params.first + 3 * params.second)));
	}
	double area() const override {// площадь
		auto params = abc();
		return M_PI * params.first * params.second;
	}
	bool operator==(const Shape& another) const override {// совпадает ли эта фигура с другой
		auto casted = dynamic_cast<const Ellipse*>(&another);
		if (casted != nullptr && 
			(casted->f1 == f1 && casted->f2 == f2 || casted->f1 == f2 && casted->f2 == f1) && 
			abs(casted->dist - dist) < epsilon) {
			return true;
		}
		return false;
	}
	bool isCongruentTo(const Shape& another) const override {// равна ли эта фигура другой в геометрическом смысле
		auto casted = dynamic_cast<const Ellipse*>(&another);
		if ((casted != nullptr) &&
			abs((casted->f1, casted->f2).dist() - (f1, f2).dist()) < epsilon &&
			abs(casted->dist - dist) < epsilon) {
			return true;
		}
		return false;
	}
	bool isSimilarTo(const Shape& another) const override {// подобна ли эта фигура другой
		auto casted = dynamic_cast<const Ellipse*>(&another);
		if ((casted != nullptr) &&
			abs((casted->f1, casted->f2).dist() - (f1, f2).dist() * casted->dist / dist) < epsilon) {
			return true;
		}
		return false;
	}
	bool containsPoint(point point) const override {// находится ли точка внутри фигуры
		if ((point, f1).dist() + (point, f2).dist() <= dist)
			return true;
		
		return false;
	}
	void rotate(point center, double angle) override {// поворот на угол (в градусах, против часовой стрелки) относительно точки
		double rad = (angle / 180) * M_PI;
		f1.rotate(center, rad);
		f2.rotate(center, rad);
	}
	void reflex(point center) override {// симметрию относительно точки
		f1.reflect(center);
		f2.reflect(center);
	}
	void reflex(Line axis) override {// симметрию относительно прямой
		f1.reflect(axis);
		f2.reflect(axis);
	}
	void scale(point center, double coefficient) override {// гомотетию с коэффициентом coefficient и центром center
		f1.scale(center, coefficient);
		f2.scale(center, coefficient);
		dist *= coefficient;
	}
};