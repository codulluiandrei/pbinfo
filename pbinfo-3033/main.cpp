#include <fstream>
#include <cstring>
using namespace std;
long long sol;
char s[100010];
int c, k, n, i, p, maxim;
char ch;
char smaxim[27];
int f[26];
int main () {
    ifstream fin ("criptografie.in");
    ofstream fout("criptografie.out");
    fin>>c;
    fin>>k>>n;
    for (i=1;i<=n;i++)
        fin>>s[i];
    p = 1;
    strcpy(smaxim, "zz");
    for (i=1;i<=n;i++) {
        ch = s[i]-'a';
        f[ ch ] ++;
        while ( f[ch] > k ) {
            f[ s[p]-'a' ]--;
            p++;
        }
        if (c == 1)
            sol += i-p+1;
        else {
            if (i-p+1 > maxim) {
                maxim = i-p+1;
                strncpy(smaxim, s+p, maxim);
            } else
                if (i-p+1 == maxim)
                    if (strncmp(smaxim, s+p, maxim) > 0)
                        strncpy(smaxim, s+p, maxim);
        }
    }
    if (c == 1)
        fout<<sol;
    else {
        smaxim[maxim] = 0;
        fout<<smaxim;
    }
    return 0;
}