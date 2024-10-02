#include <iostream>
using namespace std;


struct Nod {
    int valoare;
    Nod* urmator;
};


    int lungimeLista(Nod* cap) {
        int lungime = 0;
        Nod* curent = cap;
        while (curent != nullptr) {
            lungime++;
            curent = curent->urmator;
        }
        return lungime;
    }



int main() {
    
    Nod* nod1 = new Nod;
    nod1->valoare = 10;
    nod1->urmator = nullptr;

    Nod* nod2 = new Nod;
    nod2->valoare = 15;
    nod2->urmator = nullptr;
    
    Nod* nod3 = new Nod;
    nod3->valoare = 40;
    nod3->urmator = nullptr;

    nod1->urmator = nod2;
    nod2->urmator = nod3;

    
    int lungime = lungimeLista(nod1);
    cout << "Lungimea listei este: " << lungime << endl;

 
    delete nod1;
    delete nod2;
    delete nod3;
    

    return 0;
}



