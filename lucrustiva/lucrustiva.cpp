bool echilibrat(string str)
{
	Stiva s;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (s.isEmpty())
				return false;

			char top = s.pop();
			if ((top == '(' && str[i] != ')') || (top == '[' && str[i] != ']') || (top == '{' && str[i] != '}'))
				return false;
		}
	}
	return s.isEmpty();
}

//l13-pana penultima