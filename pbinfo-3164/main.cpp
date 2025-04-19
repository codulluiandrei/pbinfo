#include <fstream>
using namespace std;
struct elev {
    int cod;
    int media;
    int absente;
};
elev v[100], maxim1, maxim2;
int n, i, a, b;
int main () {
    ifstream fin("qclasa.in");
    ofstream fout("qclasa.out");
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>v[i].cod>>v[i].media>>v[i].absente;
    a = 0;
    for (i=1;i<=n;i++)
        if (v[i].media == 10)
            a++;
    fout<<a<<"\n";
    b = 0;
    for (i=1;i<=n;i++)
        b += v[i].media;
    fout<<b/n<<"\n";
    maxim1 = v[1];
    maxim2 = v[1];
    for (i=2;i<=n;i++)
        if (v[i].absente > maxim1.absente || v[i].absente == maxim1.absente && v[i].cod < maxim1.cod) {
            maxim2 = maxim1;
            maxim1 = v[i];
        } else
            if (v[i].absente > maxim2.absente || v[i].absente == maxim2.absente && v[i].cod < maxim2.cod)
                maxim2 = v[i];
    fout<<maxim1.cod<<" "<<maxim1.media<<" "<<maxim1.absente<<"\n";
    fout<<maxim2.cod<<" "<<maxim2.media<<" "<<maxim2.absente<<"\n";
    return 0;
}