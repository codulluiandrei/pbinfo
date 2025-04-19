void afisare(nod * p)
{
	while(p != NULL)
	{
		cout << p -> info << " ";
		p = p -> urm;
	}
}