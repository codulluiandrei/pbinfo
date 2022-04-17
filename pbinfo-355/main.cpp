#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp; cin >> n;
 	int* v = new int[n];
 	for (int i = 0; i < n; i++) {
  		cin >> temp;
  		v[i] = temp;
 	} 
    sort(v, v + n);
 	cout << v[0];
 	return 0;
}