int numarare(nod * p)
{
	int cnt = 0;
	if(! p )
		return 0;
	while(p -> urm != NULL)
	{
		if(p -> info == p -> urm -> info)
			cnt ++;
		p = p -> urm;
	}
	return cnt;
}