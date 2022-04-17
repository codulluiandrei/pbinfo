#include <bits/stdc++.h>
using namespace std;
ifstream in("numere2.in");
ofstream out("numere2.out");
int main() {
    int n, v[25001], Z = 0;
    in >> n;
    for (int i = 1 ; i <= n ; i++) {
        	in >> v[i];
        if (v[i] == v[i - 1]) {
            Z++;
            n = n - 2;
            i = i - 2;
        }
    } out << Z << endl;
    for (int i = 1 ; i <= n ; i++)
        out << v[i] << " ";
    return 0;
}