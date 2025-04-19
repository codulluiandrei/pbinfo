#include <fstream>
using namespace std;
ifstream fin("numere23.in");
ofstream fout("numere23.out");
long a[10001], b[10001], x, i, n, k;
int cer;
long urmatorul(long x);
int verif(long x);
int main()
{
    fin>>n>>k>>cer;
    x=2;
    for(i=1;i<=n;i++)
        {
        a[i]=x;
        x=urmatorul(x);
        }
    if(cer==1)                  ///cerinta 1
       fout<<a[n]<<'\n';
    else                        ///cerinta 2
    {                   ///plasez elem din a in b, parcurgand locurile libere din k in k
        b[1]=a[1];
        int p=1;
        for(i=2; i<=n; )
        {
            int m=0;  ///cate locuri libere am gasit
            if(p==n)
                p=1;
            else
                p++;
            while(m<k)      ///tb saparcurg pana la al k-lea loc liber
            {
                if(b[p]==0)
                   {
                       m++;
                       if(m==k)
                        {
                            b[p]=a[i++];m=0;
                            break;
                        }
                   }
                p++;
                if(p==n+1)
                    p=1;
            }
        }
        for(i=1;i<=n;i++)
            fout<<b[i]<<' ';
        fout<<'\n';
    }
    return 0;
}
int verif(long x)
{
    long nr=0,f=2;
    while(x%f==0)
    {
        x/=f;
        nr++;
        if(nr>3)
            return 0;
    }
    f=3;
    while(x>=f)
    {
         while(x%f==0)
         {
             x/=f;
             nr++;
         }
         if(nr>3) return 0;
         f+=2;
    }
    return nr<=3;
}
long urmatorul(long x)
{
    do
    {
        x++;
        if(verif(x))
            return x;
    }while(1);
}