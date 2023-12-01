#include <fstream>

using namespace std;

ifstream fin("countprime.in");
ofstream fout("countprime.out");

typedef unsigned long long ull;

ull check[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

ull power(ull val, ull put, ull mod){
    ull rez = 1;
    ull pw = val;
    while(put){
        if(put & 1){
            rez *= pw;
            rez %= mod;
        }

        pw *= pw;
        pw %= mod;
        put >>= 1;
    }
    return rez;
}

bool prim(ull num, ull baze){
    ull cn = num - 1;
    ull exp = 0;
    while(cn % 2 == 0)
    {
        exp++;
        cn /= 2;
    }

    ull x = (num - 1) / ((ull)1 << exp);
    ull pw = power(baze, x, num);
    if(pw == 1 || pw == num - 1)
        return true;
    for(ull i = 1; i < exp; ++i){
        pw = power(pw, 2, num);
        if(pw == num - 1)
            return true;
    }
    return false;
}

int main()
{
    ull st, dr;
    fin >> st >> dr;

    ull cnt = 0;
    for(ull i = st; i <= dr; ++i){
        bool ok = 0;
        for(int k = 0; k < 13 && !ok; ++k)
            if(i == check[k])
                ++cnt, ok = 1;
        if(!ok){
            ok = 1;
            for(int k = 0; k < 13 && ok; ++k)
                ok = prim(i, check[k]);
            cnt += ok;
        }
    }
    fout << cnt << '\n';
    return 0;
}
