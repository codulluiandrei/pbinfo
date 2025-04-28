/* autor Razvan Chivu  */
#include <iostream>
#include <fstream>
using namespace std;
int a[101][101];
int n, m, k;
bool inmat(int x, int y){
    if(x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
    return false;
}
void rec(int x, int y, int &s){
    s += a[x][y];
    a[x][y] = 0;
    int px = x, py = y;
    for(int i = 1; i <= k; i++){
        px = x - i;
        py = y;
        if(inmat(px, py) && a[px][py])
            rec(px, py, s);
        px = x + i;
        py = y;
        if(inmat(px, py) && a[px][py])
            rec(px, py, s);
        px = x;
        py = y - i;
        if(inmat(px, py) && a[px][py])
            rec(px, py, s);
        px = x;
        py = y + i;
        if(inmat(px, py) && a[px][py])
            rec(px, py, s);
    }
}
int main()
{
    ifstream fin("ronti.in");
    ofstream fout("ronti.out");
    fin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            fin >> a[i][j];
    int smax = 0;
    int xmax=0, ymax=0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j]){
                int s = 0;
                rec(i, j, s);
                if(s > smax){
                   smax = s;
                   xmax = i;
                   ymax = j;
                }
            }
    fout << xmax << " " << ymax << "\n" << smax;
    return 0;
}