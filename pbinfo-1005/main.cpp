#include <fstream>
using namespace std;
ifstream in("numere8.in");
ofstream out("numere8.out");
int freq[10000], nr;
int main() {
    while (in >> nr) if (nr <= 9999) freq[nr] = 1;
    for (int t = 9999; t > 0; t--) if (freq[t] == 0) out << t << " ";
    return 0;
}