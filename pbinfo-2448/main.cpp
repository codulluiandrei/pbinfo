#include <fstream>
using namespace std;
ifstream f("patrate3.in");
ofstream g("patrate3.out");
int main()
{
    int N,C,M,T,K,nr=0;
    f>>C;
    if(C==1)
    {
        f>>M;
        K=8*M;
        g<<K<<endl;
    }
    else
    {
        f>>N;
        T=0;nr=0;
        while(8*(T+1)<=N-nr)
            {
                ++T; K=8*T; nr=nr+K;
            }
        if(N>nr)
        {
            ++T;
        }
        g<<T<<endl;
    }
    return 0;
}