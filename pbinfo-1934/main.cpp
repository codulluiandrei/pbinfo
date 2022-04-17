#include <bits/stdc++.h>
using namespace std;

ifstream in("elfii.in");
ofstream out("elfii.out");

int x, y, z, nr1, nr2, nr3, nr4, nr5, nr6, nr, maxim;

int main() {
    in >> x >> y >> z;
    if ((x == 0 && y == 0 && z == 0)
        ||
        (x % 2 == 1 && y % 2 == 1 && z % 2 == 1)) out << "Poate data viitoare!";
    else {
        nr1 = x * 100 + y * 10 + z;
        if (nr1 % 2 == 0 && nr1 > 99 && nr1 < 1000) {
            nr++;
            if (maxim < nr1)
                maxim = nr1;
        } nr2 = x * 100 + z * 10 + y;
        if (nr2 % 2 == 0 && nr2 > 99 && nr2 < 1000) {
            nr++;
            if (maxim < nr2)
                maxim = nr2;
        } nr3 = y * 100 + x * 10 + z;
        if (nr3 % 2 == 0 && nr3 > 99 && nr3 < 1000) {
            nr++;
            if(maxim < nr3)
                maxim = nr3;
        } nr4 = y * 100 + z * 10 + x;
        if (nr4 % 2 == 0 && nr4 > 99 && nr4 < 1000) {
            nr++;
            if (maxim < nr4)
                maxim = nr4;
        } nr5 = z * 100 + y * 10 + x;
        if (nr5 % 2 == 0 && nr5 > 99 && nr5 < 1000) {
            nr++;
            if (maxim < nr5)
                maxim = nr5;
        } nr6 = z * 100 + x * 10 + y;
        if (nr6 % 2 == 0 && nr6 > 99 && nr6 < 1000) {
            nr++;
            if (maxim < nr6)
                maxim = nr6;
        }
        if (nr == 0) out << "Poate data viitoare!";
        else out << nr << endl << maxim;
    } return 0;
}