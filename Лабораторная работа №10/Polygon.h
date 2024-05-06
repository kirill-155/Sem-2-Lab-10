#pragma once
#include <iostream>
#include <vector>
#include "Shape.h"

using std::vector;

class Polygon : public Shape {
protected:
	vector<point> Vertices;

public:
	// Конструкторы
	Polygon(const vector<point>& ver) : Vertices(ver) {}

	Polygon(std::initializer_list<point> points) : Vertices(points) {};

	//Методы
	int verticesCount() const {//количество вершин
		return Vertices.size();
	}

	vector<point> getVertices() const {//сами вершины без возможности изменения
		vector<point> v = Vertices;
		return v;
	}

	bool isConvex() const {//выпуклый ли
		int size = Vertices.size();
		if (size < 4)
			return true;
		for (int i = 0; i < size; i++)
		{
			double a, b, c;
			Vertices[(size - 1 + i) % size].line(Vertices[(i + 1) % size], a, b, c);
			// по одну сторону прямой?
			bool res = (Vertices[i].x * a + Vertices[i].y * b + c) * (Vertices[(i + 2) % size].x * a + Vertices[(i + 2) % size].y * b + c) > 0;
			if (!res)
				return false;
		}
		return true;
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

		int size = Vertices.size();
		vector<double> A(size), B(size);
		for (int i = 0; i < size; i++)
		{
			double a, b, c;
			a = (Vertices[i] - Vertices[(i + 1) % size]).dist2();
			b = (Vertices[(i + 1) % size] - Vertices[(i + 2) % size]).dist2();
			c = (Vertices[(i + 2) % size] - Vertices[i]).dist2();
			A[i] = (b + c - a) / (2 * sqrt(b) * sqrt(c));
		}
		for (int i = 0; i < size; i++)
		{
			double a, b, c;
			a = (casted->Vertices[i] - casted->Vertices[(i + 1) % size]).dist2();
			b = (casted->Vertices[(i + 1) % size] - casted->Vertices[(i + 2) % size]).dist2();
			c = (casted->Vertices[(i + 2) % size] - casted->Vertices[i]).dist2();
			B[i] = (b + c - a) / (2 * sqrt(b) * sqrt(c));
		}

		bool flag;
		double k;
		for (int i = 0; i < size; i++)
		{
			flag = 1;
			k = (Vertices[i] - Vertices[(i + 1) % size]).dist2() / (casted->Vertices[0] - casted->Vertices[1]).dist2();
			for (int j = 0; j < size; j++)
			{
				if (A[i] - B[j] > 0.00001 || 
					(Vertices[i] - Vertices[(i + 1) % size]).dist2() / (casted->Vertices[j] - casted->Vertices[(j + 1) % size]).dist2() - k > 0.00001)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				return true;
			}
		}
		return false;
	}
	bool containsPoint(point point) const override {// находится ли точка внутри фигуры
		if (verticesCount() <= 2) 
			return false;
		
		bool result = false;
		int j = Vertices.size() - 1;
		for (int i = 0; i < Vertices.size(); i++) {
			if ((Vertices[i].y < point.y && Vertices[j].y >= point.y || Vertices[j].y < point.y && Vertices[i].y >= point.y) &&
				(Vertices[i].x + (point.y - Vertices[i].y) / (Vertices[j].y - Vertices[i].y) * (Vertices[j].x - Vertices[i].x) < point.x))
				result = !result;
			j = i;
		}
		return result;
	}
	void rotate(point center, double angle) override {// поворот на угол (в градусах, против часовой стрелки) относительно точки
		double rad = (angle / 180) * M_PI;
		for (int i = 0; i < Vertices.size(); i++)
		{
			point c = (Vertices[i] - center);
			Vertices[i].x = c.x * cos(rad) - c.y * sin(rad) + center.x;
			Vertices[i].y = c.x * sin(rad) + c.y * cos(rad) + center.y;
		}
	}
	void reflex(point center) override {// симметрию относительно точки
		center = center * 2;
		for (int i = 0; i < Vertices.size(); i++)
		{
			Vertices[i] = center - Vertices[i];
		}
	}
	void reflex(Line axis) override {// симметрию относительно прямой
		if (axis.B == 0)
		{
			for (int i = 0; i < Vertices.size(); i++)
				Vertices[i] = { (-axis.C / axis.A) * 2 - Vertices[i].x,(-axis.C / axis.A) * 2 - Vertices[i].y };
		}
		else
		{
			double d = axis.A * axis.A + axis.B * axis.B;
			for (int i = 0; i < Vertices.size(); i++)
			{
				point P;
				P.x = -(axis.A * axis.C + axis.B * (axis.A * Vertices[i].y - axis.B * Vertices[i].x)) / d;
				P.y = -(axis.A * P.x + axis.C) / axis.B;
				Vertices[i] = P * 2 - Vertices[i];
			}
		}
	}
	void scale(point center, double coefficient) override {// гомотетию с коэффициентом coefficient и центром center
		for (int i = 0; i < Vertices.size(); i++)
		{
			Vertices[i] = (Vertices[i] - center) * coefficient + center;
		}
	}
};