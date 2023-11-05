#include <fstream>
using namespace std;
ifstream in("maxim5.in");
ofstream out("maxim5.out");
int n, contor = 0;
int main() {
    int MaxG = 0, Max;
    bool adv = true;
    while (adv == true) {
        contor++;
        if (in >> n) {
            int C, cc = 1, Max = n;
            in >> n;
            while (n != 0){
                if (n > Max) Max = n;
                cc++;
                in >> n;
            } if (contor == 1)
                C = cc, MaxG = Max;
            else if (cc < C)
                C = cc, MaxG = Max;
            else if (cc == C)
                if (Max > MaxG)
                    MaxG = Max;
        } else adv = false;
    } out << MaxG;
    return 0;
}