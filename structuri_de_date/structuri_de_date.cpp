#include <iostream>
using namespace std;
#define MAX 5

class Stiva
{
private:
	int arr[MAX];
	int top;
public:
	Stiva()
	{
		top = -1;
	}

	void push(int elem)
	{
			cout << "Elementul " << elem << " a fost adaugat in stiva" << endl;
	}
	int pop()
	{
		if (top == -1)
		{
			cout << "Stiva este goala" << endl;
			return -1;
		}
		else
		{
			int temp = arr[top];
			arr[top--] = 0;
			return temp;
		}
	}

	int peek()
	{
		if (top == -1)
		{
			cout << "Stiva este goala" << endl;
			return -1;
		}
		else
		{
			return arr[top];
		}
	}
	bool isEmpty()
	{
		return (top < 0);
	}

	bool isFull()
	{
		return (top >= (MAX - 1));
	}

	void afisare()
	{
		for (int i = top; i >= 0; --i)
		{
			cout << arr[i] << endl;
		}
	}
};
int main()
{
	Stiva s;
	cout << "Este goala stiva? " << s.isEmpty() << endl;;
	s.push(22);
	s.push(12);
	s.push(99);
	s.push(40);
	s.push(1);
	// nu se adauga
	s.push(4);
	s.afisare();
	cout << "Este plina stiva? " << s.isFull() << endl;
	int temp = s.pop();
	cout << "Elementul eliminat este: " << temp << endl;
	s.afisare();
	s.pop();
	s.pop();
	cout << endl;
	s.afisare();
	s.pop();
	s.pop();
	// stiva este goala
	s.pop();
}
