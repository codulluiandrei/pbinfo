#include <bits/stdc++.h>
using namespace std;
ifstream in("eratostene2.in");
ofstream out("eratostene2.out");
int n, temp, prime[1000001], v[1000001];
int main() {
    prime[1] = 1;
    v[1] = 0;
    for (int i = 2; i <= 1000000; i++)
        if (prime[i] == 0) {
        v[i] = 1;
        temp = i + i;
        while (temp <= 1000000) {
            prime[temp] = 1;
            v[temp]++;
            temp = temp + i;
        }
    } in >> n;
    for (int i = 1; i <= n; i++) {
        in >> temp;
        out << v[temp] << " ";
    } return 0;
}