void splitList(Nod* head, Nod** prima, Nod** adoua)
{
	int k = 0;
	Nod* temp = head;
	while (temp != nullptr)
	{
		k++;
		temp = temp->urm;
	}

	int i;
	if (k % 2 == 0)
	{
		i = k / 2;
	}
	else
	{
		i = k / 2 + 1;
	}

	temp = head;
	k = 1;
	while (k < i)
	{
		temp = temp->urm;
		k++;
	}
	*prima = head;
	if (temp)
	{
		*adoua = temp->urm;
	}
	temp->urm = nullptr;
}