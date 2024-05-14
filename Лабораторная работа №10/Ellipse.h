#pragma once
#include <iostream>
#include <vector>
#include "Shape.h"

const double epsilon = 1e-3;

class Ellipse : public Shape {
	Point f1, f2;

protected:
	double dist;

	std::pair<double,double> abc() const {
		double a = dist / 2;
		double b = sqrt(pow(a, 2) - pow((f1, f2).dist() / 2, 2));
		return { a, b };
	}
public:

	Ellipse(Point f1, Point f2, double dist) : f1(f1), f2(f2), dist(dist) {}

	// Методы
	std::pair<Point, Point> focuses() {// фокусы
		return { f1,f2 };
	}

	std::pair<Line, Line> directrices() {// директрисы
		auto params = abc();
		Line line = Line(f1, f2);
		Point d_1 = (f1 - f2) * (params.first + params.first / eccentricity()) / (2 * params.first) + f2;
		Point d_2 = (f2 - f1) * (params.first + params.first / eccentricity()) / (2 * params.first) + f1;
		return { Line(d_1, d_1 + Point(line.A, line.B)), Line(d_2, d_2 + Point(line.A, line.B)) };
	}

	double eccentricity() {// эксцентроситет
		auto params = abc();
		return sqrt(1 - (params.second * params.second) / (params.first * params.first));
	}

	Point center() {
		return (f1 + f2) / 2;
	}

	void draw() {
		glPointSize(3);
		glColor3f(0, 1, 0);
		glBegin(GL_POINTS);
		Point center = (f1 + f2) / 2;
		double rad_1 = acos(abs(f1.x) / ((f1, f2).dist() / 2));
		rad_1 = rad_1 * M_PI / 180.0;

		if (f1 != f2) rad_1 = atan2(f1.y - f2.y, f1.x - f2.x);
		else rad_1 = 0;
		for (int i = 0; i < 361; i++) {
			double rad = i * M_PI / 180.0;
			Point dr;
			dr.x = center.x + this->abc().first * cos(rad) * cos(rad_1) - abc().second * sin(rad) * sin(rad_1);
			dr.y = center.y + this->abc().first * cos(rad) * sin(rad_1) + abc().second * sin(rad) * cos(rad_1);
			glVertex2d(dr.x, dr.y);
		}
		glEnd();
		glFlush();
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
	bool containsPoint(Point point) const override {// находится ли точка внутри фигуры
		if ((point, f1).dist() + (point, f2).dist() <= dist)
			return true;
		
		return false;
	}
	void rotate(Point center, double angle) override {// поворот на угол (в градусах, против часовой стрелки) относительно точки
		double rad = (angle / 180) * M_PI;
		f1.rotate(center, rad);
		f2.rotate(center, rad);
	}
	void reflex(Point center) override {// симметрию относительно точки
		f1.reflex(center);
		f2.reflex(center);
	}
	void reflex(Line axis) override {// симметрию относительно прямой
		f1.reflex(axis);
		f2.reflex(axis);
	}
	void scale(Point center, double coefficient) override {// гомотетию с коэффициентом coefficient и центром center
		f1.scale(center, coefficient);
		f2.scale(center, coefficient);
		dist *= coefficient;
	}
};