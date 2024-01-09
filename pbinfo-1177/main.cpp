void sterge(nod * & p , nod * q)
{
	if(q == p)
	{
		p = p -> urm;
		delete q;
		return;
	}
	nod * t = p;
	while(t -> urm != NULL && t -> urm != q)
		t = t -> urm;
	if(t -> urm == q)
	{
		t -> urm = q -> urm;
		delete q;
	}
}