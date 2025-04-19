#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("expresie8.in");
ofstream fout("expresie8.out");
int n,v[1001];
int main(){
    fin>>n;
    long long int s = 0, Max=0;
    for(int i=1;i<=n;++i)
        fin>>v[i], s+=v[i];
    for(int i=1;i<=n-2;++i){
        long long int cc = s-v[i]-v[i+1]-v[i+2]+(long long)v[i]*v[i+1]*v[i+2];
        if(cc>Max)
            Max = cc;
    }
    for(int i=1;i<=n-3;++i)
        for(int j=i+2;j<=n-1;++j){
            long long int cc = s-v[i]-v[i+1]-v[j]-v[j+1]+v[i]*v[i+1]+v[j]*v[j+1];
            if(cc>Max)
                Max = cc;
        }
    fout<<Max<<endl;
    return 0;
}