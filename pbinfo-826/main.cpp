int cifminpar(int n)
{
	if(n < 10)
		if(n % 2 == 0)
			return n;
		else
			return -1;
	else
	{
		int x = cifminpar(n / 10);
		if(n % 2 == 1)
			return x;
		else
			if(x == -1)
				return n % 10;
			else
			{
				if(x < n % 10)
					return x;
				else
					return n % 10;
			}
	}
}