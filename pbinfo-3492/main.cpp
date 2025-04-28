#include <fstream>
#define NM 1000002
#include <set>
#include <cstring>
using namespace std;
ifstream f("palpal.in");
ofstream g("palpal.out");
int n,element,i,j,k,tip;
char s[NM];
set < int > par,impar;
int main()
{
    f.get(s,NM);
    n=strlen(s);
    for(i=0; i<n; i++)
    {
        impar.insert(i);
        if(i<n-1&&s[i]==s[i+1])
            par.insert(i);
    }
    f>>k;
    for(j=1; j<=k; j++)
    {
        if(impar.size()==0&&par.size()==0)
        {
            g<<0<<'\n';
            continue;
        }
        if(j==1) g<<n<<'\n';
        else if(j==2) g<<par.size()<<'\n';
        else
        {
            if(j%2==1)
            {
                for(auto it=impar.begin(); it!=impar.end();)
                {
                    if((*it-(j/2)<0)||(*it+(j/2)>=n))
                        it=impar.erase(it);
                    else if(s[*it-(j/2)]!=s[*it+(j/2)])
                        it=impar.erase(it);
                    else
                        it++;
                }
                g<<impar.size()<<'\n';
            }
            else
            {
                for(auto it=par.begin(); it!=par.end();)
                {
                    if((*it-((j-2)/2)<0)||(*it+(j/2))>=n)
                        it=par.erase(it);
                    else if(s[*it-(j-2)/2]!=s[*it+(j/2)])
                        it=par.erase(it);
                    else
                        it++;
                }
                g<<par.size()<<'\n';
            }
        }
    }
    return 0;
}