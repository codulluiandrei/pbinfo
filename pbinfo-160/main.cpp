#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, v[100];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int j = n; j >= 1; j--)
        if (sqrt(v[j]) == (int)sqrt(v[j])){
        for (int i = n; i >= j; i--)
            v[i + 1] = v[i];
        n++;
        v[j] = sqrt(v[j]);
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}
