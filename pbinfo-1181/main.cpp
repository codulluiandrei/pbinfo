void inserare(nod * & p)
{
	nod * t = p;
	while(t != NULL)
	{
		if(t -> info % 2 == 0)
		{
			nod * q = new nod;
			q -> info = 2 * t -> info;
			q -> urm = t -> urm;
			t -> urm = q;
			t = q; 
		}
		t = t -> urm;
	}
}