#include <bits/stdc++.h>
#define nmax 1000005
using namespace std;
char a[nmax];
int k;
char s[nmax];
int main()
{
    int i, top;
    char x;
    cin >> k;
    cin >> (s + 1);
    a[0] = 'A';
    top = 0;
    for (i = 1; s[i] && k > 0; ++i)
    {
        x = s[i];
        while (k > 0 && a[top] > x)
        {
            k--;
            top--;
        }
        a[++top] = x;
    }
    for( ; s[i]; i++)
        a[++top] = s[i];
    while (k > 0)
    {
        k--;
        top--;
    }
    a[top + 1] = 0;
    cout << (a + 1) << "\n";
    return 0;
}