#include <fstream>
using namespace std;
ifstream fin ("b2.in");
ofstream fout("b2.out");
long long p2[100];
int main()
{
    long long n;
    fin >> n;
    p2[0] = 1;
    for(int i = 1; i <= 61; ++i)
        p2[i] = 2 * p2[i - 1];
    for(int x = 1; x <= 61; ++x)
        for(int y = 0; y < x; ++y){
            if(n >= p2[x] + p2[y])
             fout << p2[x] + p2[y] << ' ';
        }
    fout << '\n';
    return 0;
}