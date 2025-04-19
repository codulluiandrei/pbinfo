#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> M;
int main()
{
    int n, i, suma, S, x;
    long long cnt;
    cin >> n >> S;
    cnt = suma = 0;
    M[0] = 1;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        suma += x;
        if (M.find(suma - S) != M.end())
            cnt += M[suma - S];
        M[suma]++;
    }
    cout << cnt << "\n";
    return 0;
}