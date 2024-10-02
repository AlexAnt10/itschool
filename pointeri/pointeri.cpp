#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <map>
#include <string.h> b 


using namespace std;

void change_by_reference(int& x)
{
    ++x;
}

void change_by_pointer(int* p)
{
    *p = 50;
}


int main()
{
    /*char* c1 = new char;
    char* c2 = new char;
    /**c1 = 'a';
    *c2 = 'b';
    char* char_array = new char[10];

    cout << "adresa lui c1" << c1 << endl;
    cout << "adresa lui c2" << c2 << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << (char_array + i)<< endl;
    }*/
    //char char_array[10];
    char* char_array = new char[12];
    for (int i = 0; i < 11; i++)
    {
        *(char_array + i) = 'a' + i;
    }
    *(char_array + 11) = '\0';
    cout << char_array << endl;
    //strcpy_s(char_array, "anaaremere");
    cout << char_array << endl;

    delete[] char_array;

}

