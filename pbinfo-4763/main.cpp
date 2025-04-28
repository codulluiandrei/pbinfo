#include <bits/stdc++.h>
using namespace std;
int main()
{
    int lungimiEgale;
    unsigned n;
    char cuv[102];
    cin >> cuv;
    n = strlen(cuv);
    lungimiEgale = 1;
    while (cin >> cuv)
    {
        cin >> cuv;
        if (strlen(cuv) != n)
            lungimiEgale = 0;
    }
    if (lungimiEgale == 1) cout << "DA " << n;
    else cout << "NU";
    return 0;
}