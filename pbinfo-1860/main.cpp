#include <bits/stdc++.h>
using namespace std;
ifstream in("blackfriday.in");
ofstream out("blackfriday.out");
#define cin in
#define cout out
long long int n, v[11], t[11], contor = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> v[i] ;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 2; i <= n; i++)
        if (v[contor] * (v[i] - t[i]) > (v[contor] - t[contor]) * v[i]) 
        	contor = i;
    cout << contor;
    return 0;
}