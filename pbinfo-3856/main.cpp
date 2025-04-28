#include <fstream>
using namespace std;
int main()
{
    ifstream cin("scytale.in");
    ofstream cout("scytale.out");
    string s;
    int cer,n,lin=0,col=0;
    cin>>cer>>s>>n;
    char f[n+5][s.size()+5];
    for(int i=0;i<n;i++)
        for(int j=0;j<s.size();j++)
            f[i][j]=0;
    if(cer==1)
    {
        for(int i=0;i<s.size();i++)
        {
            f[lin][col]=s[i];
            col+=n;
            if(col>=s.size())
                lin++,col=lin;
        }
        lin=col=0;
        for(int i=0;i<s.size();i++)
        {
            cout<<f[lin][col];
            if(lin<n-1)
                lin++,col++;
            else
                lin=0,col++;
        }
    }
    else
    {
        lin=col=0;
        for(int i=0;i<s.size();i++)
        {
            f[lin][col]=s[i];
            if(lin<n-1)
                lin++,col++;
            else
                lin=0,col++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<s.size();j++)
                if(f[i][j]>='A' && f[i][j]<='Z')
                    cout<<f[i][j];
    }
    return 0;
}