#pragma once
#include <vector>
#include "Shape.h"

using std::vector;

class Polygon : public Shape {
	vector<point> Vertices;

public:
	// ������������
	Polygon(const vector<point>& ver) : Vertices(ver) {}

	template<typename... T>
	Polygon(T... points) : Vertices({ points... }) {};

	//������
	int verticesCount() const {//���������� ������
		return Vertices.size();
	}

	vector<point> getVertices() {//���� ������� ��� ����������� ���������
		vector<point> v = Vertices;
		return v;
	}

	bool isConvex() const {//�������� ��

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

		vector<double> A(Vertices.size()), B(casted->Vertices.size());
		for (int i = 0; i < Vertices.size(); i++)
		{

		}
	}
	bool containsPoint(point point) const override {// ��������� �� ����� ������ ������

	}
	bool rotate(point center, double angle) const override = 0;// ������� �� ���� (� ��������, ������ ������� �������) ������������ �����
	bool reflex(point center) const override = 0;// ��������� ������������ �����
	bool reflex(Line axis) const override = 0;// ��������� ������������ ������
	bool scale(point center, double coefficient) const override = 0;// ��������� � ������������� coefficient � ������� center
};