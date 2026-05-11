#include<cstdio>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;
int p2,lg,mask,i,j,k,p,q,n,sol(int);
vector<int>s[2],cod;
char a[50010];
int main()
{
    freopen("subsecvente.in","r",stdin);
    freopen("subsecvente.out","w",stdout);
    int n;  scanf("%d\n", &n);
    s[0].push_back(0);s[1].push_back(0);cod.push_back(0);
    s[0].push_back(0);s[1].push_back(0);cod.push_back(0);
    for(p2=1,n=1;scanf("%s",a+1)+1;p2<<=1)
    {
        lg=strlen(a+1);mask|=p2;
        for(i=1;i<=lg;i++)
        {
            j=min(i+59,lg);
            for(k=i,p=1;k<=j;k++)
            {
                q=a[k]-'a';
                if(!s[q][p])
                {s[0].push_back(0);s[1].push_back(0);cod.push_back(0);s[q][p]=++n;}
                p=s[q][p];cod[p]|=p2;
            }
        }
    }
    cod[1]=mask;
    printf("%d\n",sol(1)-1);
    return 0;
}
int sol(int nod)
{
    int sa,sb;
    if(!nod||cod[nod]!=mask)return 0;
    sa=sol(s[0][nod]);
    sb=sol(s[1][nod]);
    return max(sa,sb)+1;
}