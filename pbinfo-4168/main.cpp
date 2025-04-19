///O(N+T*log(N)); solutia nu depinde de plaja de valori
#include <fstream>
#include <algorithm>
using namespace std;
ifstream  fin("secvente.in");
ofstream fout("secvente.out");
int N,T,k,L,R,p,q,p1,p2,mij;
long long t,sp[100005];
struct secventa{
    int x,y;
}v[100005];
int cmp(secventa a, secventa b){
    if((a.x<b.x) || (a.x==b.x && a.y<b.y))return 1;
    return 0;
}
int main(){
    fin>>N;
    for(int i=1;i<=N;i++){
        fin>>v[i].x>>v[i].y;
    }
    sort(v+1,v+1+N,cmp);
    k=1;
    for(int i=2;i<=N;i++){
        if(v[k].x<v[i].x){
            while(k>0 && v[k].y>=v[i].y)
            {
                k--;
            }
            k++;
            v[k]=v[i];
        }
    }
    N=k;
    ///acum ar trebui sa nu mai existe doua intervale cu includere
    v[N+1]={v[N].y+1,1000001};
    for(int i=1;i<=N;i++){
        sp[i]=sp[i-1]+(long long)(v[i+1].y-v[i].y)*v[i].x;
        ///am adaugat toate secventele care includ secventa v[i]
        ///acestea sunt cele care au capat dreapta in intervalul
        ///[v[i].y;v[i+1].y-1] si capatul stang in intervalul
        ///[1;v[i].x]
    }
    fin>>T;
    for(int i=1;i<=T;i++){
        if(i==5){
            int test=0;
        }
        fin>>L>>R;
        ///cautare binara; O(log(N))
        p1=0;p2=N;p=0;
        while(p1<=p2){
            mij=(p1+p2)/2;
            if(v[mij].x<L){
                p1=mij+1;
            }
            else{
                p=mij;
                p2=mij-1;
            }
        }
        if(p==0 || v[p].y>R){
            fout<<0<<"\n";
        }
        else{
            ///cautare binara; O(log(N))
            p1=p;p2=N;q=0;
            while(p1<=p2){
                mij=(p1+p2)/2;
                if(v[mij].y>R){
                    p2=mij-1;
                }
                else{
                    q=mij;
                    p1=mij+1;
                }
            }
            t=sp[q]-sp[p-1];
            ///avem acum toate secventele cu capat drept
            ///in intervalul [v[p].y;v[q+1].y-1]
            ///si capatul stang corespunzator
            t=t-(long long)(v[q+1].y-R-1)*v[q].x;
            ///am eliminat capetele drepte din zona [v[q+1].y-1;R+1]
            t=t-(long long)(R-v[p].y+1)*(L-1);
            ///am eliminat pentru capetele drepte din [v[p].y;R]
            ///capetele stangi din intervalul [1;L-1]
            fout<<t<<"\n";
        }
    }
    fout.close(); fin.close();
    return 0;
}