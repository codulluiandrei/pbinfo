void inserare(nod * p, nod * q, int x)
{
	nod * t = new nod;
	t -> info = x;
	t -> urm = q -> urm;
	q -> urm = t;
}