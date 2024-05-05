#pragma once
#include "Point.h"
#include "Line.h"

// ����������� ����� Shape � ������.
class Shape {
public:
	virtual double perimeter() const = 0;// ��������
	virtual double area() const = 0;// �������
	virtual bool operator==(const Shape& another) const = 0;// ��������� �� ��� ������ � ������
	bool operator!=(const Shape& another) const {
		return !(*this == another);
	}
	virtual bool isCongruentTo(const Shape& another) const = 0;// ����� �� ��� ������ ������ � �������������� ������
	virtual bool isSimilarTo(const Shape& another) const = 0;  // ������� �� ��� ������ ������
	virtual bool containsPoint(point point) const = 0;// ��������� �� ����� ������ ������
	virtual bool rotate(point center, double angle) const = 0;// ������� �� ���� (� ��������, ������ ������� �������) ������������ �����
	virtual bool reflex(point center) const = 0;// ��������� ������������ �����
	virtual bool reflex(Line axis) const = 0;// ��������� ������������ ������
	virtual bool scale(point center, double coefficient) const = 0;// ��������� � ������������� coefficient � ������� center
};