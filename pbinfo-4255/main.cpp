#include <iostream>
using namespace std;
void citire(int A[], int &n, int &k)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>A[i];
}
void afisare(int A[], int n)
{
    for(int i=1;i<=n;i++)
        cout<<A[i]<<" ";
}
void permutare(int A[], int st, int dr)
{
    int aux=A[st];
    for(int i=st;i<dr;i++)
        A[i]=A[i+1];
    A[dr]=aux;
}
int main()
{
    int A[1001],n,k,x;
    citire(A,n,k);
    x=n/k;
    for(int i=1;i<=n-x+1;i=i+x)
        permutare(A,i,i+x-1);
    afisare(A,n);
    return 0;
}