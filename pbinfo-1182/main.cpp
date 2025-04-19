void inserare(nod * & p)
{
	nod * t = p;
	while(t -> urm != NULL)
	{
		if(t -> urm -> info % 2 == 0)
		{
			nod * q = new nod;
			q -> info = 2 * t -> urm -> info;
			q -> urm = t -> urm;
			t -> urm = q;
			t = q; 
		}
		t = t -> urm;
	}
	if( p -> info % 2 == 0)
	{
		t = new nod;
		t -> info = 2 * p -> info;
		t -> urm = p;
		p = t;
	}
}