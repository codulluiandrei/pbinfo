void patrate(int n , int &x , int &y)
{
	x = y = 1;
	int d = 2;
	while(n > 1)
	{
		if(n % d == 0)
		{
			if(n % (1LL * d * d) == 0)
			{
				if(x == 1)
					x = d;
				else
					y *= d;
				n /= d * d;
			}
			else
			{
				x = y = 0;
				n = 1;
			}
		}
		else
			d ++;
		if(d * d > n)
			d = n;
	}
	if(x == y)
		x = y = 0;
}