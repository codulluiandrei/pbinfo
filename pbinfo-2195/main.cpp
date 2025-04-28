# include <bits/stdc++.h>
using namespace std;
ifstream f("sumpow2.in");
ofstream g("sumpow2.out");
char a[20], b[20];
int A[20], B[20];
int main()
{
    f >> a >> b;
    int la = strlen(a), lb = strlen(b);
    for(int i=0; i<la; ++i)
        A[ a[i] - 'a' ] = 1;
    for(int i=0; i<lb; ++i)
        B[ b[i] - 'a' ] = 1;
    int t = 0;
    for(int i=0; i < 17; ++i){
        int x = A[i] + B[i] + t;
        if (x % 2 ) g << (char) ('a' + i);
        t = x / 2;
    }
    g << '\n';
    return 0;
}