#include <iostream>
using namespace std;

float div(float a, float b)
{
    if (b == 0)
        throw "impartire la zero imposibila";
    return a / b;
}

void calculate(float a, float b)
{
    try
    {
        float res = div(a, b);
        cout << "Rezultatul este =" << res << endl;
    } 
    catch (const char* e)
    {
        cout << "exceptia a fost prinsa: " << e << endl;
        throw; //re-arunca exceptia
    }
}

int main()
{
    float a = 100;
    float b = 0;
    try {
        calculate(a, b);
    }
    catch (const char* e) 
    {
        cout << "exceptie aruncata in functia calculate" << e << endl;
    }
}

