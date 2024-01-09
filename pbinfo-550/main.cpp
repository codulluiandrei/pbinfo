//Complexitate O(N^2) timp si memorie
//Metoda: Greedy pe arbore

#include <fstream>
using namespace std;

const int N = 1005;

ifstream fin ("mere.in");
ofstream fout ("mere.out");

int n, v[N], sum;
bool a[N][N];

void dfs(int x, int father) {
    sum += v[x];
    int poz = 0;
    for (int i = 1; i <= n; ++i)
        if (i != father && a[x][i] && v[poz] < v[i])
            poz = i;
    if (poz)
        dfs(poz, x);
}

int main() {
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 0, x, y; i < n; ++i) {
        fin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    dfs(1, -1);
    fout << sum;
}
