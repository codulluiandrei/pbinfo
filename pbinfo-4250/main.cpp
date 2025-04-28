#include <iostream>
using namespace std;
void citire(int A[], int &n)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
}
int suma_div(int n)
{
    int s=0;
    for(int d=1;d*d<=n;d++)
        if(n%d==0)
        {
            s=s+d;
            if(d*d!=n) s=s+n/d;
        }
    return s;
}
int nr_div(int n)
{
    int c=0;
    for(int d=1;d*d<=n;d++)
        if(n%d==0)
        {
            c++;
            if(d*d!=n) c++;
        }
    return c;
}
void afisare(int A[], int n)
{
    for(int i=n;i>=1;i--)
        cout<<A[i]<<" ";
}
void inlocuire(int A[], int n)
{
    for(int i=1;i<=n;i++)
        A[i]=suma_div(A[i])*nr_div(A[i]);
}
int main()
{
    int A[1001],n;
    citire(A,n);
    inlocuire(A,n);
    afisare(A,n);
    return 0;
}