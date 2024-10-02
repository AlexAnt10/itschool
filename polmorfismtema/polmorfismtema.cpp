#include <iostream>
#include <vector>
using namespace std;
#define PI 3.14
class Shape
{
	friend void printTotalArea(std::vector<Shape*>& v);
public:
	virtual float area() = 0;
};

class Rectangle : public Shape
{
public:
	Rectangle(int width, int height)
	{
		w = width;
		h = height;
	}

	float area()
	{
		return w * h;
	}
private:
	int w, h;
};

class Circle : public Shape
{
public:
	Circle(float raza)
	{
		r = raza;
	}
	float area()
	{
		return PI * r * r;
	}
private:
	float r;
};
void printTotalArea(std::vector<Shape*>& v)
{
	float suma = 0;
	for (const auto& el : v)
	{
		float temp = el->area();
		cout << "Aria temporara = " << temp << endl;
		suma += temp;
	}

	cout << "Aria totala este: " << suma << endl;
}


int main()
{
	vector<Shape*> v;
	Shape* s1 = new Circle(3);
	Shape* s2 = new Rectangle(2, 3);
	Shape* s3 = new Rectangle(2, 5);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	printTotalArea(v);
}