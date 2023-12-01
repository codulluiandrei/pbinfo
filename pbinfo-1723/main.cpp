//prof.Carmen Minca
#include <fstream>
using namespace std;

int main()
{   long long nt,p10=1,k=0,M,i,T=0, P,N,x;
    ifstream f("culegere.in");
    ofstream g("culegere.out");
    f>>P>>N;
    nt=P*(P+1)/2;
    x=nt;
    while(x)
    {
        k++; x/=10;
    }
    for(i=1;i<k;i++)
    {
        T=T+i*p10;
        p10*=10;
    }
    T=T*9+(nt-p10+1)*k;
    g<<T<<endl;
    long long probl=0;
    for(M=1;probl+M<N;M++)
        probl+=M;
    g<<M<<endl;
    return 0;
}