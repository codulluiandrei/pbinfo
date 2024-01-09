void sterge(nod * & p)
{
	nod * t = p , * q;
	while(t -> urm != NULL)
		if( t -> urm -> info % 2 == 0)
		{
			q = t -> urm;
			t -> urm = q -> urm;
			delete q;
		}
		else
			t = t -> urm;
	if(p -> info % 2 == 0)
	{
		t = p;
		p = p -> urm;
		delete t;
	}
}