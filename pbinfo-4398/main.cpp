//Em. Cerchez 100 puncte
#include <fstream>
#define NMAX 50002
#define LGMAX 102
using namespace std;
ifstream fin("palindrom.in");
ofstream fout("palindrom.out");
int n, c, S, lg, lgmax;
long long int sum;
int nr[NMAX];
int v[LGMAX];
int main()
{int i, j, st, dr, inceput;
 char ch;
 fin>>c>>n; fin.get(ch);
 for (i=1; i<=n; i++)
      {//citeste un numar
       ch=0; lg=0;
       while (1)
             {fin.get(ch);
              if (ch=='\n') break;
              v[++lg]=ch-'0';
             }
       //determin numarul minim de cifre care tb adaugate la finalul lui v pt a deveni palindrom
       for (j=1; j<lg; j++)
           {
            for (st=j, dr=lg; st<dr && v[st]==v[dr]; st++, dr--);
            if (st>=dr) break;
           }
       nr[i]=j-1;
      }
   if (c==1)
      { sum=0;
        for (i=1; i<=n; i++) sum+=nr[i];
        fout<<sum<<'\n';
      }
      else
      {
       fin>>S;
       //determinam in nr o secventa de lungime maxima cu suma elementelor <=S
       sum=0; inceput=1;
       for (i=1; i<=n; i++)
           if (sum+nr[i]<=S)
               sum+=nr[i];
               else
               {
                if (i-inceput>lgmax) lgmax=i-inceput;
                while (inceput<=i && sum+nr[i]>S)
                       sum-=nr[inceput++];
                if (sum+nr[i]<=S) sum+=nr[i];
                }
        if (i-inceput>lgmax) lgmax=i-inceput;
        fout<<lgmax<<'\n';
      }
  return 0;
}