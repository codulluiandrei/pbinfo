///O(N*N)
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin ("scara.in");
ofstream fout("scara.out");
int N, i, k;
int main(){ fin>>N;
    int v[N+1], a[N+1], b[N+1];
    for(i=1;i<=N;i++){
        fin>>v[N+1-i];
        b[i]=i; a[i]=i;
    }
    for(k=2;k<=N;k++){
        for(int i=1;i<=k-1;i++) a[i]=b[k-b[i]];
        memcpy(b+1,a+1,k*sizeof(int));
    }
    for(i=1;i<=N;i++) fout<<v[a[i]]<<" ";
    fout<<"\n";     fout.close(); fin.close();
    return 0;
}