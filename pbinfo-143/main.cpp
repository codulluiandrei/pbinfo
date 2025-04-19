#include <fstream>
using namespace std;

long long F[30], poz, x, sum;
long long P[30];
long long i, n, j, k, Q, nr;
long long v[30];

int main() {
    F[1] = F[0] = 1;
    for (i = 2; i <= 19; i++)
        F[i] = i * F[i - 1];

    ifstream fin("permutari3.in");
    ofstream fout("permutari3.out");

    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> P[i];

    for (i = 1; i < n; i++) {
        poz = poz + (P[i] - 1) * F[n - i];
        for (j = i + 1; j <= n; j++)
            if (P[j] > P[i])
                P[j]--;
    }

    fin >> Q;
    for (; Q; Q--) {
        fin >> x;
        x += poz;

        // Construct the x-th permutation
        for (i = 1; i <= n; i++)
            v[i] = 1;

        for (i = 1; i <= n; i++) {
            sum = 0;
            j = 0;

            while (sum <= x) {
                sum += F[n - i];
                j++;
            }

            sum -= F[n - i];
            x -= sum;

            // Find the j-th marked element in v
            nr = 0;
            for (k = 1; k <= n; k++) {
                nr += v[k];
                if (nr == j)
                    break;
            }

            fout << k << " ";
            v[k] = 0;
        }
        fout << "\n";
    }
    return 0;
}
