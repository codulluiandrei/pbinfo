#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;
ifstream fin("elicoptere.in");
ofstream fout("elicoptere.out");
struct punct{
double x,y;
};
struct tri{
punct A,B,C;
};
tri T[1001];
int n,k,c[1001],v[1001],u,nrc,w;
double a[105][105];
int b[105][105];
long long perechi;
void cit(){
int i;
fin>>w;
fin>>n>>k;
for(i=1;i<=n;i++)
    fin>>T[i].A.x>>T[i].A.y>>T[i].B.x>>T[i].B.y>>T[i].C.x>>T[i].C.y;
fin.close();
}
double min(double x, double y){
if(x<y) return x;
return y;
}
double distLaturaOrizontala(punct M, punct P, punct Q){
double a,b,c;
punct N;
a=Q.y-P.y;
b=P.x-Q.x;
c=P.y*Q.x-P.x*Q.y;
if(P.y==M.y && M.y==Q.y){
    return min(fabs(P.x-M.x),fabs(Q.x-M.x));
}
if(P.y==Q.y)
    return 1000000;
N.y=M.y;
N.x=(-b*M.y-c)/a;
if((P.y<=M.y && M.y<=Q.y)||(Q.y<=M.y && M.y<=P.y))
    return sqrt((M.x-N.x)*(M.x-N.x)+(M.y-N.y)*(M.y-N.y));
return 1000000;
}
double distLaturaVerticala(punct M, punct P, punct Q){
double a,b,c;
punct N;
a=Q.y-P.y;
b=P.x-Q.x;
c=P.y*Q.x-P.x*Q.y;
if(P.x==M.x && M.x==Q.x)
    return min(fabs(P.y-M.y),fabs(Q.y-M.y));
if(P.x==Q.x)
    return 1000000;
N.x=M.x;
N.y=(-a*M.x-c)/b;
if((P.x<=M.x && M.x<=Q.x)||(Q.x<=M.x && M.x<=P.x))
    return sqrt((M.x-N.x)*(M.x-N.x)+(M.y-N.y)*(M.y-N.y));
return 1000000;
}
double distTriOrizontala(tri W, tri V){
double Min,d;
Min=1000000;
d=distLaturaOrizontala(W.A,V.A,V.B);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.A,V.A,V.C);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.A,V.B,V.C);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.B,V.A,V.B);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.B,V.A,V.C);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.B,V.B,V.C);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.C,V.A,V.B);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.C,V.A,V.C);
if(d<Min)
    Min=d;
d=distLaturaOrizontala(W.C,V.B,V.C);
if(d<Min)
    Min=d;
return Min;
}
double distTriVerticala(tri W, tri V){
double Min,d;
Min=1000000;
d=distLaturaVerticala(W.A,V.A,V.B);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.A,V.A,V.C);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.A,V.B,V.C);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.B,V.A,V.B);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.B,V.A,V.C);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.B,V.B,V.C);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.C,V.A,V.B);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.C,V.A,V.C);
if(d<Min)
    Min=d;
d=distLaturaVerticala(W.C,V.B,V.C);
if(d<Min)
    Min=d;
return Min;
}
void matriceCost(){
int i,j;
double x1,x2,x;
for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++){
        x1=min(distTriOrizontala(T[i],T[j]),distTriVerticala(T[i],T[j]));
        x2=min(distTriOrizontala(T[j],T[i]),distTriVerticala(T[j],T[i]));
        x=min(x1,x2);
        if(x<=k)
        a[j][i]=a[i][j]=x;
            else
        a[j][i]=a[i][j]=1000000;
    }
}
void ad(int k){
int i;
u++;c[u]=k;v[k]=1;
for(i=1;i<=n;i++)
    if(v[i]==0 && a[k][i]<1000000 && a[k][i]!=0)
        ad(i);
}
long long comb2(int n){
long long c=n;
return c*(c-1)/2;
}
void componente(){
int i,j;
for(i=1;i<=n;i++)
    if(v[i]==0){
        u=0;nrc++;
        ad(i);
        b[nrc][0]=0;
        for(j=1;j<=u;j++){
            b[nrc][0]++;
            b[nrc][b[nrc][0]]=c[j];
        }
        perechi+=comb2(b[nrc][0]);
    }
}
double apm(int q){
int s[105],i,j,k;
double ct=0,d[105],Min;
s[b[q][1]]=1;
for(i=2;i<=b[q][0];i++){
    s[b[q][i]]=0;
    d[b[q][i]]=a[b[q][i]][b[q][1]];
}
for(k=1;k<b[q][0];k++){
    Min=1000000;
    for(i=1;i<=b[q][0];i++)
        if(s[b[q][i]]==0 && Min>d[b[q][i]]){
            Min=d[b[q][i]];
            j=i;
        }
    s[b[q][j]]=1;
    ct+=Min;
    for(i=1;i<=b[q][0];i++)
        if(s[b[q][i]]==0 && d[b[q][i]]>a[b[q][i]][b[q][j]])
            d[b[q][i]]=a[b[q][i]][b[q][j]];
}
return ct;
}
int main()
{
    double s=0,t;
    cit();
    matriceCost();
    componente();
    int i,j;
/*
    for(i=1;i<=nrc;i++){
        for(j=1;j<=b[i][0];j++)
            fout<<b[i][j]<<" ";
        fout<<'\n';
    }
*/
    for(i=1;i<=nrc;i++){
        t=apm(i);
        s+=t;
    }
     if(w==1)
         fout<<n-nrc<<'\n';
    if(w==2)
         fout<<perechi<<'\n';
    if(w==3)
         fout<<fixed<<setprecision(10)<<s<<'\n';
   fout.close();
   return 0;
}