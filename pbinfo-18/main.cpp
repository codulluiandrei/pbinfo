#include <bits/stdc++.h>
using namespace std;

ofstream out("nrdiv.out");
ifstream in("nrdiv.in");

int main() {
    int nr, rez;
    rez = 0; in >> nr;    
    for (int temp = 1; temp <= nr; temp++)
        if (nr % temp == 0)
            rez++;
    out << rez << "\n";
    return 0;
}