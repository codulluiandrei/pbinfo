#include <bits/stdc++.h>
using namespace std;
ifstream fin("mario.in");
ofstream fout("mario.out");
#define NMAX 1001
struct moneda{short int val, nri;} mario[NMAX], bowser[NMAX], mut[NMAX];
int N, M, i, j, sch;
moneda aux;
void citire()
{
        fin>>N;
        for (i=1; i<=N; i++)
        {
            fin>>mario[i].val;
            mario[i].nri = i;
        }
        fin>>M;
        for (i=1; i<=M; i++)
        {
            fin>>bowser[i].val;
            bowser[i].nri = i;
        }
}
void sortare(moneda b[NMAX], int &n){
    int sch;
    do
        {
            sch=0;
            for (i=1; i<n; i++)
                if (b[i].val>b[i+1].val)
                {
                    aux=b[i];
                    b[i]=b[i+1];
                    b[i+1]=aux;
                    sch=1;
                }
        }while (sch);
}
int main()
{
        citire();
        sortare(mario, N);
        sortare(bowser, M);
        long int s=0;
        int cate=0;
        for (i=N, j=1; i>0 && j<=M;i--, j++){
            if (mario[i].val>bowser[j].val)
            {
                cate++;
                aux.val=mario[i].val;
                mario[i].val=bowser[j].val;
                bowser[j].val=aux.val;
                mut[cate].val=mario[i].nri; // indicele din mario
                mut[cate].nri=bowser[j].nri; // indicele din bowser
            }
            else
                break;
        }
            fout<<cate<<'\n';
            for (i=1; i<=cate; i++)
                fout<<mut[i].val<<" "<<mut[i].nri<<endl;
    return 0;
}