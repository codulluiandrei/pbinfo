#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("tg.in");
ofstream fout("tg.out");
int N;
bool ok[4000010];
long long sol;
int main()
{
    fin >> N;
    for (int i = 1; i <= N; ++i)
        if (!ok[i])
            for (int j = 1; i * j * j <= N; ++j)
            {
                sol += j - 1;
                ok[i * j * j] = true;
            }
    fout << sol << '\n';
    fin.close();
    fout.close();
}