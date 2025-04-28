#include <iostream>
using namespace std;
int main()
{
    unsigned long long nv=1,nt=1, ni=1,p5,p;
    int n,c,i;
    cin>>c>>n;
    if(n==1) nv=nt=5,ni=0;
    else
    {
       p=1;p5=1;
       i=1;
       while(i<=n)
       {
           i++;
           p5*=5;
           p*=10;
       }
       nv=4*p5/5;
       nt=p5;
       ni=p-p/10-nv-nt;
    }
    if(c==1) cout<<nv;
    if(c==2) cout<<nt;
    if(c==3) cout<<ni;
    return 0;
}