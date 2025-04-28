/**
Popescu Stefan-Alexandru - 100p O(N)
**/
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}; /// DRUL
int cerinta, n;
int xPtY[nmax + 2], yPtX[nmax + 2]; /// x e abscisa, y e ordonata
int minDist[nmax + 2][4]; /// indexate dupa x; R-U-L-D
int drumMinFin;
pair<int, int> nextUp(int x, int y){ /// creste a doua
    if(x == n - 1 && yPtX[x] < y) /// ajungem direct la tinta
        return make_pair(-1, -1);
    return make_pair(x, yPtX[x]);
}
pair<int, int> nextDown(int x, int y){ /// scade a doua
    if(x == n - 1 && yPtX[x] > y) /// ajungem direct la tinta
        return make_pair(-1, -1);
    return make_pair(x, yPtX[x]);
}
pair<int, int> nextRight(int x, int y){ /// creste prima
    if(y == n - 1 && xPtY[y] < x)
        return make_pair(-1, -1);
    return make_pair(xPtY[y], y);
}
pair<int, int> nextLeft(int x, int y){ /// scade prima
    if(y == n - 1 && xPtY[y] > x)
        return make_pair(-1, -1);
    return make_pair(xPtY[y], y);
}
inline void updatePositionWith(int xNxt, int ornNxt, int xAct, int ornAct, queue<pair<int, int> > & q){
    if(xNxt != -1){
        if(minDist[xNxt][ornNxt] > minDist[xAct][ornAct] + 1)
            minDist[xNxt][ornNxt] = minDist[xAct][ornAct] + 1, 
            q.emplace(xNxt, ornNxt);
    }
    else{
        if(drumMinFin > minDist[xAct][ornAct] + 1)
            drumMinFin = minDist[xAct][ornAct] + 1;
    }
}
void bfs(){
    memset(minDist, 127, 4 * 4 * n);
    drumMinFin = 1e9;
    queue<pair<int, int> > q;
    pair<int, int> per = nextLeft(0, 0);
    minDist[per.first][0] = 1;
    q.emplace(per.first, 0);
    per = nextDown(0, 0);
    minDist[per.first][1] = 1;
    q.emplace(per.first, 1);
    per = nextRight(0, 0);
    minDist[per.first][2] = 1;
    q.emplace(per.first, 2);
    per = nextUp(0, 0);
    minDist[per.first][3] = 1;
    q.emplace(per.first, 3);
    while(!q.empty()){
        auto elem = q.front(); q.pop();
        // cerr << elem.first << " " << elem.second << "\n";
        pair<int, int> per = nextLeft((elem.first + dx[elem.second] + n) % n, (yPtX[elem.first] + dy[elem.second] + n) % n);
        updatePositionWith(per.first, 0, elem.first, elem.second, q);
        per = nextDown((elem.first + dx[elem.second] + n) % n, (yPtX[elem.first] + dy[elem.second] + n) % n);
        updatePositionWith(per.first, 1, elem.first, elem.second, q);
        per = nextRight((elem.first + dx[elem.second] + n) % n, (yPtX[elem.first] + dy[elem.second] + n) % n);
        updatePositionWith(per.first, 2, elem.first, elem.second, q);
        per = nextUp((elem.first + dx[elem.second] + n) % n, (yPtX[elem.first] + dy[elem.second] + n) % n);
        updatePositionWith(per.first, 3, elem.first, elem.second, q);
    }
}
void solve(){
    // cin >> cerinta;
    cin >> n;
    for(int i = 0; i < n; i++){
        int y;
        cin >> y;
        /// daca se oglindeste dupa diagonala principala se umbla mai jos
        y--;
        // cerr << i << " " << y << "\n";
        yPtX[i] = y;
        xPtY[y] = i;
    }
    // cerr << "\n";
    // for(int i = 0; i < n; i++){
    //     cerr << xPtY[i] << " " << yPtX[i] << "\n";
    // }
    // cerr << "\n\n\n";
    if(cerinta == 1){
        string s;
        cin >> s;
        int x1 = 0, x2 = 0;
        for(auto &x:s){
            // cerr << x1 << " " << x2 << "\n";
            switch (x)
            {
            case 'D':
                x = 'R';
                break;
            case 'U':
                x = 'L';
                break;
            case 'L':
                x = 'D';
                break;
            case 'R':
                x = 'U';
                break;
            default:
                break;
            }
            if(x == 'D'){
                auto per = nextDown(x1, x2);
                if(per.first == -1){
                    cout << "Won\n";
                    return;
                }
                x2 = (per.second + 1) % n;
            }
            else if(x == 'L'){
                auto per = nextLeft(x1, x2);
                if(per.first == -1){
                    cout << "Won\n";
                    return;
                }
                x1 = (per.first + 1) % n;
            }
            else if(x == 'U'){
                auto per = nextUp(x1, x2);
                if(per.first == -1){
                    cout << "Won\n";
                    return;
                }
                x2 = (per.second - 1 + n) % n;
            }
            else if(x == 'R'){
                auto per = nextRight(x1, x2);
                if(per.first == -1){
                    cout << "Won\n";
                    return;
                }
                x1 = (per.first - 1 + n) % n;
            }
        }
        // cerr << x1 << " " << x2 << "\n";
        cout << "Lost\n";
    }
    else{
        bfs();
        cout << (drumMinFin == 1e9 ? -1 : drumMinFin) << "\n";
    }
}
int main(){
   // ios_base::sync_with_stdio(false), cin.tie(0), std::cout.tie(0);
    freopen("arcade.in", "r", stdin);
    freopen("arcade.out", "w", stdout);
    cin >> cerinta;
    int q = 1;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
} 