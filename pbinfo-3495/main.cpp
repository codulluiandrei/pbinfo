#include <fstream>
using namespace std;
char f[6][6];
char f2[6][6];
char poz[130];
char poz1[130];
int main()
{
    ifstream cin ("foursquare.in");
    ofstream cout ("foursquare.out");
    char c;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>c;
                poz[(int)(c)]=i*10+j;
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>c;
                f[i][j]=c;
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>c;
                f2[i][j]=c;
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>c;
                poz1[(int)(c)]=i*10+j;
            }
        }
        char x,y;
        while(cin>>x>>y)
        {
            int a,b,c,d;
            a=poz[x]/10;
            b=poz[x]%10;
            c=poz1[y]/10;
            d=poz1[y]%10;
            cout<<f[a][d]<<f2[c][b];
        }
    return 0;
}