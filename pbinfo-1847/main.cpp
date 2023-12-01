bool prim(int x)
{
    if(x < 2)
        return false;
    if(x % 2 ==0 && x > 2)
        return false;
    for(int d = 3 ; d * d <= x ; d += 2)
        if(x % d == 0)
            return false;
    return true;
}

void P(int x[], int n, int & s){
    if(n == 0)
      	s = 0;
  	else
    {
      	P(x , n - 1, s);
    	if(prim(x[n-1]))
           	s += x[n-1];
    }
}