#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("cartonase.in");
    ofstream fout ("cartonase.out");
    int n, m;
    fin >> n >> m;
    fout << 2*(n-1)*(m-1)+(n-1)+(m-1);
    return 0;
}