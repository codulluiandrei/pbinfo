#include "fstream"
using namespace std;
ifstream cin("bomboane4.in");
ofstream cout("bomboane4.out");
int main(){
    unsigned long long p, q, a, b, tr=0, r=0;
    cin >> p >> q;
    a = p, b = q;
    while(a % b){
        unsigned long long r = a % b;
        a = b;
        b = r;
    }
    int P[100] = {}, Q[100] = {}, T[200] = {};
    for(; p ;) P[++P[0]] = p % 10, p /= 10;
    for(; q ;) Q[++Q[0]] = q % 10, q /= 10;
    T[0] = P[0] + Q[0] - 1;
    for(int i=1 ; i<=P[0] ; ++i)
     for(int j=1 ; j<=Q[0] ; ++j)
        T[i+j-1] = T[i+j-1] + P[i] * Q[j];
    for(int i=1 ; i<=T[0] ; ++i){
        tr = tr + T[i];
        T[i] = tr % 10;
        tr /= 10;
    }
    if(tr > 0)  T[++T[0]] = tr;
    for(int i=T[0] ; i> 0 ; --i){
        r = r * 10 + T[i];
        T[i] = r / b;
        r = r % b;
    }
    if(T[1] >= 1)
        T[1] = T[1] - 1;
    else{
        int j = 1;
        while(T[j] == 0)
            T[j++] = 9;
        T[j]--;
    }
    for(;T[T[0]] == 0 && T[0] > 1; --T[0]);
    for(int i=T[0] ; i> 0 ; --i)
        cout << T[i];
}