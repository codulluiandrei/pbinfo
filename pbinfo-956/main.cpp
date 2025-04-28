#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("sir2.in");
ofstream g ("sir2.out");
const int mod = 104729;
int n, k;
int combinari[301];
//n pe orizontala
//k pe verticala
inline void maxim () {
    g<<n-k+1<<'\n';
}
inline void citeste () {
    f>>n>>k;
    maxim ();
    n--;
    k--;
    k = min (k, n-k);
}
inline void calculeaza () {
    combinari[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=k; j>=1; j--) {
            combinari[j] = (combinari[j] + combinari[j-1]) % mod;
            //g<<combinari[j]<<' ';
        }
        //g<<endl;
    }
}
int main () {
    citeste ();
 // f>>n>>k;
    calculeaza ();
    g<<combinari[k]<<'\n';
    return 0;
}