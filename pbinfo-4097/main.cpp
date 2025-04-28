/// Boca Alina Gabriela - Colegiul National de Informatica Tudor Vianu Bucuresti
#include <fstream>
#include<cmath>
using namespace std;
ifstream cin("circular.in");
ofstream cout("circular.out");
int a[26][26],v[26];
long long circular(string s)
{
    int cost=0,n;
    char j='A';
    n=s.size();
    for(int i=0; i<n; i++)
    {
        if(j<s[i])
        {
            if(s[i]-j<'Z'-s[i]+j-64)
                cost+=s[i]-j;
            else
                cost+='Z'-s[i]+j-64;
        }
        else
        {
            if(j-s[i]<'Z'-j+s[i]-64)
                cost+=j-s[i];
            else
                cost+='Z'-j+s[i]-64;
        }
        j=s[i];
    }
    return cost;
}
int main()
{
    int c;
    cin>>c;
    string p, t,rez;
    cin>>p>>t;
    if(c==1)
    {
        cout<<circular(p);
    }
    else
    {
        int i,j,k=0,y=1;
        string alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(i=0; i<26; i++)
        {
            if(alf[i]==t[k])
            {
                v[k]=i;
                k++;
            }
            for(j=0; j<26; j++)
                if(i<j)
                {
                    a[i][j]=min(abs(i-j), abs(26-j+i));
                }
                else
                {
                    a[i][j]=min(abs(i-j), abs(26-i+j));
                }
        }
        int nrtotal=1,costtotal=0,q;
        int x;
        for(j=0; j<alf.size(); j++)
            if(p[0]==alf[j])
            {
                k=j;
                break;
            }
        costtotal=min(k,26-k);
        rez.push_back(p[0]);
        for(i=1; i<p.size(); i++)
        {
            for(j=0; j<alf.size(); j++)
                if(p[i]==alf[j])
                {
                    q=j;
                    break;
                }
            int mincost=60,nr=0;
            for(j=0; j<t.size(); j++)
            {
                if (mincost>a[k][v[j]]+a[q][v[j]])
                {
                    mincost=a[k][v[j]]+a[q][v[j]];
                    nr=1;
                    x=v[j];
                }
                else if(a[k][v[j]]+a[q][v[j]]==mincost)
                {
                    nr++;
                    if(x>v[j])
                    {
                        x=v[j];
                    }
                }
            }
            rez.push_back(alf[x]);
            nrtotal*=(nr%666013);
            nrtotal=nrtotal%666013;
            costtotal+=mincost;
              rez.push_back(p[i]);
            k=q;
        }
        cout<<costtotal<<endl<<nrtotal<<endl;
        cout<<rez;
    }
    return 0;
}