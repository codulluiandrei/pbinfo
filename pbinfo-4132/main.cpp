#include <fstream>
using namespace std;
ifstream fin("culori.in");
ofstream fout("culori.out");
int cerinta,N,nr_culori,culoare1,culoare,ok;
short x[505],y[505];
int main()
{
    fin>>cerinta>>N;
    if(cerinta==1)//cel mai lung rand ce contine NU contine 2 patratele alaturate colorate la fel
    {
        int Lmax=0,Kmax=0;
        for(int i=1; i<=N; i++)
        {
            fin>>nr_culori;
            ok=1;
            fin>>culoare;
            for(int j=1; j<=nr_culori-1; j++)
            {
                fin>>culoare1;
                if(culoare==culoare1)
                    ok=0;
                culoare=culoare1;
            }
            if (ok)
                if(nr_culori>Lmax)
                {
                    Lmax=nr_culori;
                    Kmax=1;
                }
                else if(Lmax==nr_culori)
                    Kmax++;
        }
        fout<<Lmax<<' '<<Kmax<<'\n';
    }
    else if (cerinta==2)
    {
        fin>>x[0];//citim primul numar
        for(int i=1; i<=x[0]; i++)
            fin>>x[x[0]-i+1];
        for(int i=2; i<=N; i++)
        {
            fin>>y[0];//citim urmatorul numar
            for(int j=1; j<=y[0]; j++)
                fin>>y[y[0]-j+1];
            // Compararea celor doua numere
            ok=1;
            if(x[0]!=y[0])// cele doua numere au lungimi diferite
            {
                if (x[0]<y[0])
                    ok=-1;
            }
            else//cele doua numere au aceeasi lungime
            {
                //comparam lexicografic
                int j=x[0];
                while((x[j]==y[j]) && j>0)
                    j--;
                if(x[j]<y[j])
                    ok=-1;
            }
            if(ok==-1) // al doilea numar e mai mare
                for(int j=0; j<=y[0]; j++)
                    x[j]=y[j];
        }
        for(int i=1; i<=x[0]; i++)
            fout<<x[x[0]-i+1];
        fout<<'\n';
    }
    return 0;
}