#include <bits/stdc++.h>
using namespace std;
int n;
struct elev {
    int inaltime, indice;
};
elev v[1005];
void sortare(elev *v, int st, int dr);
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].inaltime;
        v[i].indice = i;
    } sortare(v, 1, n);
    for (int i = 1; i <= n; i++) cout << v[i].indice << " ";
	return 0;
}
void sortare(elev v[], int st, int dr) {
    if (st < dr) {
        int i = st, j = dr, d = 0;
        while (i < j) {
            if (v[i].inaltime > v[j].inaltime) {
                elev temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                if (d == 0) d = 1;
                else d = 0;
            }
            if (d == 0) j--;
            else i++;
        } int k = i;
        sortare(v, st, k -1);
        sortare (v, k+1, dr);
    }
}