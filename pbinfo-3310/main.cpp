#include <fstream>
using namespace std;
char v[130];
int main()
{
    ifstream cin ("afin.in");
    ofstream cout ("afin.out");
    int a,b;
    char c;
    cin>>a>>b;
    for(char i='a';i<='z';i++)
    {
        int val=(i-'a');
        v[(int)(i)]=(char)((a*val+b)%26+'a');
    }
        while(cin>>c)
        {
            cout<<v[(int)(c)];
        }
    return 0;
}