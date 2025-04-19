///O(n)                    O(n*k) cu k mic - 100 de puncte
#include "iostream"
using namespace std;
unsigned long long s[100100];/// Solutie
int p[100]{0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};/// Numere prime
int d[100]{0, 1, 1, 1, 1,  1,  1,  1,  1,  1,  1};/// Indici pentru calcul candidati
unsigned long long c[100]={0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};/// Candidati
int main(){
    int n, k;
    cin >> n >> k;
    s[1] = 1;
    for(int i=2 ; i<=n ; ++i){
        unsigned long long minim = c[1];
        for(int i=1 ; i<=k ; ++i)
            if(c[i] < minim)
                minim = c[i];
        s[i] = minim;
        for(int j=1 ; j<=k ; ++j)
            if(c[j] == minim)
                c[j] = s[++d[j]] * p[j];
    }
    for(int i=1 ; i<=n ; ++i)
        cout << s[i] <<' ';
}