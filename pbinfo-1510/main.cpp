int cautare(int n, double X[], double v)
{
    for(int i = 0 ; i < n ; i ++)
        if(X[i] == v)
            return i;
    return -1;
}