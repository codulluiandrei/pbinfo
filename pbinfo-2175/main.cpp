//Marinel Serban
//100 puncte
#include <stdio.h>
#include <math.h>
#define MAX 60001
#define TRUE 1
#define FALSE 0
unsigned long N;
char Prime[MAX];
void TabelPrime(void)
{                                        //Ciurul lui Eratostene
  unsigned long i,j;                     //vectorul Prime va contine
  double Radical;                        //      1 pentru valori prime
                                         //      0 pentru valori neprime
  for (i=1; i<=MAX; i++) Prime[i]=TRUE;
  i=1;
  Radical=sqrt(MAX);
  while (i<=Radical)
	{
	  do
		{
		  i++;
		} while (!Prime[i]);
	  j=i*i;
	  while (j<=MAX)
		{
		  Prime[j]=FALSE;
		  j+=i;
		}
	}
}
int CitesteNumar(void)
{
  scanf("%lu", &N);
  return (N!=0);
}
unsigned long Descompune(unsigned long N, unsigned long d)
{
  unsigned long s;
//  if (N<p)           //varianta recursiva   
//	return 0;
//  else
//	return N/p + Descompune(N/p, p);
  s = 0;               //initializez contorul cu 0
  while (N>=d)         //cat timp d mai poate sa apara
    {
      s = s + N / d;   //d apare de N DIV d ori, le numar
      N = N / d;       //elimin aceste aparitii
    }
  return s;
}
void Rezolva(void)
{
  unsigned long i, j;
  i=2;
  while (!Prime[i]) i++;
  printf("%lu", Descompune(N, i));
  for (j=i+1; j<=N; j++)
	if (Prime[j]) printf(" %lu", Descompune(N,j));
  printf("\n");
}
int main()
{
  freopen("factori.in", "r", stdin);
  freopen("factori.out", "w", stdout);
  TabelPrime();
  while (CitesteNumar()) Rezolva();
  fclose(stdin);
  fclose(stdout);
  return 0;
}