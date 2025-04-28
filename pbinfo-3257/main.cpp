#include <fstream>
using namespace std;
string v2[4000];
char v[5];
int main ()
{
    ifstream cin ("cifre_romane1.in");
    ofstream cout ("cifre_romane1.out");
    for(int d=1;d<=3999;d++)
    {
        int cnt=4,cj=d,cnt1=0;
        while(cj>0)
        {
            cnt1++;
            v[cnt]=(char)(cj%10+48);
            cnt--;
            cj/=10;
        }
        string s="";
        for(int i=4-cnt1+1;i<=4;i++)
        {
            if(i==1)
            {
                if(v[i]=='1')
                    s=s+"M";
                if(v[i]=='2')
                    s=s+"MM";
                if(v[i]=='3')
                    s=s+"MMM";
            }
            else if(i==2)
            {
                if(v[i]=='9')
                    s=s+"CM";
                else if(v[i]=='4')
                    s=s+"CD";
                else
                {
                    int val=(int)(v[i]-'0');
                    if(val>=5)
                        s=s+"D";
                    val%=5;
                    for(int j=1;j<=val;j++)
                        s=s+"C";
                }
            }
            else if(i==3)
            {
                if(v[i]=='9')
                    s=s+"XC";
                else if(v[i]=='4')
                    s=s+"XL";
                else
                {
                    int val=(int)(v[i]-'0');
                    if(val>=5)
                        s=s+"L";
                    val%=5;
                    for(int j=1;j<=val;j++)
                        s=s+"X";
                }
            }
            else if(i==4)
            {
                if(v[i]=='9')
                    s=s+"IX";
                else if(v[i]=='4')
                    s=s+"IV";
                else
                {
                    int val=(int)(v[i]-'0');
                    if(val>=5)
                        s=s+"V";
                    val%=5;
                    for(int j=1;j<=val;j++)
                        s=s+"I";
                }
            }
        }
        v2[d]=s;
    }
    string s2;
    cin>>s2;
    int ok=0;
    for(int i=1;i<=3999;i++)
    {
        if(v2[i]==s2)
        {
            ok=1;
            cout<<i;
        }
    }
    if(ok==0)
        cout<<"Numar invalid";
    return 0;
}