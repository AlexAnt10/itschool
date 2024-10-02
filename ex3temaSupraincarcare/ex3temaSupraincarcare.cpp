#include <iostream>
#include<vector>
#include<conio.h>
using namespace std;

class counter
{
public:
    counter(int val  = 0) : i(val)
    {
        //this-> = i;
    }
    void afisare() const
    {
        cout << "i=" << i << endl;
    }
    counter& operator --()
    {
        --i;
        return *this; 
    }
    //post incrementare
    counter operator --(int)
    {
        counter temp = *this;
        (this-> i) = this-> i - 5;
        return temp;
    }
private:
    int i;
};

int main()
{
    counter c(100);
    --c;
    c--;
    c.afisare();
}

