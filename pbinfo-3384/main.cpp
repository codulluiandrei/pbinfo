#include <fstream>
using namespace std;
ifstream fin("codjoc.in");
ofstream fout("codjoc.out");
int main()
{
    long long int n, c, s, p = 10;
    fin >> n;
    s = n;
    while(p <= n)
    {
        s = s + n % p;
        p = p * 10;
    }
    fout << s <<"\n";
    fin.close();
	fout.close();
    return 0;
}