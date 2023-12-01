#include <fstream>

using namespace std;

ifstream fin("daruri.in");
ofstream fout("daruri.out");

int t, l, a, b,r, d;

int main()
{
    fin >> t >> l;

    a = t; b = l;
    r = a % b;

    while(r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    d = b;

    if(d != 1) {
        fout << d << '\n';

        fout << t / d << ' ' << l / d << '\n';
    }
    else {
        fout << "0\n" << "0 0\n";
    }

    fin.close();
    fout.close();

    return 0;
}
