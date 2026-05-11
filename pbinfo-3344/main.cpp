#include <iostream>
using namespace std;
typedef int MatFib[2][2];
const int MOD = 666013;
void Produs(MatFib A , MatFib B, MatFib P)
{
    P[0][0] = (1LL * A[0][0] * B[0][0] + 1LL * A[0][1] * B[1][0]) % MOD;
    P[0][1] = (1LL * A[0][0] * B[0][1] + 1LL * A[0][1] * B[1][1]) % MOD;
    P[1][0] = (1LL * A[1][0] * B[0][0] + 1LL * A[1][1] * B[1][0]) % MOD;
    P[1][1] = (1LL * A[1][0] * B[0][1] + 1LL * A[1][1] * B[1][1]) % MOD;
}
void Atrib(MatFib D ,MatFib S)
{
    D[0][0] = S[0][0];
    D[0][1] = S[0][1];
    D[1][0] = S[1][0];
    D[1][1] = S[1][1];
}
int Fibo(int n)
{
    MatFib A = {{1,1},{1,0}}, B , R = {{1,0},{0,1}};
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            Produs(R , A, B);
            Atrib(R, B);
        }
        Produs(A, A, B);
        Atrib(A , B);
        n /= 2;
    }
    return R[0][1];
}
int main()
{
    int n;
    cin >> n;
    cout << Fibo(n);
    return 0;
}