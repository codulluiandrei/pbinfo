//prof. Carmen Minca
//Colegiul National de Informatica Tudor Vianu Bucuresti
#include <fstream>
using namespace std;
int n,d,k,pozdama[103][3], albe[1003];
char a[1003][1003];
ifstream f("betasah.in");
ofstream g("betasah.out");
int main()
{
    //citire date
    int i,l,c,j,i1;
    f>>n>>d>>k;
    for(i=1;i<=d;i++)
    {
        f>>l>>c;
        a[l][c]=1;//codific cu 1 pozitia damei din joc
        pozdama[i][1]=l;pozdama[i][2]=c;
    }
    for(i=1;i<=n;i++)albe[i]=i;
    for(i=1;i<=k;i++)
    {
        f>>l>>c;
        a[l][c]=2;//codific cu 2 patratele gri din joc
        albe[l]--;//scad patratele gri din nr total de patrate de pe linia l
    }
    int M=albe[1]; //a)
    for(i=2;i<=n;i++)M=max(albe[i],M);
    //bordare matrice. Incadrez suprafata de joc cu patrate gri
    //pentru a nu iesi din suprafata de joc
    for(i=0;i<=n+1;i++)
       a[i][0]=a[i][i+1]=a[i][i+2]=2;
    for(j=0;j<=n+2;j++)
       a[n+1][j]=2;
    //determin pentru fiecare dama patratele accesibile
    for(i=1;i<=d;i++)
    {
        l=pozdama[i][1]; c=pozdama[i][2];
        //pe aceeasi linie
        j=c-1;
            while(a[l][j]!=2)//directia 7
            {
               if(a[l][j]==0)a[l][j]=3;
               j--;
            }
            j=c+1;
            while(a[l][j]!=2)//directia 3
            {
                if(a[l][j]==0)a[l][j]=3;
                j++;
            }
        //pe aceeasi coloana
          i1=l-1;
            while(a[i1][c]!=2)//directia 1
            {
                if(a[i1][c]==0)a[i1][c]=3;
                i1--;
            }
            i1=l+1;
            while(a[i1][c]!=2)//directia 5
            {
                if(a[i1][c]==0)a[i1][c]=3;
                i1++;
            }
        //pe diagonala 8-4
        i1=l-1; j=c-1;
            while (a[i1][j]!=2)//directia 8
            { if(a[i1][j]!=1) a[i1][j]=3;//marchez cu 3 patratele accesibile
              i1--; j--;}
            i1=l+1; j=c+1;
            while (a[i1][j]!=2)//directia 4
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1++; j++;}
        //pe diagonala 2-6
        i1=l-1; j=c+1;
            while (a[i1][j]!=2)//spre 2
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1--; j++;}
            i1=l+1; j=c-1;
            while (a[i1][j]!=2)//spre 6
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1++; j--;}
    }
    //numarul patratelor accesibile = nr valori de 3 din matrice
    int P=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
       if(a[i][j]==3)P++;
    g<<M<<endl<<P<<endl;
    return 0;
}