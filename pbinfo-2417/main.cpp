#include <fstream>
#include <cstring>
using namespace std;
char mesaj[1001], cheie[21], c;
int lgm, lgc, l, i, j, apare, cate, col, gasit, k;
int cod[201][21], alfabet[27];
ifstream f("criptare1.in");
ofstream g("criptare1.out");
void citire()
{
  f.getline(mesaj, 1001);
  f.getline(cheie, 21);
  f.close();
}
void decriptare()
{
  lgm=strlen(mesaj);
  lgc=strlen(cheie);
  cate=lgm/lgc;
  apare=0;
  for (c='a'; c<='z'; c++)
    {
      for (i=0; i<lgc; i++)
      if (cheie[i]==c)
	{
	  apare++;
	  alfabet[c-'a'+1]=apare;
	}
    }
  l=0;
  for (i=0; i<lgc; i++)
    for (j=1; j<=26; j++)
      if (alfabet[j]==i+1) ///am gasit litera a i-a (ca numerotare in cheie)
	{
	  ///caut pe ce pozitie in cheie este ca sa determin coloana
	  col=0; gasit=0;
	  while (!gasit)
	    {
	      if (cheie[col]==(char)(j+'a'-1))
		gasit=1;
	      col++;
	    }
	  for (k=1; k<=cate; k++)    //pun in coloana col
	    cod[k][col]=mesaj[l++];
	}
  for (i=1; i<=cate; i++)
    for (j=1; j<=lgc; j++)
      if ((char)cod[i][j]!='*')
	g<<(char)cod[i][j];
      else
	g<<' ';
  g<<endl;
  g.close();
}
int main()
{
  citire();
  decriptare();
  return 0;
}