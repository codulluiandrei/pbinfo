#include <iostream>
using namespace std;
int main() {
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= s; k++)
                cout << ' ';
            for (int j = 1; j <= n; j++) 
                cout << '*';
            s = s + 1; cout << endl;
        } s = s - 2;
        for (int a = 1; a <= n - 1; a++){
            for (int b = 1; b <= s; b++)
                cout << ' ';
            for (int x = 1; x <= n; x++)
                cout << '*';
            s--; cout << endl;
	} return 0;
}