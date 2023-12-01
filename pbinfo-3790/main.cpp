#include <iostream>
using namespace std;

int t[12], a[12], n;

int main()
{
    int i, s[4], cnt;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> t[i];

    /// generarea tuturor configuratiilor de 0,1,2,3 de lungime n
    cnt = 0;
    while (a[0] == 0)
    {
        /// calcul sume
        s[0] = s[1] = s[2] = s[3] = 0;
        for (i = 1; i <= n; i++)
            s[a[i]] += t[i];
        if (s[1] == s[2] && s[2] == s[3] && s[1] > 0)
            cnt++;

        /// urmatoarea configuratie
        for (i = n; a[i] == 3; i--)
            a[i] = 0;
        a[i]++;
    }
    cnt /= 6;
    cout << cnt << "\n";
    return 0;
}
