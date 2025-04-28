#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin ("sortareunghi.in");
ofstream fout("sortareunghi.out");
pair<int, int> v[103];
int n, i;
int cadran(int x, int y) {
    if (x > 0 && y >= 0)
        return 1;
    if (x >= 0 && y<0)
        return 4;
    if (y > 0 && x <= 0)
        return 2;
    return 3;
}
int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1);
}
int cmp(const pair<int, int> &a, const pair<int, int> &b) {
    int c1 = cadran(a.first, a.second);
    int c2 = cadran(b.first, b.second);
    if (c1 != c2)
        return c1 < c2;
    else {
        int d = det(0, 0, a.first, a.second, b.first, b.second);
        if (d != 0)
            return d > 0;
        else
            return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
    }
}
int main() {
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>v[i].first>>v[i].second;
    sort(v+1, v+n+1, cmp);
    for (i=1;i<=n;i++)
        fout<<v[i].first<<" "<<v[i].second<<"\n";
    return 0;
}