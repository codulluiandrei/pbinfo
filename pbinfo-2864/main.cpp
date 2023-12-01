#include<fstream>
using namespace std;
ifstream f("sotron.in");
ofstream g("sotron.out");
int main()
{
    long long P,N,M,R,C,nrp,nr,n1,n2,k,x;
    f>>P>>N>>M;
    if(P==1)
        g<<N*(N+1)/2<<endl;
    else
    {
        nr=2*N-1;
        x=nr;
        nrp=0;
        k=1;
        while( M<=nrp || M>nrp+x )
        {
           nrp+=x; x-=4; ++k;
        }
        n1=(k-1)*(nr+4-2*k)+1;
        n2=N+n1+1-2*k;
        if(M<=n2)
        {
          R=k+M-n1; C=k;
        }
        else
        {
          R=N+1-k; C=k+M-n2;
        }
        g<<R<<' '<<C<<endl;
    }
    return 0;
}
