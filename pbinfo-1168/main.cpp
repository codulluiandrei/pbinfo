void adaugare(nod * & p , int x)
{
	nod * q = new nod;
	q -> info = x;
	q -> urm = NULL;
	if(p == NULL)
	{
		p = q;
	}
	else
	{
		nod * t = p;
		while(t -> urm != NULL)
			t = t -> urm;
		t -> urm = q;
	}
}