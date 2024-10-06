#include "Point.h"
#include <iostream>
#include <ctime>

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::SetPoint(int a, int b)
{
	x = a;
	y = b;
}
void Point::RandPoint()
{
	x = rand() % 10;
	y = rand() % 10;
}

int Point::GetX() const
{
	return x;
}
int Point::GetY() const
{
	return y;
}

Point Point::operator+(const Point& p)
{
	return Point(x + p.x, y + p.y);
}
Point Point::operator-(const Point& p)
{
	return Point(x - p.x, y - p.y);
}
Point Point::operator*(const Point& p)
{
	return Point(x * p.x, y * p.y);
}
Point Point::operator/(const Point& p)
{
	if (p.x == 0 || p.y == 0)
	{
		cout << "erorr";
		return *this;
	}
	return Point(x / p.x, y / p.y);
}

Point& Point::operator+=(const Point& p)
{
	this->x += p.x;
	this->y += p.y;
	return *this;
}
Point& Point::operator-=(const Point& p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}
Point& Point::operator/=(const Point& p)
{
	if (p.x == 0 || p.y == 0)
	{
		cout << "erorr";
		return *this;
	}
	x /= p.x;
	y /= p.y;
	return *this;
}
Point& Point::operator*=(const Point& p)
{
	x *= p.x;
	y *= p.y;
	return *this;
}
Point& Point::operator=(const Point& p)
{
	if (this != &p)
	{
		this->x = p.x;
		this->y = p.y;
	}
	return *this;
}

void Point::Print() const
{
	cout << "Point(" << x << ", " << y << ")" << endl;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "Point(" << p.GetX() << ", " << p.GetY() << ")";
	return os;
}