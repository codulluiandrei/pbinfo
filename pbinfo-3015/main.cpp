#include <bits/stdc++.h>
#define last 220
using namespace std;
ifstream fin ("fibointerval.in");
ofstream fout("fibointerval.out");
short int x[1005][225];
void Fibo (int p){
    int i;
    for (i=last; i>=1; i--){
        x[p][i] += x[p-1][i] + x[p-2][i];
        x[p][i-1] += x[p][i] / 10;
        x[p][i] %= 10;
    }
}
void afisare (int p){
    int i;
    for (i=1; i<=last; i++)
        if (x[p][i])
        break;
    for (;i<=last; i++)
        fout << x[p][i];
    fout << " ";
}
int afis[225];
void sumInterval (int a, int b){
    int i;
    for (i=0; i<=last; i++)
        afis[i] = x[b+2][i];
    for (i=last; i>=1; i--){
        afis[i] -= x[a+1][i];
        if (afis[i]<0){
            afis[i] += 10;
            afis[i-1] --;
        }
    }
    for (i=1; i<=last; i++)
        if(afis[i])
        break;
    for (; i<=last; i++)
        fout << afis[i];
    fout << "\n";
}
int main()
{
    int n, i, Q, q, a, b;
    fin >> n >> Q;
    x[1][last] = 1;
    x[2][last] = 1;
    for (i=3; i<=n+2; i++)
        Fibo(i);
//    for (i=1; i<=n+2; i++)
//        afisare(i), fout << "\n";
    for (q=1; q<=Q; q++){
        fin >> a >> b;
        afisare(a);
        afisare(b);
        sumInterval(a,b);
    }
    return 0;
}