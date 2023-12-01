// Chesca Ciprian - sursa 100 p
// O((nrcifre(N)^2))


#include <fstream>

using namespace std;

int main()
{
    unsigned long long n,N,S,P;

    // cate segmente are fiecare cifra
    int s[10]={6,2,5,5,4,5,6,3,7,6};

    // cate cifre strict mai mari se pot obtine din cifra curenta prin adaugare
    int a[10]={1,5,1,2,2,3,1,2,0,0};

    // cate cifre se pot obtine din cifra curenta prin adaugare, inclusiv cifra curenta
    int b[10]={2,7,2,3,3,4,2,5,1,2};


    int c,k,i,j,w[25],aux,v;

    ifstream f("cifre12.in");
    ofstream g("cifre12.out");

    f>>v>>n;

    if (v==1)
    {
     N=n;S=0;
     while (N>0)
        {
        c=N%10;
        S=S+s[c];
        N=N/10;
        }
     g<<S<<"
";
    }

    if (v==2)
    {
        // duc cifrele intr-un vector
        N=n;k=0;
        while (N>0)
        {
        w[++k]=N%10;
        N=N/10;
        }
        // reversez vectorul
        for(i=1,j=k;i<j;i++,j--)
        {
        aux=w[i];
        w[i]=w[j];
        w[j]=aux;
        }

        S=0;
        for(i=1;i<=k;i++)
        {
        if (a[w[i]])
            {
            P=a[w[i]];
            for(j=i+1;j<=k;j++)
                P=P*b[w[j]];
            S=S+P;
            }
        }
    g<<S<<"
";
    }
    f.close();
    g.close();

    return 0;
}

