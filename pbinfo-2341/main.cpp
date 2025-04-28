#include <fstream> 
#include <cstring> 
#include <unordered_set> 
#define Nmax 102 
using namespace std; 
ifstream f("labirint4.in"); 
ofstream g("labirint4.out"); 
int n,x,y,X,Y,m,Q,K,lg; 
string s; 
int dx[255],dy[255]; 
unordered_set<int> M; 
bool OK(int a, int b) 
{ 
    if (a>=1 && a<=n && b>=1 && b<=m) 
        return 1; 
    return 0; 
} 
int main() 
{ 
    dx['U'] = dy['L'] = -1; 
    dx['D'] = dy['R'] = 1; 
    f>>n>>m>>K; 
    for (int i=1;i<=K;i++) 
    { 
        f>>x>>y; 
        M.insert(x*100000+y); 
    } 
    f>>X>>Y; 
    f>>lg>>s; 
    for (auto it : s) 
    { 
        int X2 = X + dx[it]; 
        int Y2 = Y + dy[it]; 
        if (OK(X2,Y2) && !M.count(X2*100000+Y2)) 
            X = X2,Y = Y2; 
    } 
    g<<X<<' '<<Y; 
    return 0; 
} 