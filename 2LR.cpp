#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Point {

		int x;
		int y;

	public:

		Point(int aa, int bb) : x(aa), y(bb) {};

		friend float distance(Point*, Point*);
};

float distance(Point* a, Point* b)
{
	float dist = sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));
	return dist;
}

int main()
{
	setlocale(LC_ALL, "ru");

	float sum;
	Point** p;
	Point* t;
	int x;
	int y;
	int n;
	int j = 0;
	float max;

	cout << "Введите количество точек: ";
	cin >> n;
	
	if (n < 2)
	{
		return(-1);
	}

	p = new Point*[n+1];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите X и Y " << i + 1 << " точки: " << endl;
		cin >> x;
		cin >> y;
		p[j] = new Point(x, y);
		j++;
	}

	p[j] = NULL;

	for (int i = 0; p[i] != NULL; i++)
	{
		sum = 0.0;
		t = p[i];
		for (j = 0; p[j] != NULL; j++)
		{
			sum += distance(t, p[j]);
		}
		sum = sum / (n-1);

		if (i == 0)
		{
			max = sum;
		}

		if (sum > max)
		{
			max = sum;
		}
	}

	for (j = 0; p[j] != NULL; j++)
	{
		delete p[j];
	}
	delete [ ]p;

	cout << "Максимальное среднее расстояние: " << max << endl;

	return 0;
}