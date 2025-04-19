#include <fstream>
using namespace std;
ifstream f("lightbot.in");
ofstream g("lightbot.out");
int n, fr[200010],P[200010],np,cer;
int main()
{
    int a, b,l=0,maxim,nm,i;
    f>>cer>>n>>a;
    fr[a]++;maxim=1;nm=a;
    np=0;
    while (f>>b)
    {
        fr[b]++;
        if(fr[b]>maxim)
            {maxim=fr[b];nm=b;}
           else if(fr[b]==maxim&&b>nm) nm=b;
        if(l==0&&b-a==2)
            l=b-1;
          else if(b-a!=1)
                {P[++np]=l;l=0;}
        a=b;
    }
    P[++np]=l;
    if(cer==1) g<<np<<'\n';
    else if (cer==2) g<<nm<<'\n';
    else {for(i=1;i<np;i++)
            g<<P[i]<<' ';
          g<<P[np]<<'\n';}
    return 0;
}