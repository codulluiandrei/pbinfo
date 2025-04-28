int SecvSumS(vector<int> &a, int s)
{
    int suma, i, n, len;
    unordered_map<int, int> M;
    n = a.size();
    M[0] = 0;
    len = n + 1;
    suma = 0;
    for(int i = 0; i < n; i++)
    {
        suma += a[i];
        if(M.find(suma - s) != M.end())
            len = min(len, i - M[suma - s] + 1);
        M[suma] = i + 1;
    }
    if (len == n + 1) len = -1;
    return len;
}