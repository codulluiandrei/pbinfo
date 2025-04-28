// Sursa cu numere Stirling de speta a doua - prof. Chesca Ciprian
// H(n) = S(n,1)1! + S(n,2)2! + ... + S(n,n-1)(n-1)! + S(n,n)n!
#include <fstream>
#define M 666013
#define nmax 5001
using namespace std;
long long n,H=0,a[nmax+1],b[nmax+1],f=1;
ifstream fin("100m.in");
ofstream fout("100m.out");
int main()
{
    int i,j;
    fin>>n;
    a[0]=1;b[0]=1;
    for(i=1;i<n;i++)
        {
        for(j=1;j<=i;j++)
            b[j]=((j+1)*a[j]+a[j-1])%M;
        for(j=0;j<=i;j++)
            a[j]=b[j];
        }
    for(i=1;i<=n;i++)
        {
        H=(H+b[i-1]*f)%M;
        f=f*(i+1)%M;
        }
    fout<<H<<"\n";
    fin.close();
    fout.close();
    return 0;
}