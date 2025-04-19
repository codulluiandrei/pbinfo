int cautare(int n, double X[], double v)
{
    if(n == 0)
        return -1;
    else
        if(X[n-1] == v)
            return n - 1;
        else
            return cautare(n-1, X, v);
}