#include <fstream>
#include <queue>
using namespace std;
ifstream fin("lee1.in");
ofstream fout("lee1.out");
#define INF 1000000001
struct punct{
    int i, j;
}p[7], rez[10];
int n, m, k, a[101][101], b[101][101], P[10], x[10];
int is, js, ifi, jfi;
int dmin = INF;
int l;
int di[]={0,0,1,-1};
int dj[]={-1,1,0,0};
void sterg(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            b[i][j] = 0;
}
bool inmat(int i, int j){
    return i <= n && j <= m && i >= 1 && j >= 1;
}
int lee(int si, int sj, int fi, int fj){
    sterg();
    queue<punct> Q;
    Q.push({si, sj});
    b[si][sj] = 1;
    while(!Q.empty()){
        punct x = Q.front();
        for(int d = 0; d <= 3; ++d){
            int i = di[d] + x.i;
            int j = dj[d] + x.j;
            if(inmat(i, j) && a[i][j] == 0 && b[i][j] == 0)
            b[i][j] = b[x.i][x.j] + 1, Q.push({i, j});
        }
        Q.pop();
    }
    return b[fi][fj] - 1;
}
void verif(){
    int dist = 0;
    for(int i = 1; i <= k + 1; ++i){
        if(lee(p[x[i-1]].i, p[x[i-1]].j, p[x[i]].i, p[x[i]].j) != INF)
            dist += lee(p[x[i-1]].i, p[x[i-1]].j, p[x[i]].i, p[x[i]].j);
        else
            return ;
    }
    if(dist < dmin){
        dmin = dist;
        for(int i = 1; i <= k; ++i)
            rez[i] = {p[x[i]].i, p[x[i]].j};
    }
    else if(dist == dmin){
        bool mm = false;
        for(int i = 1; i <= k; ++i){
            if(rez[i].i > p[x[i]].i){
                mm = true;
                break;
            }
            else if(rez[i].i == p[x[i]].i){
                if(rez[i].j > p[x[i]].j){
                    mm = true;
                    break;
                }
                else if(rez[i].j < p[x[i]].j)
                    break;
            }
            else if(rez[i].i < p[x[i]].i)
                break;
        }
        if(mm)
            for(int i = 1; i <= k; ++i)
                rez[i] = {p[x[i]].i, p[x[i]].j};
    }
}
void back(int t){
    for(int i = 1; i <= k; ++i)
        if(!P[i]){
            P[i] = 1;
            x[t] = i;
            if(t == k)
                verif();
            else
                back(t + 1);
            P[i] = 0;
        }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            fin >> a[i][j];
    fin >> is >> js >> ifi >> jfi;
    fin >> k;
    for(int i = 1; i <= k; ++i)
        fin >> p[i].i >> p[i].j;
    p[0] = {is, js};
    p[k + 1] = {ifi, jfi};
    x[k + 1] = k + 1;
    back(1);
    fout << dmin << '\n';
    fout << is << ',' << js << '\n';
    for(int i = 1; i <= k; ++i)
        fout << rez[i].i << ',' << rez[i].j << '\n';
    fout << ifi << ',' << jfi << '\n';
    return 0;
}