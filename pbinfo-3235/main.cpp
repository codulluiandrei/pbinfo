#include<bits/stdc++.h>
using namespace std;
ifstream fin ("entries.in");
ofstream fout ("entries.out");
map<int, int> M;
map<int, int> :: iterator it;
int t[10005], n;
int Find(int x)
{
  int z,y;
  y = x;
  while (t[x]!=0)
     x = t[x];
  while (t[y]!=0)
  {
     z = t[y];
     t[y] = x;
     y = z;
  }
  return x;
}
inline void Union(int x, int y)
{
    t[y] = x;
}
int main ()
{
    int T, x, y, op, k;
    fin >> T;
    while (T--)
    {
        fin >> x >> y >> op;
        k = 0;
        it = M.find(x);
        if (it == M.end()) {k = 1; n++; M[x] = n;}
        it = M.find(y);
        if (it == M.end()) {k = 1; n++; M[y] = n;}
        x = M[x];
        y = M[y];
        x = Find(x);
        y = Find(y);
        if (op == 1)
        {
            if (x != y) Union(x, y);
        }
        else
        {
            if (k == 1) fout << "0\n";
            else if (x == y) fout << "1\n";
            else fout << "0\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}