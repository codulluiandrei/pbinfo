#include <bits/stdc++.h>
using namespace std;
ifstream in("oneout.in");
ofstream out("oneout.out");
#define cin in
#define cout out
int cer, n, rez = 0;
int maxl, maxr, maxim = -1;
short int w[1000001];
long long int v[1000001];
long long int zmaxl[10001], zmaxr[10001];
void ciur() {
    for (int i = 2; i * i <= 1000001; i++)
        for (int j = i * i; j <= 1000001; j = j + i * i)
            w[j] = 1;
}
void subsecventa() {
    for (int i = 2; i < n; i++) {
        if (w[v[i - 1]] == 0 && w[v[i + 1]] == 0 && w[v[i]] == 1) {
            int contor = 0;
            int left = i - 1, right = i + 1;
            bool adv = true;
            while (left >= 1 && adv == true) {
                if (w[v[left]] == 1)
                    adv = false, left++;
                else
                    contor++;
                left--;
            } adv = true;
            while (right <= n && adv == true) {
                if (w[v[right]] == 1)
                    adv = false, right--;
                else
                    contor++;
                right++;
            }
            
            if (contor > maxim)
                maxim = contor, rez = 1, zmaxl[rez] = left + 1, zmaxr[rez] = right - 1;
            else if (contor == maxim)
                rez++, zmaxl[rez] = left + 1, zmaxr[rez] = right - 1;
        }
    }
    cout << maxim << " " << rez << "\n";
    for (int i = 1; i <= rez; i++) {
        cout << zmaxl[i] << " " << zmaxr[i] << "\n";
    }
}
int main() {
    cin >> cer >> n;
    if (cer == 1) {
        ciur();
        for (int i = 1; i <= n; i++) {
            long long int temp;
            cin >> temp;
            if (w[temp] == 0)
                rez++;
        } cout << rez;
    } else if (cer == 2) {
        ciur();
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        subsecventa();
    }
    return 0;
}