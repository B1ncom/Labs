#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Point
{

		float x;
		float y;
		Point(float aa, float bb) : x(aa), y(bb) {};

	public:

		Point() { x = y = 0.0; }

		float getx() { return x; }
		float gety() { return y; }

		static Point Polar(float, float, float, float);

};

class offset
{
	float x;
	float y;

	public:

		offset(float aa)
		{
			x = aa / sqrt(2);
			y = -(aa / sqrt(2));
		}

		float getX() { return x; }
		float getY() { return y; }


};

Point Point::Polar(float R, float F, float offx, float offy)
{
	Point p(offx - R * sin(F), offy - R * cos(F));
	return p;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	float edge = 1.0;
	cout << "Введите значение стороны: " << endl;
	cin >> edge;

	float n;
	offset offs(0.0);
	cout << "Введите смещение: " << endl;
	cin >> n;
	offs = offset(n);

	float angle = 0.0;
	float pi = acos(-1);
	float radius = edge / (sqrt(2 * (1 - cos((2 * pi) / 3))));
	Point vertex[3];

	int i = 0;
	while (i < 3)
	{
		vertex[i] = Point::Polar(radius, angle, offs.getX(), offs.getY());
		angle += 2 * (pi / 3);
		i++;
	}

	while (i < 6)
	{
		cout << "Точка номер " << i - 2 << "  Координата X: " << vertex[i - 3].getx() << "  Координата Y: " << vertex[i - 3].gety() << endl;
		i++;
	}

	return 0;
}