#include <fstream>
#define InFile  "afise.in"
#define OutFile "afise.out"
#define Max 1001
using namespace std;
struct Afis
{
    int bed, alb;
};
Afis S[Max];
int L, N, K, M;
int Viz[Max];
void Read()
{
  int x, bed, alb, i;
  ifstream in(InFile);
  in>>L>>N>>K;
  for(i=1; i<=N; i++)
    { in>>x; Viz[x]=1; }
  // marcate zonele ce trebuie acoperite
  in.close();
  i=1;
  bed = alb = 0;
  while(!Viz[i] && i<=L) i++;
  while(i <= L)
   { while(Viz[i] && i<=L)  { bed++; i++; }
     while(!Viz[i] && i<=L) { alb++; i++; }
     // determin lungimea zonelor rele urmate de zone ok
     M++;
     S[M].bed = bed;
     S[M].alb = alb;
     bed = alb = 0;
   }
   M--;
}
// ordonare crescatoare dupa zonele ok
int poz(int p, int u)
{
  int st, dr;
  st = p; dr=u;
  Afis aux=S[p];
  while(st < dr)
    { while(st<dr && aux.alb <= S[dr].alb) dr--;
      S[st]=S[dr];
      while(st<dr && aux.alb >= S[st].alb) st++;
      S[dr]=S[st];
    }
  S[st]=aux;
  return st;
}
void Quik(int p, int u)
{
  int m=poz(p,u);
  if(p<m) Quik(p,m-1);
  if(m<u) Quik(m+1,u);
}
void Write()
{
  int i, nK, St;
  ofstream out(OutFile);
  St=nK=0;
  M++;
  for(i=1; i<=M; i++) St+=S[i].bed;
  //zone care obligatoriu trebuie acoperite
  nK = M;
  if(M>K) { i = 1;
	    while(nK>K && i<=M)
	      { St += S[i].alb; i++; nK--; }
	    // folosesc spatiile albe pentru a reduce numarul de panouri
	  }
  out<<St<<" "<<nK<<"\n";
  out.close();
}
int main()
{
  Read();
  Quik(1, M);
  Write();
  return 0;
}