#include <bits/stdc++.h>
using namespace std;
ifstream in("comori1.in");
ofstream out("comori1.out");
int main() {
    int n, v[1001], temp;
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> v[i];    
    } for (int i = 0; i < n; i++) {
        if (v[i] > v[i + 1] && v[i + 1] != v[n]) {
            out << i + 2 << " ";
            temp++;
        }
    } if(temp == 0)
    out << 0;
    return 0;    
}