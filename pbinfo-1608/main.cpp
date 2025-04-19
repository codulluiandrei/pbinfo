#include <fstream>
using namespace std;
ifstream fin("sortare_divizori.in");
ofstream fout("sortare_divizori.out");
int v[1000],div_v[1000],n;
int main()
{
    int i,j;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>v[i];
        int x=v[i];
        int exp=0;
        while(x%2==0)
        {
            exp++;
            x/=2;
        }
        int nr_div=exp+1;
        int d=3;
        while(d*d<=x)
        {
            exp=0;
            while(x%d==0)
            {
                exp++;
                x/=d;
            }
            nr_div*=(exp+1);
            d+=2;
        }
        if(x!=1)
            nr_div*=2;
        div_v[i]=nr_div;
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(div_v[i]<div_v[j])
            {
                swap(v[i], v[j]);
                swap(div_v[i], div_v[j]);
            }
            else
                if(div_v[i]==div_v[j])
                    if(v[i]>v[j])
                        swap(v[i], v[j]);
    for(i=0;i<n;i++)
        fout << v[i]<<' ';
    return 0;
}