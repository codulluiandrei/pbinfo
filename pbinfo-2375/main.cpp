#include<fstream>

using namespace std;
ifstream fin("palindromsd.in");
ofstream fout("palindromsd.out");

int v[1001];
int main()
{
    int n=0, og, aux, x, st, dr, i;
    while(fin>>x)
    {
        aux=x;
        og=0;
        while(aux!=0)
        {
            og=og*10+aux%10;
            aux/=10;
        }
        if(x==og)
        {
            v[++n]=x;
        }
    }
    if(n==0)
    {
        fout<<-1;
    }
    st=1;
    dr=n;
    for(i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            fout<<v[st++]<<" ";
        }
        else
        {
            fout<<v[dr--]<<" ";
        }
    }
    fin.close();
    fout.close();

    return 0;
}
