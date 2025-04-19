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
    s = 0;
    for(int i = 0 ; i < n ; i ++)
        if(prim(x[i]))
            s += x[i];
}