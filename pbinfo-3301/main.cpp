#include <bits/stdc++.h>
using namespace std;
ifstream in("nrdiv9.in");
ofstream out("nrdiv9.out");
int main() {
    int n, var1, var2, temp, nr = 0;
    in >> n;
    temp = sqrt(n);
    int ciur[temp];
    for (int i = 1; i <= temp; i++)
        ciur[i] = i;
    for (int i = 2; i * i <= temp; i++)
        if (ciur[i] == i) {
        for (int j = i * i; j <= temp; j = j + i)
            if (ciur[j] == j)
            ciur[j] = i;
    } for (int i = 2; i <= temp; i++) {
        var2 = ciur[i / ciur[i]];
        var1 = ciur[i]; 
        if (var1 * var2 == i && var2 != 1 && var1 != var2) nr++;
        else if (ciur[i] == i)
            if (pow(i, 8) <= n)
        nr++;
    } out << nr;
    return 0;
}