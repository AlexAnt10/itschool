#include <iostream>
#include<vector>
#include<conio.h>
using namespace std;

class Complex
{
	float rl, img;
public:
	Complex(float real, float imaginar) : rl(real), img(imaginar) {}

	Complex operator +(const Complex& obj)
	{
		this->rl += obj.rl;
		this->img += obj.img;
		return *this;
	}

	bool operator <(const Complex& obj)
	{
		if (rl < obj.rl)
		{
			std::cout << "Numarul " << rl << " este mai mic decat " << obj.rl << std::endl;
			return true;
		}
		std::cout << "Numarul " << rl << " este mai mare sau egal decat " << obj.rl << std::endl;
		return false;
	}

	void afisare() const
	{
		std::cout << "nr real: " << rl << "nr imaginar: " << img << std::endl;
	}

};

int main()
{
	Complex nr(1.23, 2.09);
	Complex n0(2.3, 4.6);
	nr + n0;
	nr.afisare();
	n0.afisare();

	nr < n0;


}





//Crea?i o clas? Complex care s? reprezinte numere complexe ?i supraînc?rca?i operatorii + ?i <. Implementa?i un program care s? adune dou? numere complexe ?i s? afi?eze rezultatul.
