void numar(int n , int k , int & x)
{
	int v[20] , m = 0;
	do{
		v[++ m] = n % 10;
		n /= 10;
	}
	while(n);
	for(int i = 1 ; i < m ; i ++)
		for(int j = i + 1 ; j <= m ; j++)
			if(v[i] < v[j])
			{
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	x = 0;
	for(int i = 1 ; i <= k ; i ++)
		x = 10 * x + v[i];
}