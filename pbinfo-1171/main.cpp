void stergePrimul(nod * & p)
{
	nod * q = p;
	p = p -> urm;
	delete q;
}