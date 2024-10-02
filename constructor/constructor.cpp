#include <iostream>

using namespace std;

class Point
{
public:

	// c-tor default
	Point()
	{
		std::cout << "Constructor default params" << endl;
		this->x = x;
		this->y = y;
	}

	// c-tor parametrizat
	Point(int x, int y)
	{
		std::cout << "Constructor" << endl;
		this->x = x;
		this->y = y;
	}

	// copy constructor
	Point(const Point& p)
	{
		cout << "Copy constructor" << endl;
		this->x = p.x;
		this->y = p.y;
	}
	void display() const
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

private:
	int x, y;
};
int main()
{
	Point p(3, 5), p1(p);
	p.display();
	p1.display();

}

