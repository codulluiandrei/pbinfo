//Marinel Serban - 2018
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("careu.in");
ofstream fout("careu.out");
#define NMAX 55
char l[NMAX][NMAX], l_cuv[NMAX * 10 + NMAX][NMAX];  //lista cuvintelor
char linie[NMAX];                       //linie fisier
unsigned int n, n_cuv, l_max, cerinta;  //nr linii date, nr.cuvinte, lung maxima cuvant
bool cauta(char c[NMAX])
{
   unsigned int i;
   for (i = 1; i <= n_cuv; i++)
      if (strcmp(c, l_cuv[i]) == 0) return true;
   return false;
}
void ordonare()
{
   unsigned int i, j;
   for (i = 1; i < n_cuv; i++)
      for (j = i + 1; j <= n_cuv; j++)
         if (strcmp(l_cuv[i], l_cuv[j]) > 0)
            swap(l_cuv[i], l_cuv[j]);
}
bool palindrom(char c[NMAX])
{
   int p, u;
   if (strlen(c) <= 2) return false;
   p = 0;
   u = strlen(c) - 1;
   while (p < u)
   {
      if (c[p] != c[u])  return false;
      p++;
      u--;
   }
   return true;
}
void prelucrare()
{
   char cuv[NMAX];
   unsigned int i, j = 0;
   strcpy(cuv, "");
   strcat(linie, ".");
   for (i = 0; i < strlen(linie); i++)
      if (linie[i] != '.')
         cuv[j++] = linie[i];
      else
      {
         cuv[j] = 0;                  //pun null la sfarsit
         if (palindrom(cuv))          //daca e palindrom
         {
            if (strlen(cuv) > l_max)  //si e mai lung ca celelalte
            {
               l_max = strlen(cuv);   //retin lungimea
               n_cuv = 1;             //am gasit primul palindrom de lungimea asta
               strcpy(l_cuv[1], cuv); //il retin
            }
            else if (strlen(cuv) == l_max && !cauta(cuv))
            {      //daca are aceiasi lungime si NU l-am mai pus
               n_cuv++;                   //il numar
               strcpy(l_cuv[n_cuv], cuv); //il retin
            }
         }
         strcpy(cuv, "");             //reinitializez cuv pentru alt cuvant
         j = 0;
      }
}
void princ()
{
   unsigned int i, j;
   fin >> n; fin.get();
   for (i = 1; i <= n; i++)
   {
      fin.getline(l[i], n + 1);   //citesc linia
      strcpy(linie, l[i]);        //o copiez in linia de prelucrare
      prelucrare();               //...
   }
   for (j = 0; j < n; j++) //prelucrare coloane
   {
      strcpy(linie, "");          //formez linia de prelucrare pe cooane
      for (i = 1; i <= n; i++)    //copiez caracter cu caracter
         linie[i-1] = l[i][j];
      linie[i] = 0;               //inchid linia
      prelucrare();               //...
   }
   fin >> cerinta;
}
void scrie()
{
   unsigned int tot, i, j;
   bool este[30];
   char c;
   if (n_cuv == 0)                    //nu am nici un cuvant special detectat
      fout << 0 << '\n';
   else
   {
      ordonare();                     //ordonez cuvintele
      for (c = 'A'; c <= 'Z'; c++)    //resetez vectorul de litere
         este[c-'A'] = false;
      for (i = 1; i <= n_cuv; i++)
         for (j = 0; j < strlen(l_cuv[i]); j++)
            este[l_cuv[i][j]-'A'] = true; //aceasta litera apare
      tot = 0;                        //suma pe 0
      for (c = 'A'; c <= 'Z'; c++)
         if (este[c-'A'])             //daca litera apare
            tot += c;                 //adun codul
      if (cerinta == 1)
      {
         fout << n_cuv << '\n';          //afisari
         for (i = 1; i <= n_cuv; i++)
            fout << l_cuv[i] << '\n';
      }
      else
         fout << tot << '\n';
   }
}
int main()
{
   princ();
   scrie();
   return 0;
}