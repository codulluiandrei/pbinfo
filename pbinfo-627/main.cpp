#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("tripar.in");
ofstream fout("tripar.out");
int p;
int N,M;
long long v[15];
int main()
{
    fin>>p;
    fin>>N>>M;
    long long x;
    int i;
    v[0]=1;
    for(i=1;i<=M;i++){
        v[i]=v[i-1]*2;
    }
    if(p==1){
        for(i=1;i<=N;i++){
            fin>>x;
            x*=v[M];
            fout<<(x*x)<<"
";
        }
    }
    else{
        for(i=1;i<=N;i++){
            fin>>x;
            x*=v[M];
            fout<<(3*((x-1)*x)/2)<<"
";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
