#include <iostream>
#include<memory>
using namespace std;



	/*unique_ptr<string> p = make_unique<string>("unique_ptr");
	unique_ptr<string> p1 = std::move(p);

	if (p != nullptr)
	{
		cout << "mutarea nu s a efectuat" << endl;
	}
	else
	{
		cout << "mutarea s a efectuat cu succes. Valoarea lui p1 este = " << *p1;
	}

	p1.release();

	if (p1 != nullptr)
	{
		cout << "Release-ul nu s-a efectuat " << endl;
	}
	else
	{
		cout << "Release-ul s-a efectuat" << endl;
	}
	string* pstr = new string("bla;");
	p1.reset(pstr);
	cout << "Noul p1 este " << *p1;*/

	/*prob 3
	shared_ptr<double> p = make_shared<double>(3.14) :
	shared_ptr<double> p2 = p;

	cout << "valoarea lui p" << *p << endl;

	cout << "valoarea lui p2" << *p2 << endl;

	cout << "use count" << p2.use_count() << endl;

	p.reset(new double(101.1));
	cout << "Valoarea lui p " << *p << endl;
	cout << "Valoarea lui p2 " << *p2 << endl;
	cout << "Use count = " << p2.use_count() << endl;
}
	*/

	/*
	p4
	class B;
class A
{
public:
	~A()
	{
		cout << "Destructorul din A\n";
	}

	shared_ptr<B> ptrB;
};

class B
{
public:
	~B()
	{
		cout << "Destructorul din B\n";
	}

	weak_ptr<A> ptrA;
};


int main()
{
	shared_ptr<A> a = make_shared<A>();
	shared_ptr<B> b = make_shared<B>();
	a->ptrB = b;
	b->ptrA = a;
}

p4:
class ResourceManager
{
public:
	ResourceManager(const string& file_name) : file(file_name)
	{
		if (f != nullptr)
		{
			if (f->is_open())
			{
				f->close();
			}
		}
		f = std::make_unique<std::ofstream>(file_name);
	}

	void writeToFile(const string& text)
	{
		if (f != nullptr)
		{
			if (!f->is_open())
			{
				f->open(file, std::ios::out);
			}
			*f << text;
		}
	}
~ResourceManager()
	{
		if (f && f->is_open())
		{
			f->close();
			cout << "Fisierul s-a inchis cu success"<<endl;
		}
	}

private:
	string file;
	std::unique_ptr<std::ofstream> f;
};


int main()
{
	ResourceManager rm("unique_ptr.txt");
	rm.writeToFile("Mesaj din programul cu unique ptr\n");
	return 0;
}

6
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape()
	{
		cout << "Destructorul din Shape" << endl;
	}
};

class Circle : public Shape
{
public:
	void draw()
	{
		cout << "Draw din Circle" << endl;
	}
	~Circle()
	{
		cout << "Destructorul din Circle" << endl;
	}
};
class Rectangle : public Shape
{
public:
	void draw()
	{
		cout << "Draw din Rectangle" << endl;
	}
	~Rectangle()
	{
		cout << "Destructorul din rectangle"<<endl;
	}
};
int main()
{
	// cu raw pointers
	std::vector<Shape*> vect_raw;

	vect_raw.push_back(new Circle());
	vect_raw.push_back(new Rectangle());

	for (const auto& el : vect_raw)
	{
		el->draw();
	}

	auto it = vect_raw.begin();
	while  (it != vect_raw.end())
	{
		delete* it;
		it = vect_raw.erase(it);
	}

	// cu unique_ptr
	std::vector<unique_ptr<Shape>> vect;

	vect.push_back(make_unique<Circle>());
	vect.push_back(make_unique<Rectangle>());

	for (const auto& el : vect)
	{
		el->draw();
	}
	return 0
*/



int main()
{



}


