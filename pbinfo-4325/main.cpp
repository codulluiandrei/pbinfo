#include <iostream>
using namespace std;
void citire(int A[], int n)
{
    if(n>0)
    {
        citire(A,n-1);
        cin>>A[n];
    }
}
int cmmdc(int a, int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
int suma_sim(int A[], int st, int dr)
{
    if(st>dr) return 0;
    else if(cmmdc(A[st],A[dr])==1) return suma_sim(A,st+1,dr-1)+A[st]+A[dr];
         else return suma_sim(A,st+1,dr-1);
}
int main()
{
    int A[1002],n;
    cin>>n;
    citire(A,n);
    cout<<suma_sim(A,1,n);
    return 0;
}