//Serban Marinel 2023
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("struguri.in");
ofstream fout ("struguri.out");

struct gramada
{
   unsigned int nrG;
   unsigned int oca;
   bool luat;
} G[20001], G1[20001];

struct solutie
{
   unsigned int nr_carute;
   unsigned int cate;
   unsigned int oca_pe_caruta;
   unsigned int care[20001];
} sol[501];

int N, i, ramase, caz, nrsol, C;

void citire()
{
   int i;
   fin >> C >> N;
   for (i = 1; i <= N; i++)
   {
      fin >> G1[i].oca;
      G1[i].nrG = i;
   }
   ramase = N;
}

void refa()
{
   int j = 0;
   for (i = 1; i <= N; i++)
      if (!G1[i].luat)
         G[++j] = G1[i];
   N = j;
   memcpy (G1, G, sizeof (G));
}

void Dirichlet_lung()
{
   unsigned int Rest[20001] = {0};
   int S = 0, i, j, deunde, pana_unde, lmax = 0;
   caz = 0;
   for (i = 1; i <= N; i++)  //calculez sumele si resturile
   {
      S = S + G1[i].oca;
      Rest[i] = S % N;
   }
   //caut 0 in resturi
   i = N;
   while (i >= 1 && Rest[i]) i--;
   if (i)
   {
      lmax = i;          //am carutele 1..i
      caz = 1;           //adica am un rest 0
      deunde = 1;
	   pana_unde = i;
	   caz = 1;
   }

   for (i = 1; i < N; i++)  //acum caut resturi egale
      for (j = N; j > i; j--)
        if (Rest[i] == Rest[j])  // am gasit 2 resturi egale la distanta maxima
           if (j - i > lmax)
	       {
              lmax = j - i;
              deunde = i + 1;
			     pana_unde = j;
	       }
   if (ramase == N && C == 1)
   {
	   fout << lmax << ' ' << deunde << ' ' << pana_unde << '\n';
	   exit(0);
   }
   nrsol++;
   sol[nrsol].nr_carute = ramase;
   sol[nrsol].cate = lmax;
   S = 0;
   for (i = 1; i <= lmax; i++)
   {
      sol[nrsol].care[i] = G1[deunde].nrG;
      S += G1[deunde].oca;
      G1[deunde].luat = true;
      deunde++;
   }
   sol[nrsol].oca_pe_caruta = S / ramase;
   ramase = ramase - lmax;
}

void afisare()
{
   int i, j;
   fout << nrsol << '\n';
   for (i = 1; i <= nrsol; i++)
   {
      fout << sol[i].nr_carute << ' ';
      fout << sol[i].oca_pe_caruta << ' ';
      fout << sol[i].cate << ' ';
      for (j = 1; j <= sol[i].cate; j++)
         fout << sol[i].care[j] << ' ';
      fout << '\n';
   }
}

int main()
{
   citire();
   while (ramase)
   {
      refa();
      Dirichlet_lung();
   }
   afisare();
   return 0;
}
