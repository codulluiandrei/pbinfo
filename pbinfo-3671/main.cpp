#include <fstream>
using namespace std;
char v[28][28];
int main()
{
    ifstream cin ("autokey.in");
    ofstream cout ("autokey.out");
    int cnt=0;
    for(char a='A';a<='Z';a++)
    {
        for(char b=a;b<='Z';b++)
        {
            cnt++;
            v[a-'A'+1][cnt]=b;
        }
        for(char b='A';b<a;b++)
        {
            cnt++;
            v[a-'A'+1][cnt]=b;
        }
        cnt=0;
    }
    string cuv,key;
    cin>>cuv>>key;
    key=key+cuv;
    for(int i=0;i<cuv.size();i++)
        cout<<v[cuv[i]-'A'+1][key[i]-'A'+1];
    return 0;
}