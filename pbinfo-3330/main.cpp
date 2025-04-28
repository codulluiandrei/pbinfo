#include <iostream>
#include <cmath>
using namespace std;
typedef int NrMare[1001];
NrMare x[501], y[501], * A, * B;
void Atrib(NrMare A, int n)
{
    A[0] = 0;
    do
    {
        A[++A[0]] = n % 10;
        n /= 10;
    }
    while(n);
}
void Suma(NrMare A, NrMare B, NrMare S)
{
    int t = 0;
    S[0] = 0;
    for(int i =1 ; i <= max(A[0] , B[0]) ; i++)
    {
        int x = t + A[i] + B[i];
        S[++S[0]] = x % 10;
        t = x / 10;
    }
    while(t)
        S[++S[0]] = t % 10, t /= 10;
}
void Afis(NrMare A)
{
    for(int i = A[0] ; i > 0 ; i --)
        cout << A[i];
}
int main()
{
    A = x, B = y;
    int n, k;
    cin >> n >> k;
    Atrib(A[0], 0);
    for(int i = 1 ; i <= n ; i ++)
    {
        Atrib(B[0], 1);
        Atrib(B[i], 1);
        for(int j = 1; j < i ; j ++)
            Suma(A[j-1], A[j] , B[j]);
        swap(A,B);
    }
    Afis(A[k]);
    return 0;
}