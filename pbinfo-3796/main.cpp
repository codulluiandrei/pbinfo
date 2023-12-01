#include <bits/stdc++.h>

#define N_MAX 100005

using namespace std;

ifstream fin("qtsume.in");
ofstream fout("qtsume.out");

int N, Q;
int x, y;
long long A[N_MAX], S[N_MAX];

int main()
{
    fin >> N;
    for(int i = 1; i <= N; i++) {
        fin >> A[i];
        S[i] = S[i - 1] + i * A[i];
        A[i] += A[i - 1];
    }

    for(fin >> Q; Q; Q--) {
        fin >> x >> y;
        fout << S[y] - S[x - 1] - (x - 1) * (A[y] - A[x - 1]) << "\n";
    }
    return 0;
}
