#include <bits/stdc++.h>
using namespace std;

ifstream in("minmax.in");
ofstream out("minmax.out");

int main() {
	int vec[1001], n, maxim = -1, minim = 1001;
    in >> n;
    for (int i = 0; i < n; i++) {
     	in >> vec[i];
        if (vec[i] > maxim) maxim = vec[i];
        else if (vec[i] < minim) minim = vec[i];
    }
    out << minim << " " << maxim;
    return 0;
}