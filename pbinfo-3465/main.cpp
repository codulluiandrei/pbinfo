#include <bits/stdc++.h>
using namespace std;
#define NN 10000000
ifstream f("jocprim.in");
ofstream g("jocprim.out");
int ciur[NN + 1], v[NN + 1];
int main() {
  //algoritm de tip ciurul lui Eratostene(la final ciur[i] va fi cel mai mare divizor prim al lui i)
  for (int i = 2; i <= NN; i++)
    if (ciur[i] == 0)
  {
    ciur[i] = i;
    for (int j = 2; i * j <= NN; j++)
      ciur[i * j] = i;
  }
  int n, x, i, cnt = 0;
  f >> n;
  while (n--)
  {
    f >> x;
    if (v[ciur[x]] == 0)
      cnt++; //daca v[ciur[x]] este 0, inseamna ca apare o noua pereche
    v[ciur[x]]++; //numarul ciur[x] este cel mai mare divizor prim pentru inca un numar din sir(x)
  }
  g << cnt << '\n'; //afisam numarul de perechi
  for (i = 2; i <= NN; i++) //afisam perechile
    if (v[i]) //daca i este cel mai mare divizor prim pentru cel putin unul din termenii sirului
      g << i << " " << v[i] << '\n'; // afisam i si frecventa acestuia
  f.close();
  g.close();
  return 0;
}