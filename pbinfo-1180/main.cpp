void inserare(nod * & p, nod * q, int x)
{
	if(p == q)
	{
		nod * t = new nod;
		t -> info = x;
		t -> urm = p;
		p = t;
		return;
	}
	nod * t = p;
	while(t -> urm != q)
		t = t -> urm;
	t -> urm = new nod;
	t -> urm -> urm = q;
	t -> urm -> info = x;
}