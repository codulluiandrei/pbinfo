#include <fstream>
#include <algorithm>
#include <cmath>
#define INF 1002
using namespace std;
ifstream fin ("infasuratoareconvexa.in");
ofstream fout("infasuratoareconvexa.out");
int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1);
}
int cmp(const pair<int, int> &a, const pair<int, int> &b) {
    int d = det(0, 0, a.first, a.second, b.first, b.second);
    if (d != 0)
        return d > 0;
    else
        return a.first*a.first + a.second*a.second > b.first*b.first + b.second*b.second;
}
pair<int, int> v[103], s[103], aux;
int n, i, j, k, pminim;
int main() {
    fin>>n;
    pminim = 0;
    v[0].first = v[0].second = INF;
    for (i=1;i<=n;i++) {
        fin>>v[i].first>>v[i].second;
        if (v[i].second < v[pminim].second || ( (v[i].second == v[pminim].second)&&(v[i].first < v[pminim].first) ))
            pminim = i;
    }
    v[0] = v[pminim];
    v[pminim] = v[1];
    v[1] = v[0];
    for (i=1;i<=n;i++) {
        v[i].first -= v[0].first;
        v[i].second -= v[0].second;
    }
    sort(v+2, v+n+1, cmp);
    for (j=3;j<=n;j++)
        if (det(v[1].first, v[1].second, v[2].first, v[2].second, v[j].first, v[j].second)) {
            break;
        }
    i=2;
    j--;
    while (i<j) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        i++;
        j--;
    }
    s[1] = v[1];
    s[2] = v[2];
    k = 2;
    for (i=3;i<=n;i++) {
        while (k >= 2 && det(s[k-1].first, s[k-1].second, s[k].first, s[k].second, v[i].first, v[i].second) < 0 ) {
            k--;
        }
        s[++k] = v[i];
    }
    fout<<k<<"\n";
    for (i=1;i<=k;i++)
        fout<<s[i].first + v[0].first<<" "<<s[i].second + v[0].second<<"\n";
    return 0;
}