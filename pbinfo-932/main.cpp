#include <fstream>
#include <iomanip>
#define DIM 100010
using namespace std;
ifstream fin ("ariapoligonsimplu.in");
ofstream fout("ariapoligonsimplu.out");
pair<int, int> v[DIM];
int sol;
int n, i;
int aria(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return  (b.first-a.first) * (c.second-a.second) -
            (c.first-a.first) * (b.second-a.second);
}
int main() {
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>v[i].first>>v[i].second;
    }
    v[0] = v[n];
    for (i=0;i<n;i++) {
        sol += aria(v[0], v[i], v[i+1]);
    }
    fout<<setprecision(1)<<fixed<<sol/2.0;
    return 0;
}