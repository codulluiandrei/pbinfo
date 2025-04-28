int CifEgaleRec(int n , int k){
	if(n < 10)
	{
		if(n == k)
			return 1;
		else
			return 0;
	}
	else
	{
		if(n % 10 != k)
			return 0;
		else
			return CifEgaleRec(n / 10, k);
	}
}