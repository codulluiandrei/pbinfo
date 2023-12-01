#include <stdio.h>

char s[55001];
long imax, jmax, Lmax, n, k;
long f[91];

void Citeste();
void Afis();
void Calculeaza();

int main()
{
   freopen("teatru.in", "r", stdin);
   freopen("teatru.out", "w", stdout);
   Citeste();
   Calculeaza();
   Afis();
   return 0;
}

void Citeste()
{
   scanf("%d%d", &n, &k);  
   scanf("%c", &s[0]);  // citeste '\n' 
   for (long int i = 0; i < n; i++ )   
		scanf("%c", s + i);
}
      
void Afis()
{
   printf("%d\n", Lmax);
   for (long int i = imax; i <= jmax; i++ )
      printf("%c", s[i]);
   printf("\n");
}

void Calculeaza()
{
   long int i = 0, j = 0, nr = 0;
   f[s[0]]++; nr++;
   do
   {
      while (nr <= k && j < n) 
      {
         j++;
         if ( j >= n ) break;
         if (f[s[j]] == 0)
         {
            f[s[j]]++;
            nr++;
         }   
         else f[s[j]]++;
      }   
      if (j - i  > Lmax)
      {
         Lmax = j - i;
         imax = i; jmax = j - 1;

      }   

      while ( nr > k ) 
      {
         f[s[i]]--;
         if ( f[s[i]] == 0 ) nr--;
         i++;
      }
   } while  (i < n   && j < n);   
}


