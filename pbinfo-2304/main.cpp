#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int n, k, contor = 0;
    char cuv[50][256];
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        char temp[256];
        cin.getline(temp, 256);
        strcpy(cuv[++contor], temp);
    }
    cin >> k;
    for (int i = 1; i <= contor; i++)
        if (strlen(cuv[i]) == k)
            cout << cuv[i] << " ";
    for (int i = 1; i <= contor; i++)
        if (strlen(cuv[i]) != k)
            cout << cuv[i] << " ";
	return 0;
}