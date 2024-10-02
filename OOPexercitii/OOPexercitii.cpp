#include <iostream>
#include<vector>
using namespace std;

class Clock
{
public:
    int h, m, s;
    Clock(int h, int m , int s) : h(h), m(m), s(s) {}

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

    void tick()
    {
        if (s == 59)
        {
            s = 0;
            if (m == 59)
            {
                m = 0;
                if (h == 23)
                {
                    h = 0;
                }
                else
                {
                    h++;
                }
            }
            else
            {
                m++;
            }
        }
        else
        {
            s++;
        }
    }
};

int main()
{
    Clock c(12, 59, 59);

    c.displayTime();

     Clock* c1 = new Clock(11, 33, 59);
     c.tick();

     c1->displayTime() ;
     delete c1;

     vector<Clock> my_clocks;
     my_clocks.push_back(c);
     my_clocks.at(0).displayTime();

     
}

