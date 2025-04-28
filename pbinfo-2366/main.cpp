//100p
#include "fstream"
using namespace std;
ifstream cin("masterpiece001.in");
ofstream cout("masterpiece001.out");
char V[60010] = {};
char T[60010] = {};
int main(){
    int n, x, maxim=0, maxim_div=0;
    cin >> n;
    for(int i=1 ; i<=n ; ++i){
        cin >> x;
        if(x > maxim)
            maxim = x;
        if(!(T[x / 8] & (1 << (x % 8)))){
            T[x / 8] = T[x / 8] | (1 << (x % 8));
                int nrd=1, k=x, p=0;
                while(!(k & 1))
                    ++ p, k >>= 1;
                nrd *= p + 1;
                for(int d=3 ; d*d<=k ; d+=2){
                    p = 0;
                    while(k % d == 0)
                        ++ p, k /= d;
                    nrd *= p + 1;
                }
                if(k > 1)
                    nrd *= 2;
            if(nrd > maxim_div){
                maxim_div = nrd;
                for(int i=1 ; i<=maxim ; ++i)
                   V[i / 8] = V[i / 8] & (255 ^ (1 << (i % 8)));
                V[x / 8] = V[x / 8] | (1 << (x % 8));
            }
            else if(nrd == maxim_div)
                V[x / 8] = V[x / 8] | (1 << (x % 8));
        }
    }
    for(int i=1 ; i<=maxim ; ++i)
        if(V[i / 8] & (1 << (i % 8)))
            cout<<i<<' ';
}