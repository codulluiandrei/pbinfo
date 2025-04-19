#include <fstream>
using namespace std;
ifstream in("memory006.in");
ofstream out("memory006.out");
unsigned long long n, k, temp, var, rez, S, stanga, dreapta;
char carac[10003];
int main() {
    in >> n >> k;
    for (int i = 1; i <= n; i++) {
        in >> temp;
        var = 0;
        while (temp % 2 == 0) {
            temp = temp / 2;
            var++;
        } if (temp == 1) {
            dreapta = (dreapta + 1) % 10001;
            carac[dreapta] = var;
            S = S + var;
            if (S == k) rez++;
            else if (S > k) {
                while (S > k) {
                    S = S - carac[stanga];
                    stanga = (stanga + 1) % 10001;
                } if (S == k) rez++;
            }
        } else {
            S = 0;
            stanga = 1;
            dreapta = 0;
        }
    } out << rez;
    return 0;
}