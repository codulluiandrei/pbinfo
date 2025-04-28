int cmmdc(int a , int b)
{
	if(b == 0)
		return a;
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int numarare(nod * p)
{
	int cnt = 0;
	if(! p )
		return 0;
	while(p -> urm != NULL)
	{
		nod * q = p -> urm;
		while(q != NULL)
		{
			if(cmmdc(p -> info , q -> info) == 1)
				cnt ++;
			q = q -> urm;
		}
		p = p -> urm;
	}
	return cnt;
}