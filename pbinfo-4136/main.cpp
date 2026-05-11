#include <fstream>
using namespace std;
ifstream  fin("subsir.in");
ofstream fout("subsir.out");
int C,N,S[10005],poz[10005][10],M,Q,x,p,a,b,nr,nw,w[12];
struct pereche{
    int poz,s;
} v[10000005];
int main(){
    fin>>C>>N;
    for(int i=1;i<=N;i++){
        fin>>S[i];
    }
    for(int j=0;j<=9;j++){
        poz[N+1][j]=N+1;
        poz[N+2][j]=N+1;
    }
    for(int i=N;i>=1;i--){
        for(int j=0;j<=9;j++){
            poz[i][j]=poz[i+1][j];
        }
        poz[i][S[i]]=i;
    }
    ///poz[x][cif] = prima pozitie din S[x;N] unde gasesc cif
    if(C==1){
        ///O(M)
        fin>>M;
        for(int i=1;i<=M;i++){
            fin>>x>>p;
            nw=0;
            do{
                nw++;
                w[nw]=x%10;
                x=x/10;
            }while(x);
            int ok=1;
            int j=0;
            for(int k=nw;k>=1;k--){
                ///caut w[k] incepand cu S[j]
                j=poz[j+1][w[k]];
                if(j>p){
                    ok=0;
                    break;
                }
            }
            fout<<ok<<"\n";
        }
    }
    else{
        ///cazul C==2
        for(int i=0;i<=9;i++){
            v[i].poz=poz[1][i];
            if(v[i].poz==N+1)v[i].s=0;
            else v[i].s=1;
            if(i>0)v[i].s+=v[i-1].s;
        }
        for(int i=1;i<1000000;i++){
            p=v[i].poz;
            x=i*10;
            for(int j=0;j<=9;j++){
                v[x].poz=poz[p+1][j];
                if(v[x].poz<=N){
                    v[x].s=v[x-1].s+1;
                }
                else{
                    v[x].s=v[x-1].s;
                }
                x++;
            }
        }
        ///O(Q)
        fin>>Q;
        for(int i=1;i<=Q;i++){
            fin>>a>>b;
            nr=0;
            if(a>0)nr=v[b].s-v[a-1].s;
            else nr=v[b].s;
            fout<<nr<<"\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}