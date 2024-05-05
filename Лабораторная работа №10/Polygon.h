#pragma once
#include <vector>
#include "Shape.h"

using std::vector;

class Polygon : public Shape {
	vector<point> Vertices;

public:
	// Конструкторы
	Polygon(const vector<point>& ver) : Vertices(ver) {}

	template<typename... T>
	Polygon(T... points) : Vertices({ points... }) {};

	//Методы
	int verticesCount() const {//количество вершин
		return Vertices.size();
	}

	vector<point> getVertices() {//сами вершины без возможности изменения
		vector<point> v = Vertices;
		return v;
	}

	bool isConvex() const {//выпуклый ли

	}

	//Методы из Shape 
	double perimeter() const override {// периметр
		double P = 0;
		for (int i = 0; i < Vertices.size(); i++)
		{
			P += (Vertices[i] - Vertices[(i + 1) % Vertices.size()]).dist();
		}
		return P;
	}
	double area() const override {// площадь
		double S = 0;
		for (int i = 0; i < Vertices.size(); i++)
		{
			S+= Vertices[i].x * Vertices[(i + 1) % Vertices.size()].y - Vertices[i].y * Vertices[(i + 1) % Vertices.size()].x;
		}
		return fabsl(S / 2);// модуль
	}
	bool operator==(const Shape& another) const override {// совпадает ли эта фигура с другой
		auto casted = dynamic_cast<const Polygon*>(&another);
		if (casted == nullptr || casted->verticesCount() != verticesCount())
			return false;

		bool flag;
		int size = verticesCount();
		for (int i = 0; i < size; ++i) {
			flag = true;
			for (int j = 0; j < size; ++j) {
				if (Vertices[j] != casted->Vertices[(i + j) % size]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
		return false;
	}

	bool isCongruentTo(const Shape& another) const override {// равна ли эта фигура другой в геометрическом смысле
		auto casted = dynamic_cast<const Polygon*>(&another);
		if (isSimilarTo(another) && area() == casted->area())
			return true;
		return false;
	}
	bool isSimilarTo(const Shape& another) const override {// подобна ли эта фигура другой
		auto casted = dynamic_cast<const Polygon*>(&another);
		if (casted == nullptr || casted->verticesCount() != verticesCount() || isConvex() != casted->isConvex())
			return false;

		vector<double> A(Vertices.size()), B(casted->Vertices.size());
		for (int i = 0; i < Vertices.size(); i++)
		{

		}
	}
	bool containsPoint(point point) const override {// находится ли точка внутри фигуры

	}
	bool rotate(point center, double angle) const override = 0;// поворот на угол (в градусах, против часовой стрелки) относительно точки
	bool reflex(point center) const override = 0;// симметрию относительно точки
	bool reflex(Line axis) const override = 0;// симметрию относительно прямой
	bool scale(point center, double coefficient) const override = 0;// гомотетию с коэффициентом coefficient и центром center
};