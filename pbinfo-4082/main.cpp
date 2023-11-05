// Nistor Eugen Mot - O(k+p) 100 puncte
#include <fstream>
using namespace std;
#define M 10024
#define MM 100004
int px[M],py[M],pu[M];
char cx[MM]; int vx[MM];
int main()
{   ifstream fi("pelican.in"); ofstream fo("pelican.out");
    int i,n,p,k,is=0,u,x,y;
    fi>>n>>p>>k;
    for (i=1;i<=p;i++) {
            fi>>px[i]>>py[i]>>u; pu[i]=u-1; }
    for(i=1;i<=k;i++) {
        fi>>cx[i]>>vx[i]; if (cx[i]=='Z') is=i; }
    if(is>0) {
        x=vx[is]/n; y=vx[is]%n; u=0;
        for(i=1;i<is;i++)
            if(cx[i]=='R') u+=vx[i];
        for(i=1;i<=p;i++) {
            px[i]=x; py[i]=y; pu[i]=(pu[i]+u)%4; }
    }
    u=0; x=0; y=0;
    for(i=is+1;i<=k;i++) {
        if(cx[i]=='R') u=(u+vx[i])%4;
        if(cx[i]=='A') {
            if(u==0) x+=(n-vx[i]);
            else if(u==1) y+=vx[i];
            else if(u==2) x+=vx[i];
            else y+=(n-vx[i]);
        }
    }
    x%=n; y%=n;
    for(i=1;i<=p;i++) {
        if(pu[i]==0) {
            px[i]=(px[i]+x)%n; py[i]=(py[i]+y)%n; }
        if(pu[i]==1) {
                px[i]=(px[i]+y)%n; py[i]=(py[i]+n-x)%n; }
        if(pu[i]==2) {
                px[i]=(px[i]+n-x)%n;  py[i]=(py[i]+n-y)%n; }
        if(pu[i]==3) {
                px[i]=(px[i]+n-y)%n;  py[i]=(py[i]+x)%n; }
        fo<<px[i]<<' '<<py[i]<<'\n';
    }
    return 0;
}