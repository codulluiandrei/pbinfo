#include <iostream>
#include <cmath>
using namespace std;
typedef int NrMare[5001];
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
void Afis(NrMare A)
{
    for(int i = A[0] ; i > 0 ; i --)
        cout << A[i];
}
void Produs(NrMare A , int n)
{
    int t =  0;
    for(int i = 1 ; i <= A[0] ; i ++)
    {
        int x = t + n * A[i];
        A[i] = x % 10;
        t = x / 10;
    }
    while(t)
        A[++A[0]] = t % 10, t /= 10;
}
int F[501];
int main()
{
    int n, k;
    cin >> n >> k;
    k --;
    n += k;
    for(int i = 1 ; i <= k ; i ++)
        F[i] = n - i + 1;
    for(int i = 1 ; i <= k ; i ++)
    {
        int x = i, d = 2, k = 1;
        while(x > 1)
        {
            if(x % d == 0)
            {
                if(F[k] % d == 0)
                    F[k] /= d, x /= d, k = 1;
                else
                    k ++;
            }
            else
                d ++;
        }
    }
    NrMare rez;
    rez[rez[0] = 1] = 1;
    for(int i = 1; i <= k ; i ++)
        Produs(rez , F[i]);
    Afis(rez);
    return 0;
}