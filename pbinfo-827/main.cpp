int cifmaxpar(int n)
{
	if(n < 10)
		if(n % 2 == 0)
			return n;
		else
			return -1;
	else
	{
		int x = cifmaxpar(n / 10);
		if(n % 2 == 1)
			return x;
		else // -1 este mai mic decat o cifra para, nu trebuie tratat special
			if(x > n % 10)
				return x;
			else
				return n % 10;
	}
}