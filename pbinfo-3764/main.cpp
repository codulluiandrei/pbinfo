///Complexitate O(log(A)) pentru cerinta 1
///Complexitate O(N*sigma*sigma)
#include <fstream>
using namespace std;
ifstream  fin("cat2pal.in");
ofstream fout("cat2pal.out");
int N,v[10002], nw, c, ok, i, j, k, C , P1, P2;
long long z, s, t, w[100], s1, s2, t1, t2, x1, x2, x, y, r, X, A, vi, vj, p, q, d;
char f[100002], f0[100002], f1[100002];
int main(){fin>>C;
    if(C==1){fin>>A;
      ///voi adauga in w[] toate solutiile posibile, apoi sortez si apoi verific
      ///solutiile posibile sunt printre prefixele sau sufixele oglinditului lui A
      ///eventual precedate sau succedate de una dintre cifrele 0,1,...,9
      x=A; while(x%10==0){x=x/10;};///tai zerourile de la final
      p=1;y=0;do{y=y*10+x%10;x=x/10;p=p*10;}while(x>0);///y=oglindit(A)
      ///adaug sufixele si prefixele lui y
      nw=0; q=p; r=y;
      do{ w[++nw]=y%q; w[++nw]=r;
        q=q/10; r=r/10;
      }while(r);
      ///lipesc cate o cifra la stanga si la dreapta lui y si adaug in w[]
        for(c=0;c<=9;c++){
            d=y*10+c; if(d<=A*10){w[++nw]=d;}
            d=c*p+y; if(d<=A*10){w[++nw]=d;}
        }
      ///sortez candidatii
      for(i=1;i<=nw-1;i++)
        for(j=i+1;j<=nw;j++)
            if(w[i]>w[j]){ int aux=w[i]; w[i]=w[j]; w[j]=aux; }
      ///verific si selectez doar solutiile
      w[0]=0;P1=0;
      q=1;while(q<=A){q=q*10;}
      for(i=1;i<=nw;i++)
        if(w[P1]!=w[i]){///verific daca w[i] este o solutie
          p=1;while(p<=w[i]){p=p*10;}
          s1=0; x1=A*p+w[i]; t1=x1; do{s1=s1*10+t1%10;t1=t1/10;}while(t1);
          s2=0; x2=w[i]*q+A; t2=x2; do{s2=s2*10+t2%10;t2=t2/10;}while(t2);
          if(s1==x1 ||s2==x2){///DA, w[i] este solutie
            w[++P1]=w[i];
          }
        }
      fout<<P1<<"\n";
    }
    if(C==2){ fin>>N;
      for(i=1;i<=N;i++){ fin>>v[i]; f[v[i]]=1; }
    ///f[x]=1 daca x este din v[]
    ///orice palindrom de lungime j se poate identifica prin sufix de lungime j-j/2
    ///f0[x]=1 daca x este sufix de palindrom de lungime para
    ///f1[x]=1 daca x este sufix de palindrom de lungime impara
      ///oglinditele prefixelor
      for(i=1;i<=N;i++){
        vi=v[i]; while(vi && vi%10==0){vi=vi/10;}
        p=1; y=0; do{y=y*10+vi%10;vi/=10;p=p*10;}while(vi);
        do{
          if(y*10>=p && f[y]==1){///daca y este element din v[]
            z=p*v[i]+y;
            s=z; t=0; j=0; do{j++; t=t*10+s%10;s=s/10;}while(s);
            if(z==t){///si lipit la dreapta lui v[i] avem palindrom
              ///construim in s sufixul identificator pentru z
              k=j-j/2; s=0; while(k){s=s*10+t%10;t=t/10;k--;}
              if(j%2==0){f0[s]=1;}
              else{f1[s]=1;}
            }
          }
          p=p/10;y=y%p;
        }while(p>=10);
      }
      ///oglinditele sufixelor
      for(i=1;i<=N;i++){
        vi=v[i]; p=1; y=0; do{y=y*10+vi%10;vi=vi/10;p=p*10;}while(vi);
        do{
          if(f[y]==1){///daca este din v[]
            z=y*p+v[i];///lipim in stanga lui v[i]
            s=z; t=0; j=0; do{j++; t=t*10+s%10;s=s/10;}while(s);
            if(z==t && f[y]==1){///este palindrom
              ///construim in s sufixul identificator pentru z
              k=j-j/2; s=0; while(k){s=s*10+t%10;t=t/10;k--;}
              if(j%2==0){f0[s]=1;}
              else{f1[s]=1;}
            }
          }
          y=y/10;
        }while(y>0);
      }
      P2=0;
      for(i=0;i<100000;i++){P2=P2+f0[i]+f1[i];}
      fout<<P2<<"\n";
    }
    fout.close(); fin.close();
    return 0;
}