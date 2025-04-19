void num(int n, int v[])
{
	int x = v[0];
	for(int i = 0 ; i < n ; i ++ )
		if(v[i] <= x)
			v[i] = 0;
}