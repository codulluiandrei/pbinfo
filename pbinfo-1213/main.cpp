#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int DIM=100000;
int v[DIM],x[101];
/*void afisare(int N, unsigned int v[DIM])
{
    int i;
    for(i=1;i<=N;i++)
        cout<<v[i]<<' ';
    cout<<endl;
}*/
void prim(int n)
{
    int i,j;
     for (i=2;i<=n;i++)
        x[i]=1;
    for (i=2;i<=sqrt(n);i++)
        if (x[i])
            for (j=i;j<=n/i;j++)
                x[i*j]=0;
}
int main()
{
    int  N, K, P, i, j, l, nr=0, Max=0, poz; //nr-numar salturi din pozitia i
    ifstream in("iepuras.in");
    ofstream out("iepuras.out");
    in>>P>>N>>K;
    for(i=1;i<=N;i++)
        in>>v[i];
    prim(100);
//cerinta 1
   if(P==1)
    {
        j=K; nr=0;
        while(v[j] && j<=N)
        {
            nr++;
            if(x[v[j]])
                j+=2*v[j];
            else
                j+=v[j];
        }
        if(j<=N)
        {
            out<<"NU"<<endl;
            out<<nr;
        }
        else
        {
            out<<"DA"<<endl;
            out<<nr;
        }
    }
    else
    {
//cerinta 2
        i=1,j=1;
        while(i<=N && j<=N)
        {
            j=i;nr=1;
            while(v[j] && j<=N)
            {
               if(x[v[j]])
                    j+=2*v[j];
                else
                   j+=v[j];
            }
            if(j>N)
                nr=N-i+1;
            else
                nr=j-i+1;
            if(nr>Max)
                poz=i, Max=nr;
            i++;
        }
        out<<poz<<' '<<Max<<'\n';
        for(i=1;i<=poz-1;i++)
            out<<v[i]<<' ';
         j=poz;
        for(i=1;i<=Max && i<=N;i++)
        {
            if(x[v[j]])
                    j+=2*v[j];
                else
                   j+=v[j];
            for(l=poz+1;l<j && l<=N;l++)
               out<<v[l]<<' ';
            poz=j;
        }
        for(i=j+1;i<=N;i++)
            out<<v[i]<<' ';
    }
    return 0;
}