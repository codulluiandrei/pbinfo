#include <fstream>
using namespace std;
ifstream in("ksir.in");
ofstream out("ksir.out");
long long int k, total, grupa;
int main() {
    in >> k;
    grupa = 1; total = 0;
    while (total + 2 * grupa - 1 < k) 
    	{ total += 2 * grupa - 1; grupa++; }
    if (k - total <= grupa) out << k - total << '\n';
    else out << grupa << '\n';
    return 0;
}