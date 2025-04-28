#include <fstream>
using namespace std;
char v[27][27];
char v1[27][27];
int main()
{
    ifstream cin ("beaufort.in");
    ofstream cout ("beaufort.out");
    int cnt=0;
    for(char a='A';a<='Z';a++)
    {
        for(char b=a;b<='Z';b++)
        {
            cnt++;
            v[cnt][b-'A'+1]=a;
        }
        for(char b='A';b<a;b++)
        {
            cnt++;
            v[cnt][b-'A'+1]=a;
        }
        cnt=0;
    }
    string key;
    string cuv;
    cin>>key>>cuv;
    for(int i=0;i<cuv.size();i++)
        cout<<v[cuv[i]-'A'+1][(key[i%key.size()])-'A'+1];
    return 0;
}