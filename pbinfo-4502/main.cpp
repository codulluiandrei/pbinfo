#include <fstream>
using namespace std;
ifstream fin("steiner_1.in");
ofstream fout("steiner_1.out");
int main()
{
    int n;
    fin>>n;
	fout << n*(n+1)/2 + 1;
    return 0;
}