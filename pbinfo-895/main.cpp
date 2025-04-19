int permutare(int * a , int n)
{
	int v[105];
	for(int i = 1 ; i <= n ; i ++)
		v[i] = 0;
	for(int i = 0 ; i < n; i ++)
		if(a[i] < 1 || a[i] > n || a[i] == i + 1)
			return 0;
		else
			v[a[i]] ++;
	for(int i = 1 ; i <= n ; i ++)
		if(v[i] != 1)
			return 0;
	return 1;
}