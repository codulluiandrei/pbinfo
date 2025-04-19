int numarare(nod * p)
{
	int cnt = 0;
	while(p != NULL)
	{
		cnt ++;
		p = p -> urm;
	}
	return cnt;
}