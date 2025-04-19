/// Marius Nicoli o(N+T) - baleiere, cu sort din biblioteca
#include <fstream>
#include <algorithm>
#define DIMD 50010
#define DIMQ 300010
using namespace std;
struct poligon {
    long long x1;
    long long y1;
    long long x2;
    long long y2;
};
struct query {
    long long x;
    long long t;
};
struct eveniment {
    long long x;
    long long tip;
///1. incepe poligon 2. query 3. se termina poligon, pentru vertical
///1. query 2. incepe 3. se termina 4. incepe constant 5. se termina constant
    long long index; /// indicele dreptunghiului sau al queryului
};
int cmp(const eveniment &a, const eveniment &b) {
    if (a.x == b.x)
        return a.tip < b.tip;
    else
        return a.x < b.x;
}
poligon d[DIMD];
query q[DIMQ];
eveniment ev[2*DIMD + DIMQ];
long long r[DIMQ];
long long n, xmin, xmax, crt, a, b, c, sol, i, t, T, k, m, poz;
int main () {
    ifstream fin ("shootings.in");
    ofstream fout("shootings.out");
    fin>>n;
    fin>>d[1].x1>>d[1].y1>>d[1].x2>>d[1].y2;
    xmin = d[1].x1;
    xmax = d[1].x2;
    for (i=2;i<=n;i++) {
        fin>>d[i].x1>>d[i].y1>>d[i].x2>>d[i].y2;
        xmin = min(xmin, d[i].x1);
        xmax = max(xmax, d[i].x2);
    }
    fin>>t;
    for (i=1;i<=t;i++) {
        fin>>q[i].x>>q[i].t;
        xmin = min(xmin, q[i].x);
        xmax = max(xmax, q[i].x);
    }
    long long m = 0;
    for (i=1;i<=t;i++) {
        if (q[i].t == 1) {
            m++;
            ev[m].x = q[i].x;
            ev[m].index = i;
            ev[m].tip = 2;
        }
    }
    if (m) {
        for (i=1;i<=n;i++) {
            m++;
            ev[m].x = d[i].x1;
            ev[m].tip = 1;
            ev[m].index = i;
            m++;
            ev[m].x = d[i].x2;
            ev[m].tip = 3;
            ev[m].index = i;
        }
        sort(ev+1, ev+m+1, cmp);
        for (i=1;i<=m;i++) {
            if (ev[i].tip == 1) {
                k = ev[i].index;
                crt += d[k].y2 - d[k].y1;
            }
            if (ev[i].tip == 3) {
                k = ev[i].index;
                crt -= d[k].y2 - d[k].y1;
            }
            if (ev[i].tip == 2) {
                k = ev[i].index;
                r[k] = crt * crt;
            }
        }
    }
    T = 2;
    for (long long s = 1; s <= 2; s++) {
        m = 0;
        for (i=1;i<=t;i++) {
            if (q[i].t == T) {
                m++;
                ev[m].x = q[i].x;
                ev[m].index = i;
                ev[m].tip = 1;
            }
        }
        if (m) {
            for (i=1;i<=n;i++) {
                m++;
                ev[m].x = d[i].x1 + d[i].y1;
                ev[m].tip = 2;
                ev[m].index = i; /// incepe dreptunghi
                m++;
                ev[m].x = d[i].x2 + d[i].y2;
                ev[m].tip = 3;
                ev[m].index = i; /// se termina dreptunghi
                m++;
                ev[m].x = d[i].x1 + d[i].y2;
                ev[m].tip = 4;
                ev[m].index = i; /// se incepe constant
                m++;
                ev[m].x = d[i].x2 + d[i].y1;
                ev[m].tip = 5;
                ev[m].index = i; /// se termina incepe constant
            }
            sort(ev+1, ev+m+1, cmp);
            a = b = c = 0;
            sol = 0;
            poz = 1;
            for (i=ev[1].x;i<=ev[m].x && poz <= m;) {
                if (ev[poz].x == i) {
                    if (ev[poz].tip == 2) {
                        a++;
                        poz++;
                        continue;
                    }
                    if (ev[poz].tip == 3) {
                        b--;
                        poz++;
                        continue;
                    }
                    if (ev[poz].tip == 4) {
                        a--;
                        c++;
                        poz++;
                        continue;
                    }
                    if (ev[poz].tip == 5) {
                        c--;
                        b++;
                        poz++;
                        continue;
                    }
                    if (ev[poz].tip == 1) {
                        r[ev[poz].index] = sol * sol * 2;
                        poz++;
                        continue;
                    }
                }
                sol += a;
                sol -= b;
                i++;
            }
        }
        for (i=1;i<=n;i++) {
            d[i].x1 = xmax - (d[i].x1 - xmin);
            d[i].x2 = xmax - (d[i].x2 - xmin);
            swap(d[i].x1, d[i].x2);
            swap(d[i].y1, d[i].y2);
        }
        T++;
        for (i=1;i<=t;i++) {
            q[i].x = xmax - (q[i].x - xmin);
        }
    }
    for (i=1;i<=t;i++)
        fout<<r[i]<<"\n";
    return 0;
}