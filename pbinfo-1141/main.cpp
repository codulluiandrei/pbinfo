//100 de puncte, optim
#include<fstream>
using namespace std;
struct numar
{
    int v[50],n;
};
numar next(numar a)
{
    int i, s1, s2, s[2], t[2], i2, j, x, k;
    a.v[a.n+1]=0;
    s[0]=0;
    s[1]=0;
    for(i=1;i<=a.n+1;i++)
    {
        i2=i%2;//paritatea curenta; 1-i2 paritatea inversa celei curente
        s[i2]=s[i2]+a.v[i];
    }
    t[0]=0;
    t[1]=0;
    for(i=1;i<=a.n+1;i++)
    {
        i2=i%2;
        a.v[i-1]=0;
        if(i>1)t[1-i2]=t[1-i2]+9;
        s1=s[1-i2];//suma cifrelor de pe pozitii >i cu alta paritate decat pozitia i (curenta)
        s2=s[i2]-a.v[i];//suma cifrelor de pe pozitii >i cu aceeasi paritate decat pozitia i
        s[i2]=s2;//actualizez s[i2]
        if(a.v[i]<9)//am gasit o cifra care poate fi crescuta;
        {
            if(s2+a.v[i]<s1)
            {
                if(s1>s2+9+t[i2])continue;//nu se poate face echilibrare
                if(s2 + a.v[i]+1 + t[i2] >= s1)
                {
                    j=1;
                }
                else
                {
                    j=s1-(s2 + a.v[i] + t[i2]);
                }
                x=s1-(s2 + a.v[i]+j);
                k=2-i2;
            }
            else
            {
                if(s2 + a.v[i]+1 > s1 + t[1-i2])continue;//nu se poate face echilibrare
                j=1;
                x=(s2 + a.v[i]+1)-s1;
                k=1+i2;
            }
            //construiesc numarul cautat
            a.v[i]=a.v[i]+j;
            while(k<=i-1)
            {
                if(x>=9)
                {
                    a.v[k]=9;
                }
                else
                {
                    a.v[k]=x;
                }
                x=x-a.v[k];
                k=k+2;
            }
            break;
        }
    }
    if(a.v[a.n+1]>0)a.n++;//a fost nevoie de o cifra in plus, cifra 1
    return a;
}
int main()
{
    char ch;
    int aux,i;
    numar a, b;
    ifstream  fin("ech.in");
    ofstream fout("ech.out");
    a.n=0;
    while(fin>>ch)
    {
        if(ch>='0' && ch<='9')
        {
            a.n++;
            a.v[a.n]=ch-48;
        }
    }
    for(i=1;i<=a.n/2;i++)
    {
        aux=a.v[i];
        a.v[i]=a.v[a.n+1-i];
        a.v[a.n+1-i]=aux;
    }
    b=next(a);
    for(i=b.n;i>=1;i--)
    {
        fout<<b.v[i];
    }
    fout<<'\n';
    fout.close();
    fin.close();
    return 0;
}