//Complexitate O(N * logN) timp O(N) memorie
//Greedy cu Quicksort

#include <fstream>
using namespace std;

ifstream fin ("flici.in");
ofstream fout ("flici.out");

const int N = 1e5 + 5;

int v[N], c[N], n, sol;

int abs (int x) {
    return x > -x ? x : -x;
}

void Quicksort (int v[], int left, int right) {
    int i = left, j = right, pivot = v[abs((i + j) >> 1)];
    while (i <= j) {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j) {
            swap (v[i], v[j]);
            i++, j--;
        }
    }
    if (left < j)
        Quicksort (v, left, j);
    if (i < right)
        Quicksort (v, i, right);
}

int main() {
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    for (int i = 0; i < n; ++i)
        fin >> c[i];
    Quicksort (v, 0, n-1);
    Quicksort (c, 0, n-1);
    for (int i = 0; i < n; ++i)
        sol += abs (v[i] - c[i]);
    fout << sol;
}
