#include <fstream>
#include<iostream>
using namespace std;
int ciur[101]; //fac numere doar de 2 cifre deci pot sa iau in considerare doar numerele pana la 100
ofstream fout("chei.out");
ifstream fin("chei.in");
int main()
{

    int x,y,s,d,c,nr=0,i,j,cx,n;

    ciur[0]=ciur[1]=1;
    for(i = 2; i <= 101; i++)
    {
        if(ciur[i] == 0)
        {
            for(j = 2 * i; j <= 101; j = j + i)
            {
                ciur[j] = 1; //nu e prim
            }
        }
    }
//Cheile pot avea si o singura cifra...ex:4120 si 35 vor forma cheia 3. La fel se intampla si pentru cazul 30 si 19
    fin>>x>>y;
    fout<<x<<' '<<y<<' ';
    int k=2;
    int ok=1;
    while(ok==1)
    {
        c=y;
        nr=0;
        while(c>=10) c=c/10;
        nr=(x%10)*10+c;

        if(ciur[nr]==1) //daca numarul obtinut nu este prim
        {
            s=0;
            for(d=2; d<=nr/2; d++)
                if(nr%d==0 && ciur[d]==0)
                    s+=d;
            nr=nr-s;
        }
        if(cx==nr || nr==x || nr==y || k==10000) ok=0;
        k++;
        if(ok==1)
            fout<<nr<<' ';
        cx=x;
        x=y;
        y=nr;
    }

    return 0;
}
