#include <bits/stdc++.h>
using namespace std;
int st[20], S, sume[20];
int sol[1000001], n;
void Afisare(int top)
{
    int x = 0;
    for (int i = 1; i <= top; i++)
        x = x * 10 + st[i];
    sol[++n] = x;
}
int Valid(int top)
{
    sume[top] = sume[top - 1] + st[top];
    if (sume[top] > S) return 0;
    for (int i = 1; i < top; i++)
        if (st[i] == st[top]) return 0;
    return 1;
}
void Back()
{
    int cand, top;
    top = 1;
    st[top] = 0;
    while (top > 0)
    {
        cand = 0;
        while (!cand && st[top] < 9)
        {
            st[top]++;
            cand = Valid(top);
        }
        if (!cand) top--;
        else
        {
            if (sume[top] == S) Afisare(top);
            st[++top] = -1;
        }
    }
}
void PrintSol()
{
    sort(sol + 1, sol + n + 1);
    for (int i = 1; i <= n; i++)
        cout << sol[i] << "\n";
}
int main()
{
    cin >> S;
    if (S > 45)
    {
        cout << "-1\n";
        return 0;
    }
    Back();
    PrintSol();
    return 0;
}