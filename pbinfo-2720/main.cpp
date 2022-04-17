#include <bits/stdc++.h>
using namespace std;
ifstream in("bucketsort.in");
ofstream out("bucketsort.out");
int v[10001], n, c;
bool desc(int a,int b){
    return a > b;
}
int main() {
    in >> n;
    for (int i = 1; i <= n; i++) in >> v[i];
    in >> c;
    if (c == 0) sort(v + 1, v + n + 1);
    else sort(v + 1, v + n + 1, desc);
    for (int i = 1; i <= n; i++) out << v[i] << " ";
    return 0;
}