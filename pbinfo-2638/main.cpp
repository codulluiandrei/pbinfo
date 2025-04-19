#include <bits/stdc++.h>
using namespace std;
char s[60];
long long st[60];
int top;
inline int Cifra(char ch)
{
    return ('0' <= ch && ch <= '9');
}
int main()
{
    int i, semn = 1, op = 0;
    long long suma, x;
    cin >> s;
    for (i = 0; s[i]; )
        if (!Cifra(s[i]))
        {
            if (s[i] == '-') semn = -1;
            else semn = 1;
            if (s[i] == '*') op = 1;
            else op = 0;
            i++;
        }
        else
        {
            x = 0;
            while ('0' <= s[i] && s[i] <= '9')
            {
                x = x * 10 + s[i] - '0';
                i++;
            }
            x *= semn;
            if (op == 1) st[top] = st[top] * x;
            else st[++top] = x;
            semn = 1;
            op = 0;
        }
    suma = 0;
    for (i = 1; i <= top; i++)
        suma += st[i];
    cout << suma << "\n";
    return 0;
}