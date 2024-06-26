#pragma once
#include <iostream>
#include <vector>
#include "Shape.h"

using std::vector;

class Polygon : public Shape {
protected:
	vector<Point> Vertices;

public:
	// ������������
	Polygon(const vector<Point>& ver) : Vertices(ver) {}

	Polygon(std::initializer_list<Point> points) : Vertices(points) {};

	//������
	int verticesCount() const {//���������� ������
		return Vertices.size();
	}

	vector<Point> getVertices() const {//���� ������� ��� ����������� ���������
		vector<Point> v = Vertices;
		return v;
	}

	bool isConvex() const {//�������� ��
		int size = Vertices.size();
		if (size < 4)
			return true;
		for (int i = 0; i < size; i++)
		{
			double a, b, c;
			Vertices[(size - 1 + i) % size].line(Vertices[(i + 1) % size], a, b, c);
			// �� ���� ������� ������?
			bool res = (Vertices[i].x * a + Vertices[i].y * b + c) * (Vertices[(i + 2) % size].x * a + Vertices[(i + 2) % size].y * b + c) > 0;
			if (!res)
				return false;
		}
		return true;
	}

	void draw() {
		glLineWidth(3);
		glColor3f(0, 1, 0);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < Vertices.size(); i++) {
			glVertex2d(Vertices[i].x, Vertices[i].y);
		}
		glEnd();
		glFlush();
	}

	//������ �� Shape 
	double perimeter() const override {// ��������
		double P = 0;
		for (int i = 0; i < Vertices.size(); i++)
		{
			P += (Vertices[i] - Vertices[(i + 1) % Vertices.size()]).dist();
		}
		return P;
	}
	double area() const override {// �������
		double S = 0;
		for (int i = 0; i < Vertices.size(); i++)
		{
			S+= Vertices[i].x * Vertices[(i + 1) % Vertices.size()].y - Vertices[i].y * Vertices[(i + 1) % Vertices.size()].x;
		}
		return fabsl(S / 2);// ������
	}
	bool operator==(const Shape& another) const override {// ��������� �� ��� ������ � ������
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

	bool isCongruentTo(const Shape& another) const override {// ����� �� ��� ������ ������ � �������������� ������
		auto casted = dynamic_cast<const Polygon*>(&another);
		if (isSimilarTo(another) && area() == casted->area())
			return true;
		return false;
	}
	bool isSimilarTo(const Shape& another) const override {// ������� �� ��� ������ ������
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
	bool containsPoint(Point point) const override {// ��������� �� ����� ������ ������
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
	void rotate(Point center, double angle) override {// ������� �� ���� (� ��������, ������ ������� �������) ������������ �����
		double rad = (angle / 180) * M_PI;
		for (int i = 0; i < Vertices.size(); i++)
		{
			Point c = (Vertices[i] - center);
			Vertices[i].x = c.x * cos(rad) - c.y * sin(rad) + center.x;
			Vertices[i].y = c.x * sin(rad) + c.y * cos(rad) + center.y;
		}
	}
	void reflex(Point center) override {// ��������� ������������ �����
		for (int i = 0; i < Vertices.size(); i++)
			Vertices[i].reflex(center);
	}
	void reflex(Line axis) override {// ��������� ������������ ������
		for (int i = 0; i < Vertices.size(); i++)
			Vertices[i].reflex(axis);
	}
	void scale(Point center, double coefficient) override {// ��������� � ������������� coefficient � ������� center
		for (int i = 0; i < Vertices.size(); i++)
			Vertices[i].scale(center, coefficient);
	}
};