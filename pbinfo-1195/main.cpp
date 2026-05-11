// sursa cu combinari + Legendre
// prof. Chesca Ciprian
#include <fstream>
#define M 666013
#define nmax 1000001
using namespace std;
int n,k,w;
ifstream f("nmult.in");
ofstream g("nmult.out");
char v[nmax];
int p[nmax/10],desc[nmax/10],nr=0;
// Ciurul lui Eratostene
void ciur(int n)
{
  int i, j;
  for (i = 2; i <= n; ++i) {
    if (v[i] == 0) {
      p[++nr]=i;
      for (j = i + i; j <= n; j += i) {
        v[j] = 1;
      }}}
}
// descompunere in factori primi a lui x! cu Legendre
void dsc(int x,int op)
{
long long i,s,pp,ok;
for(i=1;i<=nr;i++)
{
	s=0;pp=p[i];ok=1;
	while (ok)
	{
		s=s+x/pp;
		if (x/pp==0) ok=0;
		pp=pp*p[i];
	}
	if (op==1) 	desc[i]+=s;
		else	desc[i]-=s;
}}
int mdl()
{
long long i,j,pp=1,r=1;
for(i=1;i<=nr;i++)
{
	pp = 1;
	for(j=1;j<=desc[i];j++)
		pp = (pp*p[i]) % M;
	r = (r*pp) % M;
}
return r;
}
int main()
{
    f>>n>>k>>w;
    ciur(n-(w-1)*(k-1));
    dsc(n-(w-1)*(k-1),1);
    dsc(k,0);
    dsc(n-(w-1)*(k-1)-k,0);
    if (n-(k-1)*(w-1)<k) g<<"0"<<"\n";
	else g<<mdl();
    f.close();
    g.close();
    return 0;
}