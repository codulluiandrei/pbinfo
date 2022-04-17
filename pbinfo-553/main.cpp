#include <iostream>
using namespace std;
int main(){
    int n, v[1005];
    cin  >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    int minim = 1, maxim = 1;
    for (int i = 2; i <= n; i++) {
        if (v[i] < v[minim]) minim = i;
        if(v[i] > v[maxim]) maxim = i;
    } cout << minim << " " << maxim;
    return 0;
}
