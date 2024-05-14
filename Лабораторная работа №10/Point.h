#pragma once
#include "Header.h"

class Line;

struct Point
{
	double x = 0, y = 0;

	Point() = default;

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	Point(T x, T y) : x(x), y(y) {}

	Point(const Point& p) : x(p.x), y(p.y) {}

	Point& operator=(const Point& B) {
		x = B.x;
		y = B.y;
		return *this;
	}

	Point operator+(const Point& B) const {
		Point res;
		res.x = x + B.x;
		res.y = y + B.y;
		return res;
	}

	Point operator-(const Point& B) const {
		Point res;
		res.x = x - B.x;
		res.y = y - B.y;
		return res;
	}

	Point operator*(double k) const {
		Point res;
		res.x = x * k;
		res.y = y * k;
		return res;
	}

	Point operator/(double k) const {
		Point res;
		res.x = x / k;
		res.y = y / k;
		return res;
	}

	void draw() {
		glPointSize(5);
		glColor3f(0, 1, 0);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		glFlush();
	}

	void line(const Point& B, double& a, double& b, double& c) const {
		a = B.y - y, b = x - B.x, c = (-a) * x + (-b) * y;
	}

	double line(const Point& B, const Point& C) const {
		double a = B.y - y, b = x - B.x, c = (-a) * x + (-b) * y;
		return a * C.x + b * C.y + c;
	}

	double dist2() const {
		return x * x + y * y;
	}

	double dist() const {
		return sqrt(x * x + y * y);
	}

	double dot(const Point& B) const {// скалярное произведение
		return x * B.x + y * B.y;
	}

	double cross(const Point& B) const {// вектрное произведение
		return x * B.y - y * B.x;
	}

	bool operator==(const Point& B) const {
		return x == B.x && y == B.y;
	}

	bool operator!=(const Point& B) const {
		return !(*this == B);
	}

	bool operator==(const int& B) const {
		return x == B && y == B;
	}

	bool operator!=(const int& B) const {
		return !(*this == B);
	}

	friend std::istream& operator>>(std::istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p) {
		out << p.x << " " << p.y;
		return out;
	}

	void rotate(const Point& center, double rad) {
		double x_2 = center.x + cos(rad) * (x - center.x) - sin(rad) * (y - center.y);
		double y_2 = center.y + sin(rad) * (x - center.x) + cos(rad) * (y - center.y);
		x = x_2;
		y = y_2;
	}

	void scale(const Point& center, double coe) {
		x = (x - center.x) * coe + center.x;
		y = (y - center.y) * coe + center.y;
	}

	void reflect(const Point& center) {
		scale(center, -1);
	}

	void reflect(const Line& line);
};