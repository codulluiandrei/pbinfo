//Marinel Serban - martie 2014
//citire caracter cu caracter
//nu utilizeaza nici o biblioteca, doar tipuri standard
#include <fstream>
#define NMAX 1000010
using namespace std;
ifstream fin("betisoare.in");
ofstream fout("betisoare.out");
int n, i;
long long suma, factor, valoare, termen;
char c, semn_urmator;
int main()
{
   fin >> n;
   fin.get();                             //trec de ENTER
   for (i = 1; i <= n; i++)
   {
      //calculeaza cea de-a i-a expresie
      suma = 0;                           //initializez suma
      termen = 1;                         //initializez termen
      factor = 0;                         //iitializez factor
      fin.get(c);
      while (c != '+' && c != '*' && c != '\n')//primul termen/factor
      {
         factor++;
         fin.get(c);
      }
      semn_urmator = c;                   //retin semnul urmator
      while (c != '\n')                   //cat timp mai am termeni sau factori
      {
         if (semn_urmator == '+' || c == '\n')
            {                             //adun termenul
                termen *= factor;
                suma += termen;
                termen = 1;
            }
         else
            termen *= factor;             //inca e produs
         factor = 0;                      //reinitializez factorul
         fin.get(c);
         while (c != '+' && c != '*' && c != '\n') //alt factor
         {
            factor++;
            fin.get(c);                   //urmatorul semn
         }
         semn_urmator = c;                //il retin
      }
      if (suma == 0)
         suma = termen * factor;
      else
         suma += termen * factor;
      fout << suma << '\n';               //afisez rezultat
   }
   fout.close();
   return 0;
}