void afisvec(int v[] , int n)
{
	if(n > 0)
	{
		cout << v[n-1] << " ";
		afisvec( v , n - 1);
	}
}