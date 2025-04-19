#include <fstream>
using namespace std;
ifstream f("coduri.in");
ofstream g("coduri.out");
int n, h, d;
char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'},c,cod[65], cod1[65];
char w[64]={'0','0','0','0','0','0','0','1','0','0','1','0','0','0','1','1','0','1','0','0','0','1','0','1','0','1','1','0','0','1','1','1','1','0','0','0','1','0','0','1','1','0','1','0','1','0','1','1','1','1','0','0','1','1','0','1','1','1','1','0','1','1','1','1'};
int i,j,x,q,nrx=0,nrg;
int main()
{
    f>>n>>h>>d;
    for(i=1;i<=n;i++)
    {
        f>>c;
        if(c=='H')
        {
            for(j=1;j<=h;j++)
            {
                f>>cod[j];
                if(cod[j]>'9') q=cod[j]-'A'+10; else q=cod[j]-'0';
                g<<w[4*q+0]<<w[4*q+1]<<w[4*q+2]<<w[4*q+3];
            }
        }
        else
            if(c=='D')
            {
                for(int k=1;k<=d;k++)f>>cod1[k];
                for(j=1;j<=h;j++)
                {
                    x=(cod1[j*4-3]-'0')*8+(cod1[j*4-2]-'0')*4+(cod1[j*4-1]-'0')*2+(cod1[j*4]-'0');
                    g<<a[x];
                }
            }
            else
            {
                for(j=1;j<=h;j++)
                    f>>cod[j];
                nrg=0;
                for(int k=1;k<=d;k++)f>>cod1[k];
                for(j=1;j<=h;j++)
                {
                    if(cod[j]=='X')
                    {
                        if(cod1[j*4-3]!='X'&&cod1[j*4-2]!='X'&&cod1[j*4-1]!='X'&&cod1[j*4]!='X')
                        {
                            x=(cod1[j*4-3]-'0')*8+(cod1[j*4-2]-'0')*4+(cod1[j*4-1]-'0')*2+(cod1[j*4]-'0');
                            cod[j]=a[x];
                        }
                        else nrg++;
                    }
                }
                if(nrg>0) {nrx++;g<<0;}
                else
                for(j=1;j<=h;j++)
                {
                    g<<(char) cod[j];
                }
            }
        g<<'\n';
    }
    g<<nrx;
    g.close();
    return 0;
}