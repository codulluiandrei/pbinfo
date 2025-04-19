#include <fstream>
using namespace std;
int x,y,inv;
int i,p,j,n,cmax,maxim,nrmaxim,sum,nrpal;
int main(){
    ifstream fin("cladiri.in");
    ofstream fout("cladiri.out");
    fin>>n;
    for (i=1;i<=n;i++){
        fin>>x;
        y = x;
        inv = 0;
        cmax = 0;
        p = 0;
        while (y) {
            if (y%10 > cmax)
                cmax = y%10;
            inv = inv*10 + y%10;
            p++;
            y/=10;
        }
        if (cmax > maxim) {
            maxim = cmax;
            nrmaxim = 1;
        } else
            if (cmax == maxim)
                nrmaxim++;
        if (x == inv)
            nrpal++;
        for (j=1;j<=p/2;j++) {
            if (x % 10 > inv % 10)
                sum += (x%10-inv%10);
            else
                sum += (inv%10 - x%10);
            x/=10;
            inv/=10;
        }
    }
    fout<<maxim<<" "<<nrmaxim<<"\n"<<nrpal<<"\n"<<sum;
    return 0;
}