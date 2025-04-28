#include <fstream>
using namespace std;
int v[130];
char v2[130];
int v3[40005];
char cod[40005];
int v4[40005];
int main()
{
    ifstream cin ("bifid.in");
    ofstream cout ("bifid.out");
    int c;
    cin>>c;
    if(c==1)
    {
        char s;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>s;
                v[s]=i*10+j;
                v2[i*10+j]=s;
            }
        }
        char c;
        int cnt=0;
        while(cin>>c)
        {
            cnt++;
            cod[cnt]=c;
        }
        int cnt1=0;
        for(int i=1;i<=cnt;i++)
        {
            cnt1++;
            v3[cnt1]=v[cod[i]]/10;
        }
        for(int i=1;i<=cnt;i++)
        {
            cnt1++;
            v3[cnt1]=v[cod[i]]%10;
        }
        for(int i=1;i<cnt1;i+=2)
        {
            cout<<v2[v3[i]*10+v3[i+1]];
        }
    }
    else
    {
        char s;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>s;
                v[s]=i*10+j;
                v2[i*10+j]=s;
            }
        }
        char c;
        int cnt=0,cnt1=0;
        while(cin>>c)
        {
            cnt++;
            cod[cnt]=c;
            cnt1++;
            v4[cnt1]=v[cod[cnt]]/10;
            cnt1++;
            v4[cnt1]=v[cod[cnt]]%10;
        }
        for(int i=1;i<=cnt;i++)
        {
            cout<<v2[v4[i]*10+v4[i+cnt]];
        }
    }
    return 0;
}