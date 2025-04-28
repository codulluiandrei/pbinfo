#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>
std::ifstream fin("distanta.in");
std::ofstream fout("distanta.out");
struct Oras
{
    int timp = 0;
    std::string nume;
};
typedef std::vector<std::vector<int>> mat;
int n, start, final;
mat V;
std::vector<Oras> oras;
std::vector<int> distanta, root;
std::map<std::pair<int, int>, int> cost;
inline void citire()
{
    int m, aux;
    std::string i, j;
    std::unordered_map<std::string, int> convert;
    fin >> n;
    V.resize(1LL * n + 1);
    oras.resize(1LL * n + 1);
    distanta.resize(1LL * n + 1);
    root.resize(1LL * n + 1);
    for (int k = 1; k <= n; ++k)
    {
        fin >> oras[k].nume >> oras[k].timp;
        convert[oras[k].nume] = k;
    }
    for (fin >> m; m; --m)
    {
        fin >> i >> j >> aux;
        cost[{ convert[i], convert[j] }] = aux;
        cost[{ convert[j], convert[i] }] = aux;
        V[convert[i]].push_back(convert[j]);
        V[convert[j]].push_back(convert[i]);
    }
    fin >> i >> j;
    start = convert[i];
    final = convert[j];
}
inline void bfs(int j)
{
    int aux;
    std::queue<int> Q;
    root[j] = j;
    distanta[j] = oras[j].timp;
    Q.push(j);
    while (!Q.empty())
    {
        j = Q.front(), Q.pop();
        for (auto const& i : V[j])
        {
            aux = distanta[j] + cost[{i, j}] + oras[i].timp;
            if (!distanta[i] || aux <= distanta[i])
                distanta[i] = distanta[j] + cost[{i, j}] + oras[i].timp,
                root[i] = j, Q.push(i);
        }
    }
}
inline void display()
{
    if (distanta[start] == 0)
    {
        fout << "NU EXISTA TRASEU";
        return;
    }
    fout << distanta[start] << '\n';
    while (start != root[start])
    {
        fout << oras[start].nume << '\n';
        start = root[start];
    }
    fout << oras[final].nume;
}
int main()
{
    citire();
    bfs(final);
    display();
    return 0;
}