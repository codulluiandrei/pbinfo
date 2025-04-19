void adaugareInainte(nod * & p , int x)
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
		q -> urm = p;
		p = q;
	}
}