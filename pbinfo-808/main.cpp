void sub(int n, int v[], int x)
{
	int cnt = 0;
	for(int i = n -1 ; i >= cnt ; )
		if(v[i] == x)
		{
			cnt ++;
			for(int j = i ; j > 0 ; j --)
				v[j] = v[j-1];
		}
		else
			i --;
	for(int i = 0 ; i < cnt ; i ++ )
		v[i] = x;
}