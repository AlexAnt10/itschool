#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ResourceHandler {
private:
    int* array;
    size_t size;
    fstream file;

public:
    // Constructor
    ResourceHandler(const string& filename, size_t arraySize) : size(arraySize) {
        array = new int[size];  // Alocare memorie pentru array
        file.open(filename, ios::out | ios::in | ios::trunc);  // Deschide fișierul

        if (!file.is_open()) {
            cerr << "Eroare la deschiderea fișierului!" << endl;
            delete[] array;  // Eliberează memoria în caz de eroare la deschiderea fișierului
            array = nullptr;
        }
    }

    // Destructor
    ~ResourceHandler() {
        if (array) {
            delete[] array;  // Eliberează memoria alocată pentru array
        }
        if (file.is_open()) {
            file.close();  // Închide fișierul
        }
    }

    // Metodă pentru a seta valorile din array
    void setArrayValue(size_t index, int value) {
        if (index < size) {
            array[index] = value;
        }
        else {
            cerr << "Indexul este în afara limitelor array-ului!" << endl;
        }
    }

    // Metodă pentru a scrie valori în fișier
    void writeToFile(const string& data) {
        if (file.is_open()) {
            file << data << endl;
        }
        else {
            cerr << "Fișierul nu este deschis!" << endl;
        }
    }
};

int main() {
    // Exemplu de utilizare a clasei ResourceHandler
    ResourceHandler handler("output.txt", 10);

    // Setează valori în array
    for (size_t i = 0; i < 10; ++i) {
        handler.setArrayValue(i, i * 10);
    }

    // Scrie date în fișier
    handler.writeToFile("Aceasta este o linie în fișier.");

    return 0;
}
