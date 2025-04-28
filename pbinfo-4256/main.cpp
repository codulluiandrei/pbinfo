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
    for(int i=st,j=dr;i<j;i++,j--)
        swap(A[i],A[j]);
}
int main()
{
    int A[1001],n,k;
    citire(A,n,k);
    for(int i=1;i<=n-k+1;i=i+k)
        permutare(A,i,i+k-1);
    afisare(A,n);
    return 0;
}