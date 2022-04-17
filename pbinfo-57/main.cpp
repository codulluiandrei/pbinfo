#include <bits/stdc++.h>
using namespace std;

ifstream in("n_suma.in");
ofstream out("n_suma.out");

int main () {
    int n, S, temp; in >> n;
    for (int i = 1; i <= n; i++) { 
    	in >> temp;
    	S = S + temp;
    } out << S;
    return 0;
}