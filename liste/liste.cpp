#include <iostream>
#include <vector>
using namespace std;

struct Nod
{
	int data;
	Nod* urm;

	Nod(int val)
	{
		data = val;
		urm = nullptr;
	}
};

void afisare(Nod* head)
{
	if (head == nullptr)
		cout << "Lista este vida\n";
	while (head != nullptr)
	{
		cout << "Elementul are valoarea " << head->data << endl;
		head = head->urm;
	}
}
Nod* insertBefore(Nod* head, int val)
{
	Nod* nou = new Nod(val);
	nou->urm = head;

	return nou;
}

void insertAfterNode(Nod* prev, int val)
{
	if (prev == nullptr)
	{
		cout << "Nodul este invalid";
		return;
	}

	Nod* nou = new Nod(val);
	nou->urm = prev->urm;
	prev->urm = nou;
}
Nod* insertAtPosition(Nod* head, int pos, int val)
{
	if (pos == 0)
	{
		head = insertBefore(head, val);
		return head;
	}

	Nod* temp = head;
	for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
	{
		temp = temp->urm;
	}

	//int i = 0;
	//while (temp != nullptr && i < pos - 1)
	//{
	//	++i;
	//	temp = temp->urm;
	//}

	if (temp != nullptr)
	{
		Nod* nou = new Nod(val);
		nou->urm = temp->urm;
		temp->urm = nou;
	}
	return head;
}

Nod* deleteAtFront(Nod* head)
{
	if (head == nullptr)
	{
		cout << "este goala";
		return nullptr;
	}
	Nod* temp = head;
	head = head->urm;

	delete temp;
	return head;
}

void deleteAtEnd(Nod* head)
{
	if (head == nullptr)
	{
		cout << "lista este invalida";
		return;
	}

	if (head->urm == nullptr)//lisat arre doar un element
	{
		delete head;
		return nullptr;
	}

	Nod* temp = head;
	for (temp; temp->urm->urm != nullptr; temp = temp->urm);

	delete temp->urm;
	temp->urm = nullptr;
	return head;
}

Nod* deleteAtPosition(Nod* head, int pos)
{
	if (head == nullptr && pos < 0)
	{
		cout << "lista invalida;";
	}
	if (pos == 0)
	{
		return deleteAtFront(head);
	}
	Nod* temp = head;
	for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
	{
		temp = temp->urm;
	}

	Nod* todelete = temp->urm;
	temp->urm = temp->urm->urm;

	delete todelete;
	return head;
}

bool searchIter(Nod* head, int val)
{
	Nod* curent = head;
	for (curent; curnet != nullptr; curent = curent->urm)
	{
		if (curent->data == val)
			return true;
	}
	return false;
}

bool searchRecursive(Nod* head, int val)
{
	if (head == nullptr)
		return false;

	if (head-> data == val)
		return trued;

}

int main()
{
	Nod* head = nullptr;
	head = new Nod(10);


	Nod* temp1 = new Nod(15);
	head->urm = temp1; // head->temp1 temp12 temp2

	Nod* temp12 = new Nod(100);
	temp1->urm = temp12;


	Nod* temp2 = new Nod(20);
	temp12->urm = temp2;

	head = insertBefore(head, 55);

	insertAfterNode(temp12, 40);
	head = insertAtPosition(head, 1, 999);

	head = insertAtEnd(head, 89);

    afisare(head);

	head = deleteAtFront(head);
	head = deleteAtPosition(head, 0);
	

    afisare(head);
}