#include <iostream>
using namespace std;
int prime[40], n, a[40], S;
int t[101]; /// pentru ciur
int sume[40]; /// sume partiale in stiva
int sol[40], k; /// retinem solutia cu numar maxim de numere prime
int nrSolutii;
void Ciur(int M)
{
    int i, j;
    for (i = 3; i * i <= M; i += 2)
        if (t[i] == 0)
            for (j = i * i; j <= M; j = j + 2 * i)
                t[j] = 1;
    n = 1;
    prime[1] = 2;
    for (i = 3; i <= M; i += 2)
        if (t[i] == 0) prime[++n] = i;
}
void Solutie(int top)
{
    nrSolutii++;
    if (top > k)
    {
        k = top;
        for (int i = 1; i <= top; i++)
            sol[i] = prime[a[i]];
    }
}
int Valid(int top)
{
    sume[top] = sume[top - 1] + prime[a[top]];
    if (sume[top] > S) return 0;
    return 1;
}
void Back()
{
    int cand, top;
    top = 1;
    a[top] = 0;
    while (top > 0)
    {
        cand = 0;
        while (!cand && a[top] < n)
        {
            a[top]++;
            cand = Valid(top);
        }
        if (!cand) top--;
        else if (sume[top] == S) Solutie(top);
        else
        {
            top++;
            a[top] = a[top - 1];
        }
    }
}
void Afisare()
{
    cout << nrSolutii << "\n";
    for (int i = 1; i <= k; i++)
        cout << sol[i] << " ";
    cout << "\n";
}
int main()
{
    Ciur(100);
    cin >> S;
    Back();
    Afisare();
    return 0;
}