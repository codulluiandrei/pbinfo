int multiplu(int * a , int n , int k)
{
	if(n == 0)
		return 0;
	else
	{
		int cnt = multiplu(a , n - 1 , k);
		if(a[n-1] % k == 0 && a[n-1] % 10 == k)
			cnt ++;
		return cnt;
	}
}