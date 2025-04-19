int NrMinMaxAp(vector<int> &a)
{
    unordered_map<int, int> M;
    int nrMaxAparitii = 0;
    int val = -1;
    for (int x : a)
    {
        M[x]++;
        if (nrMaxAparitii < M[x])
        {
            nrMaxAparitii = M[x];
            val = x;
        }
        else if (nrMaxAparitii == M[x])
            val = min(val, x);
    }
    return val;
}