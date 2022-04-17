#include <bits/stdc++.h>
using namespace std;

ifstream in("maxim3.in");
ofstream out("maxim3.out");

int main() {
    int a, b, c; in >> a >> b >> c;
    if (a > b && a > c) out << a; 
    else if (b > a && b > c) out << b;
    else out << c;
    return 0;
}