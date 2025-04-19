int suma(int *v, int n, int i, int j)
{
	if(n == 0)
      	return 0;
  	else
      	if(n <i || n > j)
      		return v[n] + suma(v, n-1, i,j);
      	else
      		return suma(v, n-1, i,j);
}