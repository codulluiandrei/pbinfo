/**
Autor: Bogdan-Ioan Popa, FMI Universitatea din Bucuresti
Scor: 100p
**/
#include <bits/stdc++.h>
#define N_MAX 100000
#define V_MAX 1000000
using namespace std;
ifstream fin("pseudocmp.in");
ofstream fout("pseudocmp.out");
int P, N;
int A[N_MAX + 5];
int freq[V_MAX + 5];
int dig_sum(int x) {
    int ret = 0;
    while(x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main()
{
    fin >> P >> N;
    for(int i = 1; i <= N; i++) {
        fin >> A[i];
        freq[A[i]]++;
    }
    int L = 0;
    for(int i = 1; i <= V_MAX; i++) {
        while(freq[i]--) {
            A[++L] = i;
        }
        freq[i] = 0;
    }
    if(P == 1) {
        for(int i = 2; i <= N; i++) {
            if(dig_sum(A[i - 1]) > dig_sum(A[i])) {
                fout << A[i - 1] << " " << A[i] << "\n";
                return 0;
            }
        }
        fout << "-1\n";
        return 0;
    }
    if(P == 2) {
        long long ans = 0;
        for(int i = 1; i <= N; i++) {
            int sum = dig_sum(A[i]);
            for(int j = sum + 1; j <= 54; j++) {
                ans += freq[j];
            }
            freq[sum]++;
        }
        fout << ans << "\n";
    }
    return 0;
}