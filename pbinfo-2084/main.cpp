# include <iostream>
#include <math.h>
using namespace std;
int inaltimi[100001], stanga[100001], dreapta[100001], n;
long long int rez = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inaltimi[i];
    stanga[0] = inaltimi[0];
    dreapta[n - 1] = inaltimi[n - 1];
    for (int i = 1; i < n; i++)
       stanga[i] = max(stanga[i - 1], inaltimi[i]);
    for (int i = n - 2; i >= 0; i--)
       dreapta[i] = max(dreapta[i + 1], inaltimi[i]);
    for (int i = 0; i < n; i++)
       rez = rez + min(stanga[i], dreapta[i]) - inaltimi[i];
    cout << rez;
    return 0;
}