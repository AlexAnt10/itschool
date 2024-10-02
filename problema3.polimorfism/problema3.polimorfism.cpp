#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Avion
{
	void setProd(string p)
	{
		prod = p;
	}
	void setModel(string m)
	{
		model = m;
	}
	string getProd() const
	{
		return prod;
	}

	string getModel() const
	{
		return model;
	}
private:
	string prod, model;
};
class AvionMilitar : public Avion
{
	void setUnitate(string u)
	{
		unitate = u;
	}
	string getUnitate() const
	{
		return unitate;
	}
private:
	string unitate;
};

class AvionLupta : public AvionMilitar
{
public:
	void setNumarRachete(int r)
	{
		numarRachete = r;
	}
	int getNumarRachete() const
	{
		return numarRachete;
	}
private:
	int numarRachete;
};

class AvionVanatoare : public AvionLupta
{
public:
	void setVmax(float v)
	{
		vmax = v;
	}
	float getVmax() const
	{
		return vmax;
	}
private:
	float vmax;
};
int main()
{
	AvionVanatoare av;
	av.setModel("F-16");
	av.setProd("USA");
	av.setUnitate("Deveselu");
	av.setNumarRachete(10);
	av.setVmax(1900);
	av.afisare();
}