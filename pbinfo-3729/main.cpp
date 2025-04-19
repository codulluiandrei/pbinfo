/// m log n
#include <fstream>
#include <iostream>
#include <algorithm>
#define DIMN 2001
#define DIMM 300001
using namespace std;
int n, m, i, maxim, j, k;
int v[DIMN], s[DIMM];
pair<int, int> w[DIMN];
int L[DIMM];
int u[DIMM], a[DIMM], b[DIMM], R[DIMM];
int sol[DIMN];
int F[DIMN], SF[DIMN];
int main () {
    ifstream fin ("exclusiv.in");
    ofstream fout("exclusiv.out");
    fin>>m>>n;
    for (i=1;i<=m;i++)
        fin>>s[i];
    for (i=1;i<=n;i++) {
        fin>>v[i];
        w[i].first = v[i];
        w[i].second = i;
    }
    sort(w+1, w+n+1);
    for (i=1;i<=m;i++) {
        int st = 1;
        int dr = n;
        int mid;
        while (st <= dr) {
            mid = (st+dr)/2;
            if (w[mid].first < s[i])
                st = mid+1;
            else
                dr = mid-1;
        }
        if (st <= n  && w[st].first == s[i]) {
            F[w[st].second] ++;
            u[i] = 1;
        }
    }
    for (i= 1;i<=n;i++)
        SF[i] = SF[i-1] + F[i];
    for (i=m;i>=1;i--) {
        int st = 1;
        int dr = n;
        int mid;
        while (st <= dr) {
            mid = (st+dr)/2;
            if (w[mid].first < s[i])
                st = mid+1;
            else
                dr = mid-1;
        }
        if (st <= n  && w[st].first == s[i]) {
            R[SF[w[st].second]] = i;
            SF[w[st].second]--;
            L[ w[st].second ] = SF[w[st].second];
            u[i] = 1;
        }
    }
    int len = 0;
    u[0] = 1;
    u[m+1] = 1;
    for (i=1;i<=m+1;i++) {
        if(u[i] == 0)
            len++;
        else {
            if (u[i-1] == 0) {
                b[i-1] = len;
                a[i-len] = len;
            }
            len = 0;
        }
        if (len > maxim)
            maxim = len;
    }
    for (i=n;i>=1;i--) {
        sol[++k] = maxim;
        int ok = 1;
        for (j=1;j<i;j++)
            if (v[j] == v[i]) {
                ok = 0;
                break;
            }
        if (ok == 0)
            continue;
        int st = 1;
        int dr = n;
        int mid;
        while (st <= dr) {
            mid = (st+dr)/2;
            if (w[mid].first < v[i])
                st = mid+1;
            else
                dr = mid-1;
        }
        for (j=SF[w[st].second]+1;j<=SF[w[st].second]+F[w[st].second];j++) {
            int poz = R[j];
            if (u[poz] != 0) {
                u[poz] = 0;
                if (u[poz-1] != 0 && u[poz+1] != 0) {
                    a[poz] = 1;
                    b[poz] = 1;
                    len = 1;
                } else {
                    if (u[poz-1] == 0 && u[poz+1] != 0) {
                        b[poz] = b[poz-1]+1;
                        len = b[poz];
                        a[poz-b[poz]+1] = b[poz];
                    } else {
                        if (u[poz-1]!=0 && u[poz+1] == 0) {
                            a[poz] = a[poz+1]+1;
                            len = a[poz];
                            b[ poz + a[poz] - 1] = a[poz];
                        } else {
                            len = b[poz-1] + a[poz+1] + 1;
                            a[poz - b[poz-1]] = len;
                            b[poz + a[poz+1]] = len;
                        }
                    }
                }
                maxim = max(maxim, len);
            }
        }
    }
    for (i=k;i>=1;i--)
        fout<<sol[i]<<"\n";
    return 0;
}