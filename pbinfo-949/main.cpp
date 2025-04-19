#include <iostream>
using namespace std;
int nr, z, l, a, zile[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool bisect(int x) {
    if (x % 4)
        return 0;
    if (x % 100)
        return 1;
    if (x % 400)
        return 0;
    return 1;
}
int main() {
    cin >> z >> l >> a >> nr;
    if (nr > 0) {
        while (nr && z > 28) {
            z++;
            int limit = zile[l];
            if (l == 2 && bisect(a) && z > 29)
                limit++;
            if (z > limit)
                l++, z = 1;
            if (l > 12)
                a++, l = 1;
            nr--;
        }
        while (1) {
            int next = 365;
            if (l < 3 && bisect(a))
                next++;
            if (l > 2 && bisect(a+1))
                next++;
            if (nr < next)
                break;
            nr -= next;
            a++;
        }
        while (1) {
            int next = zile[l];
            if (l == 2 && bisect(a))
                next++;
            if (nr < next)
                break;
            nr -= next;
            l++;
            if (l > 12)
                a++, l = 1;
        }
        for (; nr; --nr) {
            z++;
            int limit = zile[l];
            if (l == 2 && bisect(a) && z > 29)
                limit++;
            if (z > limit)
                l++, z = 1;
            if (l > 12)
                a++, l = 1;
        }
    }
    else {
        nr = -nr;
        while (nr && z > 28)
            z--, nr--;
        while (1) {
            int next = 365;
            if (l > 3 && bisect(a))
                next++;
            if (l < 2 && bisect(a-1))
                next++;
            if (nr < next)
                break;
            nr -= next;
            a--;
        }
        while (1) {
            int next = zile[(l+10)%12 + 1];
            if (l == 3 && bisect(a))
                next++;
            if (nr < next)
                break;
            nr -= next;
            l--;
            if (!l)
                l = 12, a--;
        }
        for (; nr; --nr) {
            z--;
            int limit = zile[(l+10)%12 + 1];
            if (l == 3 && bisect(a))
                limit++;
            if (!z)
                l--, z = limit;
            if (!l)
                --a, l = 12;
        }
    }
    cout << z << " " << l << " " << a;
}