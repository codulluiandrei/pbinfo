/* Stud. Buca Mihnea-Vicentiu 
   Facultatea de Matematica si Informatica 
   O(nlogV_MAX) 
*/
#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("pietricele.in"); 
ofstream fout("pietricele.out"); 
int cost[30];
int c, n, k; 
char s[200005];  
int main() { 
    fin >> c >> n >> k; 
    fin >> s; 
    for (int i = 0; i < 26; ++i) 
        fin >> cost[i]; 
    /* cerinta 1 */
    if (c == 1) { 
        assert(c == 1); 
        assert(1 <= n and n <= 200000); 
        assert(1 <= k and k <= n); 
        long long sol = 0, sum = 0; 
        k = n - k + 1; 
        for (int i = 0; i < n; ++i) { 
            sum += cost[s[i] - 'a']; 
            if (i >= k) sum -= cost[s[i - k] - 'a']; 
            sol = std::max(sol, sum); 
        } 
        fout << sol; 
        return 0; 
    } 
    assert(c == 2); 
    assert(1 <= n and n <= 200000); 
    assert(1 <= k and k <= n); 
    /* cerinta 2 */
    long long st = 1, dr = 1e18, sol = -1; 
    while(st <= dr){ 
        long long mij = (st + dr) / 2, sum = 0, ct = 0; 
        for (int i = 0; i < n; i++) { 
            sum += cost[s[i] - 'a']; 
            if (sum >= mij) { 
                ++ct; 
                sum = 0; 
            } 
        } 
        if (ct >= k) { 
            sol = mij; 
            st = mij + 1; 
        } else { 
            dr = mij - 1; 
        } 
    } 
    fout << sol; 
}