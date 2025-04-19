//Marinel Serban - ianuarie 2017
#include <bits/stdc++.h>
using namespace std;
ifstream fin("3cifre.in");
ofstream fout("3cifre.out");
unsigned int n, cerinta, i, nrmaxap, nrmin = 1000, nrapmin, nrmax = 99, nrapmax, nr3cifre;
unsigned int x1min, x1max, x2min, x2max;
unsigned int x, copiex;
int VF[1010];
int main()
{
   fin >> n >> cerinta;
   while (n > 0)                       //cat timp mai am numere
   {
      fin >> x;                        //citesc un n umar
      copiex = x;
      while (x > 99)                   //cat timp are cel putin 3 cifre
      {
         nr3cifre = x % 1000;          //extrag un numar din 3 cifre alaturate
         if (nr3cifre > 99)             //este din 3 cifre?
         {
            if (cerinta == 1)           //cerinta 1
            {
               if (nr3cifre < nrmin)    //am gasit un nou minim?
               {
                  nrmin = nr3cifre;     //retine
                  nrapmin = 1;          //apare prima data
                  x1min = copiex;       //in acest numar
                  x1max = copiex;       //deocamdata el este si ultimul
               }
               else
                  if (nr3cifre == nrmin)//este egal cu minimul curent?
						{
							nrapmin++;         //contorizeaza
							x1max = copiex;    //ultima aparitie
						}
               if (nr3cifre > nrmax)    //am gasit un nou maxim?
               {
                  nrmax = nr3cifre;     //retine
                  nrapmax = 1;          //apare prima data
                  x2min = copiex;       //in acest numar
                  x2max = copiex;       //deocamdata el este si ultimul
               }
               else
                  if (nr3cifre == nrmax)//este egal cu maximul curent
						{
							nrapmax++;         //contorizeaza
							x2max = copiex;    //ultima aparitie
						}
            }
            else                        //este cerinta 2
               {
                  VF[nr3cifre]++;       //contorizeaza in VF
                  if (VF[nr3cifre] > nrmaxap)  //numar maxim de aparitii
                     nrmaxap = VF[nr3cifre];   //actualizat permanent
               }
         }
         x /= 10;                       //elimina ultima cifra din x
      }
      n--;                              //am terminat un numar
   }
   if (cerinta == 1)                    //afisare cerinta 1
   {
      fout << nrmin << ' ' << nrapmin << ' ' << x1min << ' ' << x1max << '\n';
      fout << nrmax << ' ' << nrapmax << ' ' << x2min << ' ' << x2max << '\n';
   }
   else
   {
	   fout << nrmaxap << '\n';
      for (i = 100; i <= 999; i++)      //parcurg vectorul de frecventa
         if (VF[i] == nrmaxap)
            fout << i << ' ';           //afisare cerinta 2
      fout << '\n';
   }
   return 0;
}