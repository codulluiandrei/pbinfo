#include <bits/stdc++.h>
using namespace std;

ifstream in("pozitie.in");
ofstream out("pozitie.out");

int main() {
    int n, v[10000], temp = 0;
    in >> n;
    for (int i = 1; i <= n; i++) {
    	in >> v[i];    
        if (v[i] < v[1]) temp++;
    } out << temp + 1;
    return 0;
}