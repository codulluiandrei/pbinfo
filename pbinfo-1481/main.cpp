#include <bits/stdc++.h>
using namespace std;
ifstream in("pitic.in");
ofstream out("pitic.out");
int main() {
    int m, S, temp, var;
    bool adv, cond; 
    in >> m;
    for (int i = 1; i <= m; i++) {
        adv = true;
        temp = 2;
        if (i == 1) adv = false;
        var = sqrt(i);
        while (temp <= var && adv == true) {
            if (i % temp == 0)
                adv = false;
            temp++;
        } if (adv == true) out << i << " ";
        else {
            S = 0;
            var = i; 
            temp = 2;
            while (var != 1) {
                cond = false;
                while (var % temp == 0) {
                    cond = true;
                    var = var / temp;
                } if (cond == true) S = S + temp;
                temp++;
            } out << S << " ";
        }
    } return 0;
}