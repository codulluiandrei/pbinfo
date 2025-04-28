long long CountSumS(vector<int> &a, int s)
{
    int n = a.size();
    if (n <= 1) return 0;
    unordered_map<int, int> M;
    M.clear();
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[s - a[i]] > 0) cnt += M[s - a[i]];
        M[a[i]]++;
    }
    return cnt;
}