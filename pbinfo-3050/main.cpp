#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("ncif.in");
ofstream fout("ncif.out");
int main()
{
    int n,m,k;
    fin>>k;
    for(int i=1; i<=k; ++i)
    {
        fin>>n>>m;
        fout<<(int)((log10(n)*m)+1)<<endl;
    }
    return 0;
}