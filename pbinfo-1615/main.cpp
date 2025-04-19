#include <fstream>
using namespace std;
int x[30001];
ifstream f("axyz.in");
ofstream g("axyz.out");
int main()
{
    int N,A,B,C,NB,Z,i,k,j, poz, t,cer;
    f>>cer>>A>>N;
    for(i=1; i<=N; i++)
        f>>x[i];
///cerinta 1) - problema are solutie pentru toate testele propuse
    if(cer==1)
    {
        k=N-1;
        while(k>0 && x[k]<=x[k+1])k--;
        poz=N;
        while(poz>k && x[poz]>=x[k])poz--;
        swap(x[k],x[poz]);
        for(i=1; i<=k; i++)g<<x[i];
        for(i=N; i>k; i--)g<<x[i];
    g<<'\n';
    }
    else ///cerinta 2
    if(A<100){
        B=A%10;
        A=A/10;
        Z=0;
        NB=0;
        for(i=N; i>=1; i--)
            if(x[i]==B)NB++;
            else if(x[i]==A)Z+=NB;
        g<<Z<<'\n';
    }
    else
        { int i,C,NC=0,NBC=0,Z=0;
          C=A%10; A/=10; B=A%10; A/=10;
          for (i=N; i>=1;i--)
            if(x[i]==C)NC++;
            else if(x[i]==B)NBC+=NC;
                else if(x[i]==A)Z+=NBC;
          g<<Z<<'\n';
        }
    return 0;
}