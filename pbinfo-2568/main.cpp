#include <bits/stdc++.h>
using namespace std;
ifstream f("cubprim.in");
ofstream g("cubprim.out");
struct primecubes {
    unsigned long long cube;
    int idx, root;
    bool operator < (const primecubes &e) const {
        if(root != e.root) return root > e.root;
        return idx < e.idx;
    }
} v[200001]; 
unsigned long long x;
char p[187501];
int a[200001];
int N, M, aux;
void GetPrimeNumbers(const int N) {   
    for(int i = 1;((i * i) << 1) + (i << 1) <= N;i++) {
        if((p[i >> 3] & (1 << (i & 7))) == 0) {
            for(int j = ((i * i) << 1) + (i << 1);(j << 1) + 1 <= N;j += (i << 1) + 1) {
                p[j >> 3] |= (1 << (j & 7));
            }
        }
    }
    a[++a[0]] = 2;
    for(int i = 1;(i << 1 | 1) <= N;++i)  
        if((p[i >> 3] & (1 << (i & 7))) == 0) 
            a[++a[0]] = (i << 1 | 1);
}
int CheckCube(unsigned long long x) {
    int l = 1, r = a[0];
    while(l <= r) {
        int m = (l + r) / 2;
        if(1ULL * a[m] * a[m] * a[m] == x) {
            return a[m];
        }else if(1ULL * a[m] * a[m] * a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}
int main() {
    GetPrimeNumbers(2642239);
    f >> N;
    for(int i = 1;i <= N;i++) {
        f >> x;
        aux = CheckCube(x);
        if(aux != -1)
            M++, v[M].idx = i, v[M].root = aux, v[M].cube = x;
    }
    sort(v + 1, v + M + 1);
    g << M << "\n";
    for(int i = 1;i <= M;i++) {
        g << v[i].idx << " " <<  v[i].root << " " <<  v[i].cube;
        if(i < M) g << "\n";
    }
    return 0;
}