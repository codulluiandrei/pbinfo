#include <iostream>
using namespace std;
void citire(int A[], int &n)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
}
int oglindit(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n=n/10;
    }
    return r;
}
int cmmdc(int a, int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
void afisare(int A[], int n)
{
    for(int i=n;i>=1;i--)
        cout<<A[i]<<" ";
}
void inlocuire(int A[], int n)
{
    for(int i=1;i<=n;i++)
        A[i]=cmmdc(A[i],oglindit(A[i]));
}
int main()
{
    int A[1001],n;
    citire(A,n);
    inlocuire(A,n);
    afisare(A,n);
    return 0;
}