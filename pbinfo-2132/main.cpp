#include <iostream>
#include <cstring>
using namespace std;
char s[10001];
bool ap[150];
int nr[10000],Min;
int main()
{
    int i,L,dist=0,j,k,L_sb;
    cin>>s;
    L=strlen(s);
    for(i=0;i<L;i++)
        if (!ap[(int)s[i]])
        {
            ap[(int)s[i]]=true;
            dist++; ///cate litere distincte avem
        }
    Min=L;
    k=j=0;
    for (i=0;i<L;i++)
    {
        nr[(int)s[i]]++;
        if (nr[(int)s[i]]==1) k++;
        if (k==dist)
        {
            ///determin lungimea subsirului
            while (nr[(int)s[j]]>1)
            {
                if (nr[(int)s[j]]>1) nr[(int)s[j]]--;
                j++;
            }
            L_sb=i-j+1;
            if (Min>L_sb)
            {
                Min=L_sb;
            }
        }
    }
    cout<<Min<<'\n';
    return 0;
}