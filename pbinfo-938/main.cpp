int suma(int v[] ,int n)
{
	if(n == 0)
		return 0;
	else
	{
		int s = suma(v , n - 1);
		s += v[n-1];
		return s;
	}
}