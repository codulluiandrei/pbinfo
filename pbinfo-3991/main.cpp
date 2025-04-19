#include <bits/stdc++.h>
using namespace std;
char s[1003];
int NrMinOp()
{
    int i, cnt = 0, nrOp = 0;
    int n = strlen(s);
    if (n % 2 == 1) return -1;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0)
        {
            nrOp++;
            cnt = 1;
        }
    }
    nrOp += cnt / 2;
    return nrOp;
}
int main()
{
    cin >> s;
    cout << NrMinOp();
    return 0;
}