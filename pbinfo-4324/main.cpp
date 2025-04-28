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
        afisare(A,n-1);
        cout<<A[n]<<" ";
    }
}
int numar_cifre(int n)
{
    if(n<=9) return 1;
    else return 1+numar_cifre(n/10);
}
int prima_cifra(int n)
{
    if(n<=9) return n;
    else return prima_cifra(n/10);
}
void inlocuire(int A[], int n)
{
    if(n>0)
    {
        inlocuire(A,n-1);
        A[n]=numar_cifre(A[n])*prima_cifra(A[n]);
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