#include <fstream>
using namespace std;
ifstream in("numere18.in");
ofstream out("numere18.out");
int main() {
    int p, n, m;
    in >> p;
    if (p == 1) {
        in >> n;
        int S = 0, temp1 = n * (n - 1) / 2, temp2 = n * (n + 1) / 2;
        for (int i = temp1 + 1; i <= temp2; i++)
            S = S + i;
        out << S;
    } else {
        in >> m;
        int k = 1;
        while (k * (k + 1) / 2 < m) k++;
        k--;
        out << k + 1<< " " << m - k * (k + 1) / 2;
    } return 0;
}