#include <fstream>
using namespace std;
int codif[130];
int main()
{
    ifstream cin("afin1.in");
    ofstream cout("afin1.out");
    int a,b,ok=0;
    cin>>a>>b;
    for(char c='a';c<='z';c++)
    {
        if(codif[codif[(a*(c-'a')+b)%26+'a']]!=0)
            ok=-1;
        codif[(a*(c-'a')+b)%26+'a']=c;
    }
    char ch;
    cin.get(ch);
    if(ok==-1)
        cout<<-1;
    else
    {
        while(cin.get(ch) && ch!='\n')
            cout<<(char)(codif[ch]);
    }
    return 0;
}