#pragma once

class Point {
public:

	Point(int x, int y) : x(x), y(y) { }

	template<int c>
	int wsp() const { if (c == 0) return x; else return y; }

	template<typename T>
	static T min(const T& x, const T& y) { return (x < y) ? x: y; }

	template<typename T>
	static T max(const T& x, const T& y) { return (x < y) ? y: x; }

	bool operator<(const Point& toCmp) const {
		if (this->x == toCmp.x) return (this->y < toCmp.y) ? true: false;
		else return (this->x < toCmp.x) ? true: false;
	}


private:
	int x;
	int y;
};
