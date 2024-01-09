#include <fstream>

using namespace std;
char mat1[6][6],mat4[6][6];
int square2[130],square3[130];
int main()
{
    ifstream cin ("foursquare1.in");
    ofstream cout ("foursquare1.out");
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
            cin>>mat1[i][j];
    }
    char ch;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>ch;
            square2[ch]=i*10+j;
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>ch;
            square3[ch]=i*10+j;
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
            cin>>mat4[i][j];
    }
    char a,b;
    while(cin>>a>>b)
    {
        int x1,y1,x2,y2;
        x1=square2[a]/10;
        y2=square2[a]%10;
        x2=square3[b]/10;
        y1=square3[b]%10;
        cout<<mat1[x1][y1]<<mat4[x2][y2];
    }
    return 0;
}