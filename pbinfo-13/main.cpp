#include <bits/stdc++.h>
using namespace std;
int main() {
    char carac[11];
    int n = 0, i = 0, j = 1;
    cin >> carac;
    while (carac[n] != '\0') n++;    
    i = n;
    while (i) {
        j = 0;
        while (j < i) {
            cout << carac[j];
            j++;
        } cout << endl;
        i--;
    } i = 0;
    while (carac[i] != '\0') {
        j = i; 
        while (carac[j] != '\0') {
            cout << carac[j];
            j++;
        } cout << endl;
        i++;
    } return 0;    
}