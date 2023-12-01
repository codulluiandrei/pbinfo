#include <fstream>

using namespace std;

ifstream fin("betisoare1.in");
ofstream fout("betisoare1.out");

int main() {
    int N;
    char prec, tip;

    fin >> N;
    fin >> prec;

    tip = prec;

    char x;
    int lg = 1, nr = 0, mx = 0;
    for(int i = 1; i <= N; ++i) {
        if(i < N) fin >> x;
        else x = (prec == '0' ? '1' : '0');

        if(x != prec) {
            if(mx < lg) {
                mx = lg;
                tip = prec;
                nr = 1;
            }
            else {
                if(mx == lg && tip == prec) {
                    ++nr;
                }
                else {
                    if(mx == lg && tip < prec) {
                        nr = 1;
                        tip = prec;
                    }
                }
            }

            lg = 1;
        }
        else {
            ++lg;
        }

        prec = x;
    }

    fout << tip << ' ' << mx << '\n' << nr << '\n';

    fin.close();
    fout.close();

    return 0;
}
