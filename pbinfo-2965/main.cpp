//autor: prof. Liviu Pinzaru, Palatul Copiilor Suceava & Clubul Copiilor Falticeni
#include <fstream>
using namespace std;
int v[8],ord[100];
short int w[10];

int main()
{
    ifstream f("album.in");
    ofstream g("album.out");

    int i,j,N,n,x,z,poz=0,Mm=0,ii,ORD;
    int p;
    char a[20];
    int V=0,R=0;

    f>>p;
    f>>N;

    if(p==1)
    {
        for(ii=1;ii<=N;++ii)
            f>>a;
        for(j=0;a[j];++j)
        {
            x=a[j]-'0';
            w[x]++;
        }
        i=0;
        for(j=9;j>=0 ;--j)
        {
            if(w[j]>=1)
                v[++i]=j;
        }
        x=v[1];
        if(w[x]>1)
            g<<x<<" "<<x;
        else
            g<<v[2]<<" "<<v[1];

        return 0;
    }


    for(ii=1;ii<=N;++ii)
    {
        f>>a;
        //g<<a<<'\n';

        for(j=0;j<=9;++j)
            w[j]=0;

        for(j=0;a[j];++j)
        {
            x=a[j]-'0';
            w[x]++;
        }

        i=0;
        for(j=9;j>=0 ;--j)
        {
            if(w[j]>=1)
                v[++i]=j;
        }
        n=i;

        x=v[1];
        if(w[x]>1)
            Mm=x*10+x;
        else
            Mm=v[1]*10+v[2];

        //g<<Mm<<'\n';

            ORD=1234567;

            for(i=1;i<=n;++i)  //verificam dublurile
            {
                x=v[i];
                if(w[x]>1)
                {
                    z=x*10+x;
                    //g<<z<<'\n';
                    //cautam cel mai mic ordin
                    if(ord[z]>0) //daca numarul z a mai fost
                    {
                        if(ord[z]<ORD)
                            ORD=ord[z];
                    }
                }
            }

            for(i=1;i<n;i++)
                for(j=i+1;j<=n;j++)
                {
                    z=v[i]*10+v[j];
                    //g<<z<<'\n';
                    //cautam cel mai mic ordin
                    if(ord[z]>0) //daca a mai fost
                    {
                        if(ord[z]<ORD)
                            ORD=ord[z];
                    }
                }

            if(ORD==1234567)  //se creaza un nou ordin
            {
                ++poz;
                ord[Mm]=poz;
                ORD=poz;
                //g<<"alt ordin:"<<ORD<<'\n';
                if(poz%2) V++;
                else R++;

            }
            else  //s-a aderat la ordinul ORD
            {
                if(ORD%2) V++;
                else R++;
            }

            //g<<"V="<<V<<" R="<<R<<" poz="<<poz<<" ORD="<<ORD<<'\n';
    }


if(V>R)
    g<<"V"<<'\n'<<V;
else if(R>V)
    g<<"R"<<'\n'<<R;
else //if(V==R)
   g<<"V R"<<'\n'<<V;


    return 0;
}
