#include <fstream>
using namespace std;
ifstream fin("escape.in");
ofstream fout("escape.out");
int n,i, fp[10],f[10],ciur[1000001],d,cam[10],v[10], x, j, y, punctaj, pmax1,pmax2, c;
//fprim==seria 1
int main()
{
    ciur[0]=ciur[1]=1;
    for ( d = 2; d <= 1000; d++ )
        for(j=d*d; j<=1000000; j=j+d)
            ciur[j]=1;
    for( i=1; i<=9; i++)
        v[i]=i;
    fin>>c>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        punctaj=x%100;
        x=x/100;
        y=x%9;
        if(y==0)
            y=9;
        cam[y]++;
        if(ciur[x]==0)
            fp[y]+=punctaj;      //seria 1
        else
            f[y]+=punctaj;        //seria 2
    }
    if(c==1)
    {
        for( i=1; i<=9; i++)
            if( fp[i]>pmax1)
                pmax1=fp[i];
        for( i=1; i<=9; i++)
            if( f[i]>pmax2)
                pmax2=f[i];
        fout << pmax1 <<' '<<pmax2;
    }
    else //if (c==2)
    {
        for( i=1; i<9; i++)
            for( j=i+1; j<=9; j++)
                if( cam[i]<cam[j])                      //descrescator
                {
                    swap(cam[i], cam[j]);
                    swap(v[i], v[j]);
                }
                else if( cam[i]==cam[j]&&v[i]>v[j])     //crescator
                    swap(v[i], v[j]);
        for( i=1; i<=9; i++)
            if(cam[i]!=0)
                fout<<v[i]<<' ';
    }
    return 0;
}