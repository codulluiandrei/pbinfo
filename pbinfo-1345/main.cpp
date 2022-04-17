#include <fstream>
using namespace std;
string problema = "kprim";
ofstream out(problema + ".out");
ifstream in(problema + ".in");
int main() {
    int k, n = 1; in >> k;
    k++;
    if (k == 3) n = 7, k = 0;
    while (k > 0) {
        n++;
        bool adv = true;
        if (n % 2 == 0 && n > 2) adv = false;
        for (int d = 3; d * d <= n && adv; d = d + 2)
            if (n % d == 0)
                adv = false;
        if (adv) k--;
    } out << (long long int) n * n << endl;
    return 0;
}