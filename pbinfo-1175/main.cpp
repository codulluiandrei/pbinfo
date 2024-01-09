int suma(nod * p)
{
	int s = 0;
	if( p == NULL )
		return 0;
	if( p -> urm == NULL )
		return 0;
	while(p -> urm -> urm != NULL)
	{
		if( p -> info % 2 == 0 && p -> urm -> info % 2 == 1 && p -> urm -> urm -> info % 2 == 0)
			s += p -> urm -> info;
		p = p -> urm;
	}
	return s;
}