#include <bits/stdc++.h>
using namespace std;
const int N = 250000;
int n;
int a[N + 5], ap[N + 5];
vector <int> v;
inline int cmmdc(int x, int y){
    if(x == -1) return y;
    while(y > 0){
        int r = x % y;
        x = y; y = r;
    }
    return x;
}
int main()
{
    freopen("comun.in", "r", stdin);
    freopen("comun.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n ; ++i)
        scanf("%d", &a[i]), ++ap[a[i]]; ///citesc sirul si vad ce numere apar in el
    for(int i = 1; i <= n ; ++i){
        ///un numar a[i] apare in sirul final doar daca cmmdc-ul tuturor multiplilor lui
        ///care apar in sirul initial e diferit de  a[i]
        int nr = 0, cm = -1;
        for(int j = 2; j * a[i] <= N ; ++j)
            if(ap[j * a[i]]) cm = cmmdc(cm, j * a[i]);
        if(cm != a[i]) v.push_back(a[i]);
    }
    printf("%d\n", v.size());
    for(auto it : v)
        printf("%d ", it);
    return 0;
}