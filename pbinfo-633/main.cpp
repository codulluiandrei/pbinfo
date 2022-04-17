#include <iostream>
using namespace std;
int main() {
	int v[1001], n;
    cin >> n;
    int pare = 0, impare = 0;
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
   		if (v[i] % 2 == 0) pare++;
        else impare++;
    }
    if (impare > pare) cout << impare - pare;
    else cout << pare - impare;
}