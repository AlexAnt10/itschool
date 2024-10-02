#include <iostream>
#include <string>
using namespace std;

class shape
{
public:
    shape() = default;
    void  draw()
    {
        cout << "draw from shape\n";
    }
};

class circle : public shape
{
public:
    circle() = default;
    void draw()
    {
        cout << "draw from circle\n";
    }
};

class rectangle : public shape
{
public:
    rectangle() = default;
    void draw()
    {
        cout << "draw from rectangle\n";
    }
};


int main()
{
    shape* s = new rectangle;

    s->draw();
    delete s;
}
