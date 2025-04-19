void sterge(nod * p , nod * q)
{
	if(q -> urm	== NULL)
		return ;
	nod * t = q -> urm;
	q -> urm = t -> urm;
	delete t;
}