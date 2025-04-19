#include <fstream>
using namespace std;
ifstream fin("caroiaj.in");
ofstream fout("caroiaj.out");
char a[501][501], s[250001];
int n, i, j, lg, lgmx, poz, nc, k, x, y;
int main()
{
    fin>>n; ///fin.get();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            fin>>a[i][j];
        ///fin.get();
    }
    nc=n/2+n%2;
    k=0;
    for(int t=1;t<=nc;t++)
    {
        ///1
        x=t;
        for(int i=t; i<= n-t+1; i++)
            s[k++]=a[x][i];
        ///2
        y=n-t+1;
        for(int i=t+1;i<=n-t+1;i++)
            s[k++]=a[i][y];
        ///3
        x=n-t+1;
        for(int i=n-t; i>=t; i--)
            s[k++]=a[x][i];
        ///4
        y=t;
        for(int i=n-t;i>=t+1;i--)
            s[k++]=a[i][y];
    }
    ///fout<<s<<endl;
    for(int i=0;i<k;i++)
    {
        ///cazul I, cand secventa simetrica are 1 element in mijloc
        int st, dr;
        st=i-1, dr=i+1;lg=1;
        while(st>=0 && dr<k && s[st]==s[dr])
        {
            st--, dr++ ;
            lg+=2;
        }
        if(lg>=lgmx)
        {
            lgmx=lg;
            poz=st+1;
        }
        ///cazul II, cand secventa simetrica are 2 elemente in mijloc
        if(s[i]==s[i+1] && i+1<k)
        {
        st=i-1;dr=i+2;lg=2;
        while(st>=0 && dr<k && s[st]==s[dr])
        {
            st--, dr++ ;
            lg+=2;
        }
        if(lg>=lgmx)
        {
            lgmx=lg;
            poz=st+1;
        }
        }
    }
    //fout<<lgmx<<endl;
    for(int i=poz;i<poz+lgmx;i++)
        fout<<s[i];
    fout<<'\n';
    fout.close();
    return 0;
}