# include <fstream>
using namespace std;
ifstream f("turn.in");
ofstream g("turn.out");
struct cub{
    int l, c;
}T[101];
int st[20], h[20];
int n, H;
bool ap[101];
void tipar(int k)
{
    for(int i=1; i<=k; ++i)
        g << st[i] << ' ';
    g << '\n';
}
void back(int k)
{
    for(int x=1; x<=n; ++x){
        st[k] = x;
        if (!ap[st[k]]){
            if (h[k-1] + T[st[k]].l <= H){
                if (k == 1 || (T[st[k]].c != T[st[k-1]].c && T[st[k]].l <= T[st[k-1]].l)){
                    ap[st[k]] = 1;
                    h[k] = h[k-1] + T[st[k]].l;
                    if (h[k] == H) tipar(k);
                        else back(k+1);
                    ap[st[k]] = 0;
                }
            }
        }
    }
}
int main()
{
    f >> n >> H;
    for(int i=1; i<=n; ++i){
        f >> T[i].l  >> T[i].c;
    }
    back(1);
    return 0;
}