#include <bits/stdc++.h>
using namespace std;
int main(){
    int a , b , c , max , min;
    cin >> a >> b >> c;
    max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    min = a;
    if(min > b) min = b;
    if(min > c) min = c;
    cout << max-min << endl;
    return 0;
}