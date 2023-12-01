void ordonare(int  a[] , int n , int st , int dr)
{
	if(n>st)
    {
    	if(n - 1<= dr)
        {
        	int pmax = n - 1;
          	for(int i = st ; i < n - 1 ; i ++)
              	if(a[i] > a[pmax])
              		pmax = i;
            int aux = a[pmax];
          	a[pmax] = a[n - 1];
          	a[n - 1] = aux;
        }
      	ordonare(a,n-1,st,dr);
    }
}