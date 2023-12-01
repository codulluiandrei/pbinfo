#include <bits/stdc++.h> 
using namespace std; 
  
ifstream f ("tomi.in"); 
ofstream g ("tomi.out"); 
  
const int nmax = 1e5 + 3; 
  
long long v[nmax], usu, act; 
int n, nr, k; 
  
int main() 
{ 
    f >> n >> k; 
  
    for (int i = 1; i <= n; ++i) 
        f >> v[i]; 
  
    usu = (1ll<<60) - 1ll; 
  
    for (long long i = 59; i >= 0; --i) 
    { 
        act = usu ^ (1ll<<i); 
  
        nr = 0; 
        for (int j = 1; j <= n; ++j) 
            if ((v[j] | act) == act) ++nr; 
  
        if (nr >= k) 
            usu = act; 
    } 
  
    g << usu << '\n'; 
    g.close();
    return 0; 
} 