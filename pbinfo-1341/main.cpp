#include <fstream>
#include <vector>

using namespace std;

ifstream fin("protest.in");
ofstream fout("protest.out");

const int MaxN = 100001;

vector<int> G[MaxN];
vector<bool> scandalagiu;
vector<bool> viz;

int n, k, nr;

void Df(int nod);

int main()
{
    fin >> n >> k;

    scandalagiu = vector<bool>(n + 1);
    viz         = vector<bool>(n + 1);

    for ( int i = 1, sc; i <= k; ++i )
    {
        fin >> sc;
        scandalagiu[sc] = 1;
    }

    for ( int i = 1, x, y; i < n; ++i )
    {
        fin >> x >> y;
        G[x].push_back(y);
    }

    Df(1);

    fout << nr;


    fin.close();
    fout.close();
    return 0;
}

void Df(int nod)
{
    viz[nod] = 1;

    for ( auto v : G[nod] )
    {
        if ( !scandalagiu[v] && !viz[v] )
        {
            Df(v);
            nr++;
        }

    }


}
