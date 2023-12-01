///O(m) - implementare proprie
#include <fstream>
#define ull unsigned long long

using namespace std;

///O fost ceva o fost da numa liste nu facui
ifstream fin("cevaculiste.in");
ofstream fout("cevaculiste.out");

ull n,m,v[100001],c;

int main(){
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        fin>>v[i];
    }
    while(m){
        if(v[m]<=n){
            c+=(n-v[m])/m+1;
            n-=((n-v[m])/m+1)*m;
        }
        ///Pur si simplu sar peste cele de care nu am nevoie
        while(m&&v[m]>n){
            m--;
        }
    }
    fout<<c;
    return 0;
}