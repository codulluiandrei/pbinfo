#include <bits/stdc++.h>
using namespace std;

ifstream in("maxim.in");
ofstream out("maxim.out");

int main(){
    int a, b, maxim;
    in >> a >> b;
    maxim = (a > b ? a : b);
    out << maxim << endl;
    return 0;
}