int sub(int n, int v[], int k)
{
	int s = 0 , cnt = 0;
	for(int i = 0 ; i < n && cnt < k ; i ++)
		if(v[i] % 2 == 1)
			s += v[i], cnt ++;
	if(cnt < k)
		return -1;
	return s;
}