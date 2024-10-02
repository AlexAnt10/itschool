#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct angajat
{
	string nume;
	string prenume;
	int varsta;

	void afiseaza() const
	{
		cout << endl;
		cout << "Nume: " << nume << " Prenume: " << prenume << " varsta: " << varsta;
	}
};

bool comparare(const angajat& a, const angajat& b)
{
	return a.varsta < b.varsta;
}

int main()
{
	vector<angajat> angajati;
	int nr_angajati;
	int nr_angajati;
	for (int i = 0; i <  nr_angajati; ++i)
	{
		string nume, prenume;
		int varsta;
		cout << endl;
		cout << "Dati detaliile angajatului " << i << ":" << endl;
		cout << "Nume: ";
		cin >> nume;
		cout << endl;
		cout << "Prenume: ";
		cin >> prenume;
		cout << endl;
		cout << "Varsta: ";
		cin >> varsta;
		angajati.at(i).nume = nume;
		angajati[i].prenume = prenume;
		angajati[i].varsta = varsta;
		angajati.push_back({ "marinescu ", "ion", 12 });
	angajati.push_back({ "vlad", "ion", 99 });
	angajati.push_back({ "dan", "ion", 67 });
	angajati.push_back({ "alex", "ion", 88 });
	angajati.push_back({ "popescu", "ion", 44 });
	angajati.push_back({ "ionescu", "ion", 55 });

	for (const auto& el : angajati)
	{
		el.afiseaza();
	}

	std::sort(angajati.begin(), angajati.end(), comparare);

	for (const auto& el : angajati)
	{
		el.afiseaza();
	}
}
	