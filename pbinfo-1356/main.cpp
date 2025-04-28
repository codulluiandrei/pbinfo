#include <fstream>
#include <cmath>
using namespace std;
ifstream f("nsir.in");
ofstream g("nsir.out");
int st[101], n, ex=0;
double eps=0.00001;
void scrie(int k)
{
    ex=1;
    for(int i=1;i<=k;i++)
        g<<st[i]<<" ";
    g<<endl;
 }
int suma1(int k)
{
    int i, s=0;
    for(i=1;i<=k;i++)
        s+=st[i];
    return s;
}
float suma2(int k)
{
    int i;
    float s=0;
    for(i=1;i<=k;i++)
        s+=1./st[i];
    return s;
}
int validare(int k)
{
    if(k==1)return 1;
    if(suma1(k)>n || (suma2(k)>1+eps)) return 0;
    return 1;
}
void back(int k)
{
    if(k<=n)
    {
        if( (suma1(k-1)==n) && (fabs(1-suma2(k-1))<eps) )
        {
            ex=1; scrie(k-1);
        }
        else
        {
            for(st[k]=st[k-1]; st[k]<=n; st[k]++)
                 if (validare(k)==1)back(k+1);
        }
    }
}
int main()
{
    f>>n;
    back(1);
    if(ex==0)g<<0<<endl;
    return 0;
}