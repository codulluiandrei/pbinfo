#include <fstream>
using namespace std;
int a[100];
int main()
{   int n,i,k;
    ifstream fin("n311.in");
    ofstream fout("n311.out");
    fin>>n;
    k=0;
    while (n>1)
        if (n==2)
        {
            n=n-1;
            a[++k]=1;
        }
        else
        if (n%3==0)
        {
            n=n/3;
            a[++k]=3;
        }
        else
            if ((n+1)%3==0)
            {
                n=(n+1)/3;
                a[++k]=-1;
                a[++k]=3;
            }
            else
            {
                n=(n-1)/3;
                a[++k]=1;
                a[++k]=3;
            }
    for (i=k;i>0;i--)
        fout<<a[i]<<" ";
    fout<<"\n";
    fin.close();
    fout.close();
    return 0;
}