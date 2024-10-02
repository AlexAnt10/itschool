#include <iostream>
#include<string>
#include<vector>
using namespace std;

/*class copac
{   
private:
    float inaltime;
    float numar_crengi;
    bool fructifer;
public:
     

    void setfructifer(bool f)
    {
        fructifer = f;
    }

    bool getfructifer() const
    {
        return fructifer;
    }

    void afiseaza_atribute()
    {
        cout << "inaltime: " << inaltime << endl << "numar_crengi: " << numar_crengi << endl << "fructifer: " << fructifer << endl;
    }
};


int main()
{
    copac c1;
    c1.afiseaza_atribute();
    c1.setfructifer(true);
    cout <<"Fructifer  " << c1.getfructifer() << endl;
    c1.afiseaza_atribute();
}*/

//problema class clock

class Clock
{
public:
    int h, m, s;
    Clock(int h, int m, int s) : h(h), m(m), s(s) {}

    void setTime(int h, int m, int s)
        {
        this->h = h;
        this->m = m;
        this->s = s;
        }
    void displayTime()
    {
        cout << h << ":" << m << ":" << s << endl;
    }

    string getTime() const
    {
        string time = std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);
        return time;
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
    Clock c(22, 59, 59);
    cout << c.getTime() << endl;
    c.displayTime();

    Clock* c1 = new  Clock(23, 59, 59);
    c.tick();
    cout << c1->getTime()<< endl;
    c1->displayTime();
    delete c1;

    vector<Clock> my_clocks;
    my_clocks.push_back(c);
    my_clocks.at(0).displayTime();
}

