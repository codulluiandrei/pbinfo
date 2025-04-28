#include <iostream>
#define M 1000000007
using namespace std;
long long n,p,i,f;
int main()
{
    cin >> n;
    if(n % 2 == 1){
        p = 2;
        f = 2;
        for(i = 1; i < n-1; i = i + 2){
           f = f + (i<<2) + 6;
           if(f >= M)
           f = f - f / M * M; 
           p = (p * f) % M;
        }
    }
    else{
        p = 2;
        f = 2;
        for(i = 1; i < n-2; i = i + 2){
           f = f + (i<<2) + 6;
           if(f >= M)
           f = f - f / M * M;
           p = (p * f) % M;
        }
        p = (p *(n+1)) % M;
    }
    p = (p * (n+1) - 1 + M) % M;
    cout << p;
    return 0;
}