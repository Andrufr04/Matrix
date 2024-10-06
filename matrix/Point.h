#include <iostream>

using namespace std;
class Point
{
    int x;
    int y;
public:
    Point();
    Point(int a, int b);

    void SetPoint(int a, int b);
    void RandPoint();

    int GetX() const;
    int GetY() const;

    Point operator+(const Point& p);
    Point operator-(const Point& p);
    Point operator*(const Point& p);
    Point operator/(const Point& p);

    Point& operator+=(const Point& p);
    Point& operator-=(const Point& p);
    Point& operator/=(const Point& p);
    Point& operator*=(const Point& p);
    Point& operator=(const Point& p);

    friend ostream& operator<<(ostream& os, const Point& p);
    void Print() const;
};


