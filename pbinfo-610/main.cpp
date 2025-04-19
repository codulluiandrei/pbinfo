#include <stdio.h>
#include <bitset>
#include <unistd.h>
#define NMAX (1600000)
using namespace std;
int n = 0;
int grupuri = 0;
int soldati[NMAX];
inline int bindex(int b) { return b / 32; }
inline int boffset(int b) { return b % 32; }
void set_bit(int b) {
    soldati[bindex(b)] |= 1 << (boffset(b));
}
bool get_bit(int b) {
    return (soldati[bindex(b)] & (1 << (boffset(b)))) != 0;
}
int main() {
    freopen("spion.in", "rt", stdin);
    freopen("spion.out", "wt", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, s, d;
        scanf("%d %d %d", &x, &s, &d);
        int prezenta = get_bit(s) + get_bit(d);
        grupuri += 1 - prezenta;
        printf("%d\n", grupuri);
        set_bit(x);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}