//100 puncte EmCerchez
#include <fstream>
#include <cstring>
#include <cassert>
#define NMAX 16
#define LGS 16
#define LGMAX 15000000
using namespace std;
ifstream fin("expand.in");
ofstream fout("expand.out");
int N, start, lgs;
char G[26][NMAX][LGS];
int lg[26];
char  s[LGS];
struct element {short int nr;
                char s[LGS];};
element C[LGMAX];
void citire();
int BFS(int start);
int main()
{
    citire();
    fout<<BFS(start)<<'\n';
    fout.close();
    return 0;
}
void citire()
{char L, c;
 int i, j, lllg;
 fin>>L>>s>>N;
 assert('a'<=L && L<='z');
 lgs=strlen(s);
 assert(lgs<=15);
 assert(N<=15);
 start=L-'a';
 for (i=0; i<N; i++)
      {
       fin>>c;
       assert('a'<=c && c<='z');
       fin>>G[c-'a'][lg[c-'a']];
       lllg=strlen(G[c-'a'][lg[c-'a']]);
       assert(lllg==2 || lllg==3);
       lg[c-'a']++;
      }
}
int BFS(int start)
{
int inc=0, sf=0, i, j, k, lgx,t,z;
element x;
C[0].nr=0; C[0].s[0]=start+'a'; C[0].s[1]=0;
while (inc<=sf)
      {
        x=C[inc++];
        lgx=strlen(x.s);
        for (i=0; i<lgx; i++)
             {
               j=x.s[i]-'a';
               for (k=0; k<lg[j]; k++)
                   if (lgx-1+strlen(G[j][k])<=lgs)
                        {
                          ++sf; if (sf==LGMAX) return -2;
                          C[sf].nr=x.nr+1;
                          for (t=0; t<i; t++) C[sf].s[t]=x.s[t];
                          for (z=0; G[j][k][z]; z++) C[sf].s[t+z]=G[j][k][z];
                          for (t=i+1; x.s[t]; t++) C[sf].s[t+z-1]=x.s[t];
                          C[sf].s[t+z-1]=0;
                          if (strcmp(C[sf].s,s)==0) return C[sf].nr;
                        }
                }
      }
   return -1;
}