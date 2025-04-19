void zero(int n, int v[])
{
	int pare[101], impare[101], k = 0, p = 0;
	for(int i = 1 ; i <= 2*n ; ++i)
		if(v[i]%2 == 0)
			pare[k ++ ] = v[i];
		else
			impare[p++] = v[i];
	k = p = 0;
	for(int i = 1 ; i <= 2*n ; ++i)
		if(i % 2 == 1)
			v[i] = impare[k++];
		else
			v[i] = pare[p++];
}