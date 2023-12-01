void P(int x[], int n, int &mini, int &maxi, int &sum){
	if(n == 1)
		mini = maxi = sum = x[0];
	else
	{
		P(x , n - 1 , mini ,maxi, sum);
		sum += x[n-1];
		if(x[n-1] < mini)
			mini = x[n-1];
		if(x[n-1] > maxi)
			maxi = x[n-1];
	}
}
