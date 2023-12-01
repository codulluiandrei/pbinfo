#include <fstream>
using namespace std;
ifstream fin("castel.in");
ofstream fout("castel.out");
int C,N,H,x,maxi,Ha,y,k;
long long suma=0;
int main()
{
    fin>>C>>N;
    H=0;
    while(H*(H+1)/2<=N)
        H++;
    H=H-1;
    if(C==1)
    {
        for(int i=1; i<=N; i++)
        {
            fin>>x;
            if(x>=1&& x<=9)
            k++;
        }
        fout<<k<<"\n";
    }
    else if (C==2)
    {
        for(int i=1; i<=H*(H+1)/2; i++)
            fin>>x;
        fout<<H<<" "<<x<<"\n";
    }
    else if(C==3)
    {
        Ha=H;
        for(int i=1; i<=(Ha+1); i++)
        {
            fin>>x;
            for(int j=2; j<=H; j++)
            {
                fin>>y;
                suma=suma+x+y;
                x=y;
            }
            H--;
        }
        fout<<Ha*(Ha-1)/2<<" "<<suma<<"\n";
    }
    return 0;
}
