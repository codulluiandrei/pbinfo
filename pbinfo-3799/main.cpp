vector<int> CountNum(vector<int> &a, int S)
{
    vector<int> b;
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n && a[i] <= S; i++)
    {
        S -= a[i];
        b.push_back(a[i]);
    }
    return b;
}