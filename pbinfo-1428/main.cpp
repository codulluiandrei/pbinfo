/*
    Author: Rusu Daniel
    Verdict: 100/100pct
    Complexity: O(log2(N))
*/
#include <fstream>
using namespace std;
ifstream fin("sume1.in");
ofstream fout("sume1.out");
#define MOD 1000000007
long long N;
long long rise(long long base, long long power) {
    if(power == 0) {
        return 1;
    }
    long long x = rise(base, power / 2);
    if(power % 2 == 0) {
        return (x * x) % MOD;
    }
    return (((x * x) % MOD) * base) % MOD;
}
int main() {
    fin >> N;
    fout << (rise(2, N + 1) + MOD - 1) % MOD << '\n';
    fin.close();
    fout.close();
    return 0;
}