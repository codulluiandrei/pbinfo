#include <fstream>
using namespace std;
ifstream in("relativ.in");
ofstream out("relativ.out");
long long int n, temp, minim, maxim = 0, Stemp, S, relativ = 1;
int main() {
    in >> n >> temp;
    minim = temp; Stemp = temp; S = temp;
    for (int i = 1; i <= n - 1; i++) {
        in >> temp;
        Stemp = Stemp + temp;
        if (temp <= minim) {
              relativ++;
              if (Stemp - S + minim > maxim) maxim = Stemp - S + minim;
              minim = temp; S = Stemp;
          }
    } out << relativ << "\n" << maxim;
    return 0;
}