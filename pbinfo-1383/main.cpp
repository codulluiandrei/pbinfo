#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
    ifstream  fin1("avioane.in");
    ofstream fout1("avioane.out");
    int tip1,tip2,tip3,tip4,tipx,lovit,picat,nou,s,trag;
int i,j,k,l,n,a[305][305],sol,x,t,viz[10000];
void init_matrice()
{
    int i,j;
    for(i=1;i<=300;i++)
        for(j=1;j<=300;j++)
            a[i][j]=0;
}
int tipul1(int n, int x, int y, int &s)
{
    int sol=(a[x][y]%100000==a[x+2][y]%100000)&&(x<=n-3)&&(y>=3)&&(y<=n-2);
    int k;
    s=a[x][y]+a[x+2][y];
    for(k=1;k<=5&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x+1][y-3+k]%100000);
        s+=a[x+1][y-3+k];
    }
    for(k=1;k<=3&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x+3][y-2+k]%100000);
        s+=a[x+3][y-2+k];
    }
    return sol;
}
int tipul2(int n, int x, int y, int &s)
{
    int sol=(a[x][y]%100000==a[x][y-2]%100000)&&(x<=n-2)&&(x>=3)&&(y>=4);
    int k;
    s=a[x][y]+a[x][y-2];
    for(k=1;k<=5&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x-3+k][y-1]%100000);
        s+=a[x-3+k][y-1];
    }
    for(k=1;k<=3&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x-2+k][y-3]%100000);
        s+=a[x-2+k][y-3];
    }
    return sol;
}
int tipul3(int n, int x, int y, int &s)
{
    int sol=(a[x][y]%100000==a[x-2][y]%100000)&&(x>=4)&&(y>=3)&&(y<=n-2);
    int k;
    s=a[x][y]+a[x-2][y];
    for(k=1;k<=5&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x-1][y-3+k]%100000);
        s+=a[x-1][y-3+k];
    }
    for(k=1;k<=3&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x-3][y-2+k]%100000);
        s+=a[x-3][y-2+k];
    }
    return sol;
}
int tipul4(int n, int x, int y, int &s)
{
    int sol=(a[x][y]%100000==a[x][y+2]%100000)&&(x<=n-2)&&(x>=3)&&(y<=n-3);
    int k;
    s=a[x][y]+a[x][y+2];
    for(k=1;k<=5&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x-3+k][y+1]%100000);
        s+=a[x-3+k][y+1];
    }
    for(k=1;k<=3&&sol;k++)
    {
        sol=(a[x][y]%100000==a[x-2+k][y+3]%100000);
        s+=a[x-2+k][y+3];
    }
    return sol;
}
void  rezolva()
{
    fin1>>n>>trag;
    tipx=1; //
    viz[0]=1;
    int total=0;;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            {
                fin1>>a[i][j];
                if (viz[a[i][j]]==0)
                {
                    viz[a[i][j]]=1;
                    total++;
                }
            }
    fout1<<total<<"\n";
    tip1=tip2=tip3=tip4=lovit=picat=nou=0;
    int x,y;
    for(i=1;i<=trag;i++)
    {
        fin1>>x>>y;
        a[x][y]+=100000;
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            s=0;
            if (a[i][j]%100000>0)
            {
                if(tipul1(n,i,j,s)>0)
                {
                    tip1++;
                    if (a[i][j]>100000) picat++;
                    else
                        if (s/100000>=5) picat++;
                        else
                            if(s/100000>0) lovit++;
                }
                else
                if(tipul2(n,i,j,s)>0)
                {
                    tip2++;
                    if (a[i][j]>100000) picat++;
                    else
                        if (s/100000>=5) picat++;
                        else
                            if(s/100000>0) lovit++;
                }
                else
                if(tipul3(n,i,j,s)>0)
                {
                    tip3++;
                    if (a[i][j]>100000) picat++;
                    else
                        if (s/100000>=5) picat++;
                        else
                            if(s/100000>0) lovit++;
                }
                else
                if(tipul4(n,i,j,s)>0)
                {
                    tip4++;
                    if (a[i][j]>100000) picat++;
                    else
                        if (s/100000>=5) picat++;
                        else
                            if(s/100000>0) lovit++;
                }
            }
            else
            {
                if (nou==0)
                switch (tipx)
                {
                    case 1: if(tipul1(n,i,j,s)>0)
                                if (s%100000==0)
                                {
                                    nou=1;
                                    x=i;
                                    y=j;
                                }
                        break;
                    case 2: if(tipul2(n,i,j,s)>0)
                                if (s%100000==0)
                                {
                                    nou=1;
                                    x=i;
                                    y=j;
                                }
                        break;
                    case 3: if(tipul3(n,i,j,s)>0)
                                if (s%100000==0)
                                {
                                    nou=1;
                                    x=i;
                                    y=j;
                                }
                        break;
                    case 4: if(tipul4(n,i,j,s)>0)
                                if (s%100000==0)
                                {
                                    nou=1;
                                    x=i;
                                    y=j;
                                }
                        break;
                }
            }
        }
    fout1<<tip1<<'\n';
    fout1<<tip2<<'\n';
    fout1<<tip3<<'\n';
    fout1<<tip4<<'\n';
    fout1<<lovit<<'\n';
    fout1<<picat<<'\n';
}
int main()
{
    rezolva();
    fin1.close();
    fout1.close();
    return 0;
}