#include<iostream>
#include "MyMatrix.h"
#include "Point.h"
using namespace std;

ostream& operator<<(ostream& os, const Point& p)
{
	os << "Point(" << p.GetX() << ", " << p.GetY() << ")";
	return os;
}

// Создать класс для работы с матрицами.
// Предусмотреть, как минимум, 
// функции для сложения матриц, 
// умножения матриц, 
// транспонирования матриц, 
// 
// присваивания матриц друг другу(конструктор копирования), 
// установка и получение произвольного элемента матрицы(доступ через индексы).

// конструктор копирования
// установка и получение произвольного элемента матрицы(доступ через индексы).


int main()
{
	srand(time(0));

	MyMatrix<Point> m1(2, 3);
	MyMatrix<Point> m2(2, 3);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Point p1, p2;
			p1.RandPoint();
			p2.RandPoint();
			m1.SetEl(i, j, p1);
			m2.SetEl(i, j, p2);
		}
	}

	cout << "M1: " << endl;
	m1.Print();

	cout << "M2: " << endl;
	m2.Print();

	MyMatrix<Point> sum = m1.Sum(m2);
	cout << "Sum: " << endl;
	sum.Print();

	MyMatrix<Point> tM = sum.Transpose();
	cout << "T:  " << endl;
	tM.Print();

	/*MyMatrix<Point> m1(2, 3);
	MyMatrix<Point> m2(3, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Point p1;
			p1.RandPoint();
			m1.SetEl(i, j, p1);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Point p2;
			p2.RandPoint();
			m2.SetEl(i, j, p2);
		}
	}

	cout << "M1: " << endl;
	m1.Print();

	cout << "M2: " << endl;
	m2.Print();

	MyMatrix<Point> mul = m1.Mul(m2);
	cout << "Mul: " << endl;
	mul.Print();*/





	/*MyMatrix<int> m1(2, 3);
	m1.Input();
	m1.Print();
	MyMatrix<int> m2(2, 3);
	m2.Input();
	m2.Print();

	MyMatrix<int> m3 = m1.Sum(m2);
	m3.Print();*/




	/*Point a;
	a.RandPoint();
	a.Print();*/

	//MyMatrix<double> m(3, 3);
	//m.Input();
	//m.Print();

	////cout << endl << m.GetEl(0, 0) << endl << endl;

	//MyMatrix<double> obj2 = m.Transpose();
	//obj2.Print();

	//MyMatrix<int> m1(3, 3);
	//m1.Input();
	//m1.Print();

	/*MyMatrix<double> m(3, 3);
	m.Input();
	m.Print();

	cout << endl;*/

	/*cout << endl << "min el: " << m.Min() << endl;
	cout << endl << "max el: " << m.Max() << endl;*/

	//cout << endl << m.GetEl(0, 0) << endl << endl;

	/*MyMatrix<double> obj2 = m.Transpose();
	obj2.Print();

	MyMatrix<int> m1(3, 3);
	m1.Input();
	m1.Print();*/

	// транспонирование
	/*MyMatrix obj1(5, 2);
	obj1.Input();
	obj1.Print();
	cout << endl;
	MyMatrix obj2 = obj1.Transpose();
	obj2.Print();*/

	// умн
	/*MyMatrix obj1(2, 2);
	obj1.Input();
	obj1.Print();
	cout << endl;

	MyMatrix obj2(2, 2);
	obj2.Input();
	obj2.Print();
	cout << endl;

	MyMatrix obj3 = obj1.Mul(obj2);
	obj3.Print();*/

	// сумма
	/*MyMatrix obj1(3, 2);
	obj1.Input();
	obj1.Print();
	cout << endl;

	MyMatrix obj2(3, 2);
	obj2.Input();
	obj2.Print();
	cout << endl;

	MyMatrix obj3 = obj1.Sum(obj2);
	obj3.Print();*/

	return 0;
}