#include <fstream>
using namespace std;
int freq[12];
ifstream in("mincifre.in");
ofstream out("mincifre.out");
int main() {
    char cif;
    while (in >> cif) freq[cif - '0']++;
    bool adv = false;
    for (int i = 1; i <= 9 && !adv; i++) {
        if (freq[i]) { 
            out << i;
            freq[i]--;
            adv = true;
        }
    } for (int i = 0; i <= 9; i++)
        for (int j = 1; j <= freq[i]; j++)
            out << i;
    return 0;
}