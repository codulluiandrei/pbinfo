# include <iostream>
using namespace std;
int n, m, a[25005], b[200005];
int caut(int st, int dr, int v[], int x) {
    if(st > dr) return 0;
    else {
        int m = (st + dr) / 2;
        if (v[m] == x) return m;
        if (v[m] > x) return caut(1, m-1, v, x);
        if (v[m] < x) return caut(m+1, dr, v, x);
        return 0;
    }
} int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int j = 1; j <= m; j++) cin >> b[j];
    for (int i = 1; i <= m; i++)
        if ((caut(1, n, a, b[i]))) cout << 1 << " ";
        else cout << 0 << " ";
    return 0;
}