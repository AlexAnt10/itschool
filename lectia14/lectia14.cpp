#include <iostream>
#include<string>

using namespace std;

class clock
{
public: 
    int h, m, s;
    clock(int h, int m, int s) : h(h), m(m), s(s) {}

    void setTime(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void displayTime()
    {
        cout << h << ":" << m << ":" << s;
    }

    string getTime()
    {
        string time = std::to.string(h) + ":" + std::to.string(m) + ":" + std::to.string(s);
        return time;
    }
};

int main()
{
    clock c(12, 59, 59);
    cout << c.getTime << endl;
    c.displayTime();
}


