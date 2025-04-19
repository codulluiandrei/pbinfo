#include <fstream>
using namespace std;
ifstream f("tai.in");
ofstream g("tai.out");
int N,i,x,nd,d,C,aux,y1,y2,y3,z,t,w,p,max1,x1,x2,q;
int main()
{
    f>>C;
    if (C==1)
    {
        f>>N;
        max1=0;
        for (i=1;i<=N;i++)
        {
            f>>x;
            for (d=2;d*d<=x;d++)
                if (x%d==0) break;
            if (x>1&&d*d>x&& x>max1)
                max1=x;
        }
        g<<max1<<"\n";
    }
    else
        if (C==2)
    {
        max1=0;
        f>>N;
        for (i=1;i<=N;i++)
        {
            f>>x;
            aux=x;
            p=10;
            while (aux>=p)
            {
                x1=aux%p;
                x2=aux/p;
                //g<<x<<"="<<x2<<" "<<x1<<endl;
                p=p*10;
                for (d=2;d*d<=x1;d++)
                    if (x1%d==0) break;
                if (x1>1&&d*d>x1&& x1>max1)
                    max1=x1;
                for (d=2;d*d<=x2;d++)
                    if (x2%d==0) break;
                if (x2>1&&d*d>x2&& x2>max1)
                    max1=x2;
            }
        }
        g<<max1<<"\n";
    }
    else
    {
        f>>N;
        max1=0;
        for (i=1;i<=N;i++)
        {
            f>>x;
            aux=x;
            p=10;
            while (aux>p*10)
                p=p*10;
            for (t=10;t*10<=p;t=t*10)
                for (q=10;q*t<=p;q=q*10)
            {
                    y1=x%t;
                    z=x/t;
                    y2=z%q;
                    y3=z/q;
                    for (d=2;d*d<=y1;d++)
                        if (y1%d==0) break;
                    if (y1>1&&d*d>y1&& y1>max1)
                        max1=y1;
                    for (d=2;d*d<=y2;d++)
                        if (y2%d==0) break;
                    if (y2>1&&d*d>y2&& y2>max1)
                        max1=y2;
                    for (d=2;d*d<=y3;d++)
                        if (y3%d==0) break;
                    if (y3>1&&d*d>y3&& y3>max1)
                        max1=y3;
            }
        }
        g<<max1<<"\n";
    }
    return 0;
}