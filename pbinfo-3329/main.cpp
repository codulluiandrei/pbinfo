#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
int F[26];
long long Fact(int n)
{
    long long R = 1;
    for(int i = 1 ; i <= n ; i ++)
        R *= i;
    return R;
}
int main()
{
    char s[201];
    cin >> s;
    assert(strlen(s) <= 20);
    for(int i = 0 ; s[i] ; i ++)
        F[s[i]-'a'] ++;
    int S = 0;
    for(int i = 0 ; i < 26 ; i ++)
        S += F[i];
    long long R = Fact(S);
    for(int i = 0 ; i < 26 ; i ++)
        R /= Fact(F[i]);
    cout << R;
    return 0;
}