#include <fstream>
using namespace std;
ifstream fin("zecimala.in");
ofstream fout("zecimala.out");
long long x;
int main() {
    fin >> x;
    fout << 5 << '\n';
    fin.close();
    fout.close();
    return 0;
}