#include <fstream>
#include <algorithm>
using namespace std;
char v[5];
string v2[55];
int main()
{
    ifstream cin ("cifre_romane.in");
    ofstream cout ("cifre_romane.out");
    int cnt=0;
    char c;
    while(cin>>c)
    {
        cnt++;
        v[cnt]=c;
    }
    if(cnt==1)
    {
        v[4]=v[1];
        v[1]=0;
    }
    else if(cnt==2)
    {
        v[4]=v[2];
        v[3]=v[1];
    }
    else if(cnt==3)
    {
        v[4]=v[3];
        v[3]=v[2];
        v[2]=v[1];
    }
    for(int i=4-cnt+1;i<=4;i++)
    {
        if(i==1)
        {
            if(v[i]=='1')
                cout<<"M";
            if(v[i]=='2')
                cout<<"MM";
            if(v[i]=='3')
                cout<<"MMM";
        }
        else if(i==2)
        {
            if(v[i]=='9')
                cout<<"CM";
            else if(v[i]=='4')
                cout<<"CD";
            else
            {
                int val=(int)(v[i]-'0');
                if(val>=5)
                    cout<<"D";
                val%=5;
                for(int j=1;j<=val;j++)
                    cout<<"C";
            }
        }
        else if(i==3)
        {
            if(v[i]=='9')
                cout<<"XC";
            else if(v[i]=='4')
                cout<<"XL";
            else
            {
                int val=(int)(v[i]-'0');
                if(val>=5)
                    cout<<"L";
                val%=5;
                for(int j=1;j<=val;j++)
                    cout<<"X";
            }
        }
        else if(i==4)
        {
            if(v[i]=='9')
                cout<<"IX";
            else if(v[i]=='4')
                cout<<"IV";
            else
            {
                int val=(int)(v[i]-'0');
                if(val>=5)
                    cout<<"V";
                val%=5;
                for(int j=1;j<=val;j++)
                    cout<<"I";
            }
        }
    }
    return 0;
}