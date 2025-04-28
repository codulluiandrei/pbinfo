#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("align.in");
ofstream fout("align.out");
const int NMAX = 110;
const int LMAX = 210;
char words[NMAX][LMAX];
char temp[LMAX];
char alignment;
int n, len[NMAX];
int main()
{
    fin >> n >> alignment;
    fin.get();
    int maxim = -1;
    for (int i = 1; i <= n; ++i) {
        fin.getline(words[i], LMAX);
        len[i] = strlen(words[i]);
        maxim = max(maxim, len[i]);
    }
    if (alignment == 'D') {
        for (int i = 1; i <= n; ++i) {
            if (len[i] != maxim) {
                strcpy(temp, words[i]);
                memset(words[i], 0, sizeof words[i]);
                for (int j = len[i]; j <= maxim; ++j) {
                    words[i][j - len[i] - 1] = ' ';
                }
                strcat(words[i], temp);
            }
        }
    }
    else {
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            pos = 0;
            while (pos < len[i] && words[i][pos] == ' ')
                ++pos;
            strcpy(temp, words[i] + pos);
            memset(words[i], 0, sizeof words[i]);
            strcpy(words[i], temp);
        }
    }
    for (int i = 1; i <= n; ++i) {
        fout << words[i] << '\n';
    }
    return 0;
}