#include <fstream>
using namespace std;
ifstream in("numere7.in");
ofstream out("numere7.out");
int freq[10];
int main() {
    int n, m;
    in	>> n >> m; 
    do { freq[n % 10]++;
        n = n / 10;
    } while (n != 0);
    do { freq[m % 10]++;
        m = m / 10;
    } while (m != 0);
    int p = 1;
    while (freq[p] == 0) p++;
    out << p;
    freq[p]--;
    for (int i = 0; i < 10; i++)
        for (int j = 1; j <= freq[i]; j++)
            out << i;
    return 0;
}