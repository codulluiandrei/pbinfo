void factorial(int n ,int & f)
{
	if(n == 0)
		f = 1;
	else
	{
		int g;
		factorial(n - 1 , g);
		f = g * n;
	}
}