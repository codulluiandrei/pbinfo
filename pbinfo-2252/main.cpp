#include <fstream>
#define Maxx 500001
using namespace std;
ifstream fin("profu.in");
ofstream fout("profu.out");
long long A[Maxx],k,sum,mx,trans,nw,n,i,st,dr,mij;
int main()
{
    fin>>n>>k;// pornim de pe considerentul ca valoarea cautata va fi intre maximul elementelor si suma lor
    for (i=1; i<=n; i++)
    {
        fin>>A[i];
        mx=max(A[i],mx);
        sum+=A[i];
    }
    st=mx;
    dr=sum;
    while (st<=dr)
    {
        trans=0;
        nw=0;
        mij=(st+dr)/2;
        for (i=1;i<=n;i++)
        {
            if (nw+A[i]>mij)
            {
                trans++;
                nw=A[i];
            }
            else
                nw+=A[i];
        }
        if (nw>0)
            trans++;
        if (trans>k)
            st=mij+1;
        else
            dr=mij-1;
    }
    fout<<st;
    return 0;
}