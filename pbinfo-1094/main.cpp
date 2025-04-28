//Emanuela Cerchez
//timp maxim: 0.17
#include <stdio.h>
#define InFile  "immortal.in"
#define OutFile "immortal.out"
#define NMax 54
#define LgMax NMax * NMax
int T[NMax][NMax];
int n, m, nr;
struct Poz   {int x, y;}        P[LgMax];
struct Lupta {struct Poz v, m;} sol[LgMax];
int ok=0;
int mort[LgMax];
int dx[]={-1, 0, 1,  0};
int dy[]={ 0, 1, 0, -1};
void citire(void);
void bkt(int);
void afisare(void);
int main()
{
citire();
bkt(0);
return 0;
}
void citire()
{
int i, j, x, y, k=0;
FILE * fin=fopen(InFile,"r");
fscanf(fin,"%d %d %d", &n, &m, &nr);
for (i=1; i<=nr; i++)
    {fscanf(fin,"%d %d", &x, &y);
     T[x+1][y+1]=i;}
for (i=2; i<=n+1; i++)
    for (j=2; j<=m+1; j++)
        if (T[i][j])
           {P[++k].x=i; P[k].y=j; T[i][j]=k;}
for (i=0; i<n+4; i++) T[i][0]=T[i][1]=T[i][m+3]=T[i][m+2]=-1;
for (i=0; i<m+4; i++) T[0][i]=T[1][i]=T[n+2][i]=T[n+3][i]=-1;
}
void bkt(int k)
//s-au desfasurat k lupte sol[0], ..., sol[k-1]
{
int i, d, x, y, moare;
if (!ok)
   if (k==nr-1)
      {ok=1; afisare();}
      else
      for (i=1; i<=nr; i++)
          if (!mort[i])
             {
              //poate sari i?
              x=P[i].x; y=P[i].y;
              for (d=0; d<4; d++)
                 if (T[x+dx[d]][y+dy[d]]>0 && T[x+2*dx[d]][y+2*dy[d]]==0)
                     {
                      //un vecin peste care poate sari
                      moare=T[x+dx[d]][y+dy[d]];
                      sol[k].m.x=x+2*dx[d]; sol[k].m.y=y+2*dy[d];
                      sol[k].v.x=x; sol[k].v.y=y;
                      P[i].x=x+2*dx[d]; P[i].y=y+2*dy[d];
                      T[x][y]=0; T[x+2*dx[d]][y+2*dy[d]]=i;
                      mort[T[x+dx[d]][y+dy[d]]]=1;
                      T[x+dx[d]][y+dy[d]]=0;
                      bkt(k+1);
                      P[i].x=x; P[i].y=y;
                      T[x][y]=i; T[x+2*dx[d]][y+2*dy[d]]=0;
                      T[x+dx[d]][y+dy[d]]=moare;
                      mort[T[x+dx[d]][y+dy[d]]]=0;
                     }
             }
}
void afisare()
{
int i;
FILE * fout=fopen(OutFile,"w");
for (i=0; i<nr-1; i++)
    fprintf(fout,"%d %d %d %d
",sol[i].v.x-1,sol[i].v.y-1,sol[i].m.x-1,sol[i].m.y-1);
fclose(fout);
}