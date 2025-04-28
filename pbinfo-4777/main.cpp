//Serban Marinel
#include <fstream>
#include <cassert>
using namespace std;
#define MAX 100
char s[MAX][50];                       //retin sponsorii
int Lg[MAX];                           //evidenta numar caractere
char Cap[11] =   {'O', 'L', 'I', 'M', 'P', 'I', 'A', 'D', 'A', 'D', 'E'};
char Coada[11] = {'I', 'N', 'F', 'O', 'R', 'M', 'A', 'T', 'I', 'C', 'A'};
int Cerinta, NrS, NrSol, SCorect, Cati[12];
ifstream fin ("sponsor.in");
ofstream fout ("sponsor.out");
void Citeste();
void Scrie();
int main()
{
   Citeste();
   Scrie();
   return 0;
}
void Citeste()
{
   int i, Lung, ok, k;
   char sp[50];
   fin >> Cerinta >> NrS;
   assert(Cerinta == 1 || Cerinta == 2);
   assert(11 <= NrS && NrS <= 50);
   fin.get();                    //citesc numarul de sponsori si CR
   SCorect = -1;
   for (i = 0; i < NrS; i++)     //citesc cei NrS sponsori si ii retin pe cei buni
   {
      fin.getline (sp, 50);      //citesc un sponsor
      Lung = 0;
      while (sp[Lung] != 0) Lung++;
      Lung--;                    //numarul de caractere
	  assert(1 <= Lung && Lung <= 32);
      ok = 0;                    //verific daca poate fi intr-o solutie
      for (k = 0; k < 11 && !ok; k++)
         if (sp[0] == Cap[k] && sp[Lung] == Coada[k])
            ok = 1;
      if (ok)                    //daca DA, il retin
      {
         SCorect++;
         for (k = 0; k <= Lung; k++)
            s[SCorect][k] = sp[k];
         Lg[SCorect] = Lung;    //lungimea nume sponsor i
         switch (sp[0])         //calculez de cate ori apare combinatia
         {
            case 'O': if (sp[Lung] == 'I') Cati[0]++; break;
            case 'L': if (sp[Lung] == 'N') Cati[1]++; break;
            case 'I': if (sp[Lung] == 'F') Cati[2]++;
                      else
                        if (sp[Lung] == 'M') Cati[5]++; break;
            case 'M': if (sp[Lung] == 'O') Cati[3]++; break;
            case 'P': if (sp[Lung] == 'R') Cati[4]++; break;
            case 'A': if (sp[Lung] == 'A') Cati[6]++;
                      else
                        if (sp[Lung] == 'I') Cati[8]++; break;
            case 'D': if (sp[Lung] == 'T') Cati[7]++;
                      else
                        if (sp[Lung] == 'C') Cati[9]++; break;
            case 'E': if (sp[Lung] == 'A') Cati[10]++; break;
         }
      }
   }
}
void Scrie()
{
   int i, j, k;
   if (Cerinta == 1)
   {
      NrSol = 1;                  //calculez numarul de solutii
      for (i = 0; i < 11; i++) NrSol *= Cati[i];
      fout << NrSol << '\n';      //si le afisez
   }
   else
   {
       //ordonez
       for (i = 0; i < SCorect; i++)//sortare prin selectie
          for (j = i + 1; j <= SCorect; j++)
          {
              k = 0;
              while (s[i][k] == s[j][k] && k <= min(Lg[i], Lg[j])) k++;
              if (s[i][k] > s[j][k])
              {
                  swap (s[i], s[j]);
                  swap (Lg[i], Lg[j]);
              }
          }
       //afisez
       for (i = 0; i < 11; i++)        //caut in ordine cele 11 cuvinte
         for (k = 0; k <= SCorect; k++)//in sirul de cuvinte posibile
            if (s[k][0] == Cap[i] && s[k][Lg[k]] == Coada[i])//la primul gasit
            {
               fout << s[k] << '\n';//afisez cuvantul
               break;
            }
   }
}