# include <fstream>
using namespace std;

ifstream f("colier.in");
ofstream g("colier.out");

struct colier{
    int g, c;
}C[101];

int st[101], sol[101], sumg[101];
bool ap[101];
int gmax, n, m;

void back(int k)
{
    for(int x=1; x<=n; ++x){
        st[k] = x;
        if (!ap[st[k]]) {
            if (k == 1 || (C[st[k]].c != C[st[k-1]].c)){
                ap[st[k]] = 1;
                sumg[k] = sumg[k-1] + C[st[k]].g;
                if (k == m) {
                    if (C[st[k]].c != C[st[1]].c) {
                        if (sumg[k] > gmax) {
                            gmax = sumg[k];
                            for(int i=1; i<=k; ++i)
                                sol[i] = st[i];
                        }
                    }
                }
                else if (k < m) back(k+1);
                ap[st[k]] = 0;
            }
        }
    }
}
int main()
{
    f >> n >> m;
    for(int i=1; i<=n; ++i){
        f >> C[i].c >> C[i].g;
    }

    back(1);

    for(int i=1; i<=m; ++i)
        g << sol[i] << " ";

    return 0;
}
