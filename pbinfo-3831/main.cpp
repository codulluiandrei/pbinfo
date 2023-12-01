#include <bits/stdc++.h> 
#pragma warning (disable : 26451) 
#pragma warning (disable : 4996) 
using namespace std; 
ifstream fin("medians.in"); 
ofstream fout("medians.out"); 
#define MAXN 100005 
int a[MAXN], b[2 * MAXN]; 
int n; 
int query(int p) { 
    int t = 0; 
    for (int i = (p + MAXN); i; i -= (i & -i)) { 
        t += b[i]; 
    } 
    return t; 
} 
void update(int p, int val) { 
    for (int i = (p + MAXN); i < 2 * MAXN; i += (i & -i)) { 
        b[i] += val; 
    } 
} 
long long solve(long long k) { 
    long long s = 0; 
    for (int i = 0; i < 2 * MAXN; ++i) { 
        b[i] = 0; 
    } 
    long long total = 0; 
    update(0, 1); 
    for (int i = 0; i < n; ++i) { 
        s += (a[i] > k ? -1 : 1); 
        total += query(s); 
        update(s, 1); 
    } 
    return total; 
} 
int main() { 
    long long k; 
    fin >> n >> k; 
    for (int i = 0; i < n; ++i) { 
        fin >> a[i]; 
    } 
    fout << solve(k) - solve(k - 1); 
}