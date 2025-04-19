#include <fstream>
using namespace std;
int v[130];
char v2[130];
int main()
{
    ifstream cin ("bacon.in");
    ofstream cout ("bacon.out");
    int cer;
    cin>>cer;
    char ch;
    cin.get(ch);
    if(cer==1)
    {
        while(cin.get(ch) && ch!='\n')
        {
            int val=ch-'A';
            string l="";
            for(int i=1;i<=5;i++)
            {
                if(val%2==0)
                    l=l+'A';
                else
                    l=l+'B';
                val/=2;
            }
            for(int i=4;i>=0;i--)
                cout<<l[i];
        }
    }
    else
    {
        char c;
        int ok=0,val=0;
        while(cin.get(c) && c!='\n')
        {
            if(ok!=5)
            {
                if(c=='A')
                    val=val*2;
                else if(c=='B')
                    val=val*2+1;
                ok++;
            }
            else
            {
                cout<<(char)('A'+val);
                ok=1;
                if(c=='A')
                    val=0;
                else
                    val=1;
            }
        }
        cout<<(char)('A'+val);
    }
    return 0;
}