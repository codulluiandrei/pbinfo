#include <fstream>

using namespace std;
ifstream  fin("puteri5.in");
ofstream fout("puteri5.out");
int d[100000],s[100000],nd,ns;
int x[5];
int x_la_y(int x,int y) // calculeaza x la puterea y
{                       // x si y sunt cifre
    int p,i;
    p=1;
    for(i=1;i<=y;i++)
        p=p*x;
    return p;
}
void putere(int x,int z)  // calculeaza x la z
{               // x este cifra, z este numar natural
    int i,r,j;
    d[0]=1;nd=1;

    if(x>1)
    for(i=1;i<=z;i++)
    {
        r=0;
        for(j=0;j<nd;j++)
            {
                d[j]=d[j]*x+r;
                r=d[j]/10;
                d[j]=d[j]%10;

            }

        if(r>0)
        {
            d[nd]=r;
            nd++;
        }
    }
}

void suma(void)
{
int i,r;
for(i=0;i<nd;i++)
    s[i]=s[i]+d[i];

if(nd>ns)ns=nd;

r=0;
for(i=0;i<ns;i++)
{
    s[i]=s[i]+r;
    if(s[i]>9)
    {
        s[i]=s[i]-10;
        r=1;
    }
    else r=0;
}
if(r>0)
{
    s[ns]=r;
     ns++;
}

}

int main()
{
    int a,b,c,i,u,v,z;
    fin>>a>>b>>c;
    x[0]=a;x[1]=b;x[2]=c;x[3]=a;x[4]=b;
    ns=1;
  for(i=1;i<=3;i++)
    {
        u=x[i];v=x[i+1];
        z=x_la_y(u,v);
        putere(x[i-1],z);
        suma();

        z=x_la_y(v,u);
        putere(x[i-1],z);
        suma();
    }
    for(i=ns-1;i>=0;i--)
        fout<<s[i];

    return 0;
}
