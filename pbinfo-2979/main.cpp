#include <fstream>
using namespace std;
ifstream in("cartele.in");
ofstream out("cartele.out");
int maxim, sec1, sec, p, h, m, s, h1, m1, s1, N, max1, cb, cf, suma;
char c, a;
int main() {
    in >> p; in >> N;
    if (p == 1) {
        cb = 0; cf = 0;
        for (int i = 1; i <= N; i++) {
            in >> c >> a >> h >> m >> s;
            if (c == 'b') if (a == 'i') cb++; else cb--;
            else if (a == 'i') cf++; else cf--;
        } out << cb << " " << cf << "\n";
    } else if (p == 2) {
        in >> c >> a >> h1 >> m1 >> s1;
        sec1 = h1 * 3600 + m1 * 60 + s1;
        if (c == 'b') cb = 1, cf = 0;
        else cb = 0, cf = 1;
        suma = 0;
        for (int i = 2; i <= N; i++) {
            in >> c >> a >> h >> m >> s;
            sec = h * 3600 + m * 60 + s;
            if (cb == cf && cb > 0) suma = suma + (sec - sec1);
            if (c == 'b') if (a == 'i') cb++; else cb--;
            else if (a == 'i') cf++; else cf--;
            sec1 = sec;
        } out << suma << "\n";
    } else { in >> c >> a >> h1 >> m1 >> s1;
        if (c == 'b') { cb = 1; cf = 0; sec1 = h1 * 3600 + m1 * 60+  s1; }
        else cb = 0, cf = 1; maxim = 0;
        for (int i = 2; i <= N; i++) {
            in >> c >> a >> h >> m >> s;
            sec = h * 3600 + m * 60 + s;
            if (c == 'b') {
                if (cb % 2 != 0 && sec - sec1 > maxim) maxim = sec - sec1;
                if (a == 'i') cb++; else cb--; sec1 = sec;
            } else if (a == 'i') cf++; else cf--;
        } out << maxim << "\n";
    } return 0;
}