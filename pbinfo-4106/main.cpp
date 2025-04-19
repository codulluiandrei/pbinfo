#include <fstream>
using namespace std;
ifstream fin("halfsort4.in");
ofstream fout("halfsort4.out");
int main()
{
    int A[1001],n;
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>A[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if((A[i]<0 && A[j]<0 && A[i]>A[j]) || (A[i]>0 && A[j]>0 && A[i]<A[j]))
            {
                int aux=A[i]; A[i]=A[j]; A[j]=aux;
            }
    for(int i=1;i<=n;i++)
        fout<<A[i]<<" ";
    return 0;
}