/* Secvente - O(N)
 * Florian Usurelu
 * scor: 100
 */
#include <bits/stdc++.h> 
using namespace std; 
ifstream f ("secvente.in"); 
ofstream g ("secvente.out"); 
const int nmax = 1e6 + 3; 
char s[nmax]; 
int v[nmax], n, st[nmax], dr[nmax], k, sum, sol; 
int main() 
{ 
    f >> n >> k >> (s + 1); 
    for (int i = 1; i <= n; ++i) 
    { 
        v[i] = s[i] - '0'; 
        sum += v[i]; 
    } 
    if (sum < 2 * k) 
    { 
        g << -1; 
        return 0; 
    } 
    sum = 0; 
    for (int i = 1; i <= n; ++i) 
    { 
        sum += v[i]; 
        if(i - k >= 1) 
        { 
            sum -= v[i - k]; 
            st[i] = max(sum, st[i - 1]); 
        } 
        if(i == k) st[i] = sum; 
    } 
    sum = 0; 
    for (int i = n; i >= 0; --i) 
    { 
        sum += v[i]; 
        if(i + k <= n) 
        { 
            sum -= v[i + k]; 
            dr[i] = max(sum, dr[i + 1]); 
        } 
        if(i == n - k + 1) dr[i] = sum; 
    } 
    sol = 2e9; 
    for (int i = k; i + 1 <= n - k + 1; ++i) 
        sol = min(sol, 2 * k - st[i] - dr[i + 1]); 
    g << sol; 
    return 0; 
}  