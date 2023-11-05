//prof. Marinel Serban
#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("bucati.in");
ofstream fout("bucati.out");

int cerinta, n, cn, p10, nrc, c_nrc;
int vmax, c1, c2, v, vmin, x, d;

int main()
{
   fin >> cerinta >> n;                 //citesc datele
   assert(cerinta == 1 || cerinta == 2);
   assert(999 < n && n < 1000000000); 

   cn = n;                              //pastrez n
   nrc = 0;                             //contor cifre
   p10 = 1;                             //initializez puterea lui 10
   while (cn)                           //mai am cifre?
   {                                    //determin
      nrc++;                            //numarul de cifre
      p10 *= 10;                        //puterea lui 10
      cn /= 10;                         //scap de ultima cifra
   }
   c_nrc = nrc;                         //pastrez numarul de cifre
   p10 /= 10;                           //pentru rotire
   if (cerinta == 1)      //cerinta 1
   {
      vmax = n / 100; c1 = n / 10 % 10; c2 = n % 10;//initializez
      while (nrc)                       //repet de nrc ori
      {
         if (n / 100 > vmax)            //daca gasesc o valoare mai mare
         {                              //pastrez
            vmax = n / 100; c1 = n / 10 % 10; c2 = n % 10;
         }
         n = n % 10 * p10 + n / 10;     //rotesc cifrele
         nrc--;                         //am mai testat o valoare
      }
      fout << vmax + c1 + c2 << '\n';   //afisez suma maxima
   }
   else                   //cerinta 2
      {
         vmin = 9973;   //cel mai mare numar prim in conditiile problemei
         while (nrc)
         {                          //incerc prima data cu 2 cifre + cifre
            v = n % 100;                //ultimele 2 cifre
            //if (v > 9)                //are 2 cifre dar poate fi chiar 00
            {
               x = n / 100;             //valoarea fara ultimele 2 cifre
               while (x)                //fac suma dintre v si restul cifrelor
               {
                  v += x % 10;
                  x /= 10;
               }
               if (v < vmin)            //doar asa are rost sa verific primalitatea
               {
                  d = 2;
                  while (d * d <= v && v % d != 0) d++;
                  if (d * d > v)
                     vmin = v;
               }
            }
            n = n % 10 * p10 + n / 10;  //rotesc cifrele
            nrc--;                      //am mai testat o valoare
         }
         if (vmin == 9973)       //NU am gasit cu 2 cifre
         {
            nrc = c_nrc;         //refac numarul de cifre
            while (nrc)          //incerc cu 3 cifre + restul cifrelor
            {
               v = n % 1000;               //ultimele 3 cifre
               //if (v > 99)               //are 3 cifre dar poate fi chiar 000
               {
                  x = n / 1000;            //valoarea fara ultimele 3 cifre
                  while (x)                //fac suma dintre v si restul cifrelor
                  {
                     v += x % 10;
                     x /= 10;
                  }
                  if (v < vmin)            //doar asa are rost sa verific primalitatea
                  {
                     d = 2;
                     while (d * d <= v && v % d != 0) d++;
                     if (d * d > v)
                        vmin = v;
                  }
               }
               n = n % 10 * p10 + n / 10;  //rotesc cifrele
               nrc--;                      //am mai testat o valoare
            }
            fout << vmin << '\n';          //sigur am gasit acum (enunt)
         }
         else
            fout << vmin << '\n';          //am gasit solutie cu 2 cifre
      }
   return 0;
}