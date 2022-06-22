#include <fstream>
using namespace std;
ifstream in("hex.in");
ofstream out("hex.out");
const int dim = 1e4 + 1;
const char Hex[] = "0123456789ABCDEF";
char temp[dim], a[dim + 4];
int main() {
    int n = 0;
    while(!in.eof())
        in >> temp[n++];
    n--;
    int rest = n % 4;
    if (rest) {
        int adaos = 4 - rest;
        for (int i = 0, curr = 1; curr <= adaos; ++i, ++curr)
            a[i] = '0';
        n = n + adaos;
        for (int i = adaos; i < n; ++i)
            a[i] = temp[i - adaos];
    } else for (int i = 0; i < n; ++i)
            a[i] = temp[i];
    int numar;
    bool adv = 0;
    for (int i = 0; i < n; i = i + 4) {
        numar = (a[i] - '0') * 8 + (a[i + 1] - '0') * 4 + (a[i + 2] - '0') * 2 + (a[i + 3] - '0');
        if(numar) adv = 1;
        if(adv) out << Hex[numar];
    } return 0;
}