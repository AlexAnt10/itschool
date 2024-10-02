#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point 
{
public:
    //c-tor default
   /* Point(int x = 5, int y = 5)
    {
        cout << "construcotr default" << endl;
        this->x = x;
        this->y = y;
    }*/

    //c-tor parametrizat
    /*Point(int x, int y = 5)
    {
        cout << "construcotr " << endl;
        this->x = x;
        this->y = y;
    }*/

    Point(const Point& p)
    {
        cout << "copy const" << endl;
        this->x = p.x;
        this->y = p.y;
    }

    void display() const
    {
        cout << "x =" << x << endl;
        cout << "y =" << y << endl;
    }

private:
    float x, y;

};


int main()
{
    Point p(3, 5), p1(p);
    //p1 = p;
    p.display();
    p1.display();
}


