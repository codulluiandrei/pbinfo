// solutie 100 pct Mihai Georgescu
#include <stdio.h>
struct Frigider
         {
           char min;
           char max;
         }f[10001], r[10001];
int Cate, i, j, N;
char min, max;
FILE* Fisier;
char Maxim(char x, char y)
{
  if (x>y) return x;
  else return y;
}
char Minim(char x, char y)
{
  if (x<y) return x;
  else return y;
}
int Cauta(char min, char max)
{
  int i, Unde;
  for (i=1; i<= Cate; i++)
    {
      if ((f[i].max>=min) && (f[i].max<=max)) Unde=i;//am gasit frigiderul i
      if ((f[i].min>=min) && (f[i].min<=max)) Unde=i;//am gasit frigiderul i
      if ((f[i].min<=min) && (f[i].max>=max)) Unde=i;//am gasit frigiderul i
      if ((f[i].max<min) || (f[i].min>max)) Unde=-1; //nu am gasit frigider
    }
  return Unde;
}
void Intersectie(int j, char min, char max)
{
  f[j].min=Maxim(min, f[j].min);//modific temperatura minima din frigider
  f[j].max=Minim(max, f[j].max);//modific temperatura maxima din frigider
}
void Ordoneaza(void)
{                      //sortare prin selectie
  int i, j, ptmin;
  char tmax, tmin;
  for (i=1; i<=N-1; i++)
    {
      tmin=r[i].min; tmax=r[i].max; ptmin=i;
      for (j=i+1; j<=N; j++)
        if (r[j].min<tmin)   //crescator dupa temperatura minima
          { tmax=r[j].max; tmin=r[j].min; ptmin=j; }
        else
          if (r[j].min==tmin)//pentru temperatura minima egala
            if (r[j].max>tmax)     //descrescator dupa cea maxima
              { tmax=r[j].max; tmin=r[j].min; ptmin=j; }
      r[ptmin].min=r[i].min; r[ptmin].max=r[i].max;
      r[i].min=tmin; r[i].max=tmax;
    }
}
int main()
{
  char x, y;
  Fisier=fopen("reactivi.in", "rt");
  fscanf(Fisier, "%d", &N);
  for (i=1; i<=N; i++)
    fscanf(Fisier, "%d %d", &r[i].min, &r[i].max, &x, &y);
  Ordoneaza();      //ordonez intervalele de temperatura
                    //crescator dupa temperatura minima si
                    //descrescator dupa temperatura maxima
  //pun primul reactiv (deci cel cu intervalul cel mai mare)
  //in primul frigider
  f[1].min=r[1].min; f[1].max=r[1].max; Cate=1;
  for (i=2; i<= N; i++)          //pentru toate celelalte
    {
      min=r[i].min; max=r[i].max;
      j=Cauta(min, max);  //caut un frigider in care a mai fost pus ceva
      if (j>0)                //daca gasesc
        Intersectie(j, min, max);//ajustez temperatura din frigider
      else                    //altfel
        {
          Cate++;                //"deschid" un frigider nou
          f[Cate].min=min;       //si pun aici reactivul
          f[Cate].max=max;
        }
    }
  fclose(Fisier);
  Fisier=fopen("reactivi.out", "wt");
  fprintf(Fisier, "%d\n", Cate);
  fclose(Fisier);
  return 0;
}