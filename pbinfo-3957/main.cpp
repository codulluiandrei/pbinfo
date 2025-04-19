/// Moca Andrei - 100p
#include <bits/stdc++.h>
using namespace std;
const int N(1001);
class Bigint {
public:
    Bigint(int const& _x = 0) {
        int x(_x);
        a[0] = 0;
        while (x) {
            a[++a[0]] = x % 10;
            x /= 10;
        }
    }
    Bigint(const char* s) {
        a[0] = static_cast<int>(strlen(s));
        for (int i = 1; i <= a[0]; ++i)
            a[i] = s[a[0] - i] - '0';
    }
    inline int Divide(int const& x) {
        int r = 0;
        for (int i = a[0]; i >= 1; --i) {
            r = 10 * r + a[i];
            a[i] = r / x;
            r %= x;
        }
        while (!a[a[0]] && a[0] >= 1)
            --a[0];
        return r;
    }
    inline void Multiply(int const& x) {
        int t = 0;
        for (int i = 1; i <= a[0]; ++i) {
            a[i] = a[i] * x + t;
            t = a[i] / 10;
            a[i] %= 10;
        }
        while (t) {
            a[++a[0]] = t % 10;
            t /= 10;
        }
    }
    inline bool NotZero() {
        return a[0];
    }
    inline void Print() {
        for (int i = a[0]; i >= 1; --i)
            cout << a[i];
    }
private:
    int a[N];
};
char s[N];
int main() {
    cin >> s;
    Bigint n(s), res(1);
    while (n.NotZero())
        if (n.Divide(2))
            res.Multiply(2);
    res.Print();
    return 0;
}