#include <bits/stdc++.h>
using namespace std;

ifstream in("nraparitii.in");
ofstream out("nraparitii.out");

int main() {
    int n, v[101]; in >> n;
    for (int i = 0; i < n; i++) in >> v[i];
    int nraparitii = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == v[n - 1])
            nraparitii++;
    out << nraparitii << endl;
    return 0;
}