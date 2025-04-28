#include <fstream>
#include <vector>
using namespace std;
ifstream fin ("di.in");
ofstream fout("di.out");
vector<int> v;
int n, m, x, y;
void query(int nod, int st, int dr, int x, int y) {
    if (x <= st && dr <= y) {
        if (st == x) {
            v.push_back(st);
        }
        v.push_back(dr);
    } else {
        int mid = (st+dr)/2;
        if (x <= mid)
            query(2*nod, st, mid, x, y);
        if (y>mid)
            query(2*nod+1, mid+1, dr, x, y);
    }
}
int main () {
    fin>>n>>m;
    for (int i=1;i<=m;i++) {
        fin>>x>>y;
        v.clear();
        query(1, 1, n, x, y);
        fout<<v.size()-1<<" ";
        for (int j=0; j<v.size(); j++)
            fout<<v[j]<<" ";
        fout<<"\n";
    }
    return 0;
}