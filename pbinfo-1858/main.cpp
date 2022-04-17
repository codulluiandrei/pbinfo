#include <bits/stdc++.h>
using namespace std;
ifstream in("restmare.in");
ofstream out("restmare.out");
long long n, k;
int main() {
    in >> n ;
    k = n / 2 ;
    if (n % 2 == 1 ) out << k * k ;
	else out << k * (k - 1) ;
    return 0;
}