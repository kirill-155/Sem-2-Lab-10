#pragma once
#include <iostream>

class Line;

struct point
{
	double x = 0, y = 0;

	point() = default;

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	point(T x, T y) : x(x), y(y) {}

	point(const point& p) : x(p.x), y(p.y) {}

	point& operator=(const point& B) {
		x = B.x;
		y = B.y;
		return *this;
	}

	point operator+(const point& B) const {
		point res;
		res.x = x + B.x;
		res.y = y + B.y;
		return res;
	}

	point operator-(const point& B) const {
		point res;
		res.x = x - B.x;
		res.y = y - B.y;
		return res;
	}

	point operator*(double k) const {
		point res;
		res.x = x * k;
		res.y = y * k;
		return res;
	}

	point operator/(double k) const {
		point res;
		res.x = x / k;
		res.y = y / k;
		return res;
	}

	void line(const point& B, double& a, double& b, double& c) const {
		a = B.y - y, b = x - B.x, c = (-a) * x + (-b) * y;
	}

	double line(const point& B, const point& C) const {
		double a = B.y - y, b = x - B.x, c = (-a) * x + (-b) * y;
		return a * C.x + b * C.y + c;
	}

	double dist2() const {
		return x * x + y * y;
	}

	double dist() const {
		return sqrt(x * x + y * y);
	}

	double dot(const point& B) const {// скалярное произведение
		return x * B.x + y * B.y;
	}

	double cross(const point& B) const {// вектрное произведение
		return x * B.y - y * B.x;
	}

	bool operator==(const point& B) const {
		return x == B.x && y == B.y;
	}

	bool operator!=(const point& B) const {
		return !(*this == B);
	}

	bool operator==(const int& B) const {
		return x == B && y == B;
	}

	bool operator!=(const int& B) const {
		return !(*this == B);
	}

	friend std::istream& operator>>(std::istream& in, point& p) {
		in >> p.x >> p.y;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const point& p) {
		out << p.x << " " << p.y;
		return out;
	}

	void rotate(const point& center, double rad) {
		double x_2 = center.x + cos(rad) * (x - center.x) - sin(rad) * (y - center.y);
		double y_2 = center.y + sin(rad) * (x - center.x) + cos(rad) * (y - center.y);
		x = x_2;
		y = y_2;
	}

	void scale(const point& center, double coe) {
		x = (x - center.x) * coe + center.x;
		y = (y - center.y) * coe + center.y;
	}

	void reflect(const point& center) {
		scale(center, -1);
	}

	void reflect(const Line& line);
};