#include <bits/stdc++.h>
using namespace std;
ifstream in("vistiernic.in");
ofstream out("vistiernic.out");
#define cin in
#define cout out
int n, ptr2, ptr5, rez;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        while (temp % 2 == 0) {
            ptr2++;
            temp = temp / 2;
        } while (temp % 5 == 0) {
           ptr5++;
           temp = temp / 5;
        }
    } if (ptr2 <= ptr5) 
        rez = ptr2;
    else 
        rez = ptr5;
    cout << rez;
    return 0;
}