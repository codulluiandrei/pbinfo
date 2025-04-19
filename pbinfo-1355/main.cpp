#include <fstream>
using namespace std;
int x[10], n, S, ex;
ifstream f("sirab.in");
ofstream g("sirab.out");
void scrie()
{
    ex=1;
    for(int i=1;i<=n;i++)
        g<<x[i]<<" ";
    g<<endl;
}
int valid(int k)
{
     int i;
     if(k==1) return 1;
     for(i=1;i<k;i++)
        if((x[i]+x[k])%(x[k]-x[i]))return 0;
     return 1;
}
void back(int k)
{
    if(k==n+1) scrie();
    else
    {
        for(x[k]=x[k-1]+1;x[k]<=S;x[k]++)
            if(valid(k)) back(k+1);
    }
}
int main()
{
    f>>S>>n;
    back(1);
    if(ex==0)g<<0<<endl;
    return 0;
}