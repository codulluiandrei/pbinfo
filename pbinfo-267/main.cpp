#include <fstream>
using namespace std;
ifstream in("unice.in");
ofstream out("unice.out");
int freq[100], nr, temp;
int main() {
    in >> nr;
    for (int i = 1; i <= nr; i++) {
        in >> temp;
        freq[temp]++;
    } for (int i = 0; i < 100; i++)
        if (freq[i] == 1) out << i << " ";
    return 0;
}