int numarare(int * v , int n)
{
    if(n < 2)
        return 0;
    else
        return numarare(v, n - 1) + (v[n-1] == v[n-2]);
}