#include <bits/stdc++.h>
#define MAX_N 512
#define INF 1000000
using namespace std;
int n;
int pre[2][MAX_N+1], crt[2][MAX_N+1];
/**
crt[0][j]=reprezinta multiplicitatea lui 2 in costul drumului pana la linia curenta si coloana j
pre[0][j]=reprezinta multiplicitatea lui 2 in costul drumului pana la linia precedenta si coloana j
crt[1][j]=reprezinta multiplicitatea lui 5 in costul drumului pana la linia curenta si coloana j
pre[1][j]=reprezinta multiplicitatea lui 5 in costul drumului pana la linia precedenta si coloana j
*/
int min(int a, int b)
{
  if (a < b) return a;
  return b;
}
int mult(int a, int b)
///determina multiplicitatea lui b in a
{
  int nr=0;
  while (a%b==0)
        {a /= b;
         nr++;}
  return nr;
}
int main()
{
  int i, j, k;
  int v;
  FILE * fin=fopen("zero1.in","r");
  FILE * fout=fopen("zero1.out","w");
  fscanf(fin, "%d",&n);
  for (i=0; i<2; i++)
      {
       pre[i][1]=0;
       for (j=2; j<=n; j++) pre[i][j] = INF;
       crt[i][0] = INF;
      }
  for (i=1; i<=n; i++)
      {
       for (j=1; j<=n; j++)
           {
            fscanf(fin, "%d", &v);
            for (k=0; k<2; k++)
                if (!v)
                   crt[k][j] = INF;
                   else
                   crt[k][j]=mult(v,!k?2:5) + min(crt[k][j-1],pre[k][j]);
            }
       for (j=0; j<2; j++)
           for (k=1; k<=n; k++)
               pre[j][k] = crt[j][k];
      }
  fprintf(fout,"%d\n",min(crt[0][n],crt[1][n]));
  fclose(fout);
  return 0;
}