#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



struct elev
{
	string nume_prenume;
	string nume_matricol;
	int clasa;

	struct nota
	{
		string materie;
		float valoare;
		void afisare()
		{
			cout << endl;
			cout << "Materie: " << materie << " " << "nota :" << valoare << endl;
		}
	};
	nota note[5];

	void afisare()
	{
		cout << endl;
		cout << nume_prenume << " " << nume_matricol << " " << clasa << " "<< "Note: " << endl;

		for (int i = 0; i < 5; i++)
		{
			note[i].afisare();
		}
	}
	bool operator<(const elev& e)
	{
		return nume_prenume < e.nume_prenume;
	}
};

int main()
{
	set<elev> e;
	e.insert({ "Radu Pop", "NR126", 6, {{"mate", 9} ,{"romana", 10} ,{"engleza", 10},{"sport", 10},{"purtare", 9}} });
	e.insert({ "Vasile Ion", "124", 3, {{"mate", 4} ,{"romana", 5} ,{"engleza", 10},{"sport", 10},{"purtare", 8}} });
	e.insert({ "Daniela", "654", 8, {{"mate", 6} ,{"romana", 6} ,{"engleza", 10},{"sport", 10},{"purtare", 10}} });

}


