#include <iostream>
#include <vector>
using namespace std;

int lungime_sir(const char n[], int i = 0)
{

    if (n[i] == '\0') {
        return i;
    }

    return lungime_sir(n, i + 1);
}

int main()
{
    const char sir[] = "It school";
    int lungime = lungime_sir(sir);
    cout << "Lungimea sirului este: " << lungime << endl;
    return 0;
}