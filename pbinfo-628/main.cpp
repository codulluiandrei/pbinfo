#include<stdio.h>
struct elem{
    int x , y , z;
    elem *urm;
};
int di[]={1,-1,0,0,0,0};
int dj[]={0,0,1,0,-1,0};
int dk[]={0,0,0,1,0,-1};
int c[101][101][101],v[101][101][101],n,l,p;
FILE *g;
void cit(){
    FILE *f;
    int i,j,k;
    f=fopen("cub1.in","r");
    fscanf(f,"%d",&p);
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
                fscanf(f,"%d",&c[i][j][k]);
    fclose(f);
}
int ok(int i){
    if(i<=n&&i>=1)
        return 1;
    return 0;
}
int valide(int i,int j,int k){
    if(ok(i)&&ok(j)&&ok(k))
        return 1;
    return 0;
}
void lee(){
    elem *p,*u,*q;
    int i,j,k,l;
    p=new elem;
    u=p;
    p->x=1;p->y=1;p->z=1;
    p->urm=0;
    v[1][1][1]=1;
    while(p){
        for(l=0;l<=5;l++)
            if(c[p->x][p->y][p->z]&(1<<l)){
                i=p->x+di[l];
                j=p->y+dj[l];
                k=p->z+dk[l];
                if(v[i][j][k]==0&&valide(i,j,k)){
                    v[i][j][k]=v[p->x][p->y][p->z]+1;
                    q=new elem;
                    q->x=i;
                    q->y=j;
                    q->z=k;
                    q->urm=0;
                    u->urm=q;
                    u=q;
                }
            }
        q=p;
        p=p->urm;
        delete q;
    }
}
void drum(int i,int j,int k){
    if(i==1&&j==1&&k==1){
        fprintf(g,"1 1 1
");
        return;
    }
    for(l=0;l<=5;l++)
        if(v[i-di[l]][j-dj[l]][k-dk[l]]==v[i][j][k]-1&&(c[i-di[l]][j-dj[l]][k-dk[l]]&(1<<l)))
            break;
    drum(i-di[l],j-dj[l],k-dk[l]);
    fprintf(g,"%d %d %d
",i,j,k);
}
int main(){
    cit();
    lee();
    g=fopen("cub1.out","w");
    if(p==1){
        int nr_max,i,j,k,ii=0,jj=0,kk=0,l,nr;
        nr_max=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++){
                    nr=0;
                    for(l=0;l<6;l++)
                        if((c[i][j][k]&(1<<l))&&valide(i+di[l],j+dj[l],k+dk[l]))
                            nr++;
                    if(nr>nr_max){
                        ii=i;
                        jj=j;
                        kk=k;
                        nr_max=nr;
                    }
                }
        fprintf(g,"%d %d %d
",ii,jj,kk);
    }else{
        if(v[n][n][n]){
            fprintf(g,"%d
",v[n][n][n]);
            drum(n,n,n);
        }else
            fprintf(g,"-1
");
    }
    fclose(g);
    return 0;
}