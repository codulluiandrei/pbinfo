#include <bits/stdc++.h>
using namespace std;
char a[11][7];
int d[11], n, st[11], viz[26];
void Citire()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = strlen(a[i]);
        sort(a[i], a[i] + d[i]);
    }
}
void Afisare()
{
    for (int i = 1; i <= n; i++)
        cout << a[i][st[i]];
    cout << "\n";
    exit(0);
}
void Back(int top)
{
    if (top == n + 1) Afisare();
    else for (int i = 0; i < d[top]; i++)
    {
        int j = a[top][i] - 'a';
        if (viz[j] == 0)
        {
            viz[j] = 1;
            st[top] = i;
            Back(top + 1);
            viz[j] = 0;
        }
    }
}
int main()
{
    Citire();
    Back(1);
	return 0;
}