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
void afisare(int A[], int n)
{
    if(n>0)
    {
        cout<<A[n]<<" ";
        afisare(A,n-1);
    }
}
int cifre_impare(int n)
{
    if(n<=9) if(n%2==1) return n;
             else return 0;
    else if(n%2==1) return cifre_impare(n/10)*10+n%10;
         else return cifre_impare(n/10);
}
void inlocuire(int A[], int n)
{
    if(n>0)
    {
        inlocuire(A,n-1);
        A[n]=cifre_impare(A[n]);
    }
}
int main()
{
    int n,A[1002];
    cin>>n;
    citire(A,n);
    inlocuire(A,n);
    afisare(A,n);
    return 0;
}