#include <bits/stdc++.h>
#define BUF 16384
using namespace std;
class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;
    char read_ch() {
        ++sp;
        if (sp == BUF) {
            sp = 0;
            fread(buff, 1, BUF, fin);
        }
        return buff[sp];
    }
public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[BUF]();
        sp = BUF-1;
    }
    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
    InParser& operator >> (long long &n) {
        char c;
        n = 0;
        while (!isdigit(c = read_ch()) && c != '-');
        long long sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
};
class OutParser {
private:
    FILE *fout;
    char *buff;
    int sp;
    void write_ch(char ch) {
        if (sp == 50000) {
            fwrite(buff, 1, 50000, fout);
            sp = 0;
            buff[sp++] = ch;
        } else {
            buff[sp++] = ch;
        }
    }
public:
    OutParser(const char* name) {
        fout = fopen(name, "w");
        buff = new char[50000]();
        sp = 0;
    }
    ~OutParser() {
        fwrite(buff, 1, sp, fout);
        fclose(fout);
    }
    OutParser& operator << (int vu32) {
        if (vu32 <= 9) {
            write_ch(vu32 + '0');
        } else {
            (*this) << (vu32 / 10);
            write_ch(vu32 % 10 + '0');
        }
        return *this;
    }
    OutParser& operator << (long long vu64) {
        if (vu64 <= 9) {
            write_ch(vu64 + '0');
        } else {
            (*this) << (vu64 / 10);
            write_ch(vu64 % 10 + '0');
        }
        return *this;
    }
    OutParser& operator << (char ch) {
        write_ch(ch);
        return *this;
    }
    OutParser& operator << (const char *ch) {
        while (*ch) {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};
InParser fin ("aib2d.in");
OutParser fout ("aib2d.out");
int n, Q, op, x, aib[1001][1001];
inline int Suma (int x, int y) {
    int S = 0;
    for (int i = x; i > 0; i -= (i & (-i)))
    for (int j = y; j > 0; j -= (j & (-j)))
    S += aib[i][j];
    return S;
}
inline void Update (int x, int y, int val) {
    for (int i = x; i <= n; i += (i & (-i)))
    for (int j = y; j <= n; j += (j & (-j)))
    aib[i][j] += val;
}
inline void Query (int x1, int y1, int x2, int y2) {
    fout << Suma (x2, y2) - Suma (x2, y1 - 1) - Suma (x1 - 1, y2) + Suma (x1 - 1, y1 - 1) << '\n';
}
int main() {
    fin >> n;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++) {
      fin >> x;
      Update (i, j, x);
    }
    fin >> Q;
    while (Q --) {
        fin >> op;
        if (op == 1) {
            int x, y, val;
            fin >> x >> y >> val;
            Update (x, y, val);
        } else {
            int x1, y1, x2, y2;
            fin >> x1 >> y1 >> x2 >> y2;
            Query (x1, y1, x2, y2);
        }
    }
    return 0;
}