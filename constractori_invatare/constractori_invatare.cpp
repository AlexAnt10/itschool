#include <iostream>
#include <string>

using namespace std;

class point
{
public:
	point(int x = 5, int y = 5)
	{
		cout << "Constructor default";
		x = x;
		y = y;

	}
	void display() const
	{
		 
	}
private:
	float x, y;
};
int main()
{
	point p(2, 3);
}


