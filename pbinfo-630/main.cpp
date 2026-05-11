#include<stdio.h>
#define infinit 2000000000
struct nod
{
    int inf , c;
    nod * urm;
} * l[50005];
FILE *f;
int n,nh,m,x[50005],d[50005],t[50005],poz[50005],nivel[50005],P,S,F,nr=0;
void cit()
{
    nod *p;
    int a,b,i,j;
    freopen("joc.in","r",stdin);
	scanf("%d%d%d%d",&P,&n,&S,&F);
    for(i=1;i<=n;i++){
        l[i] = 0;
        scanf("%d" , &nivel[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=1 ; j<=a ; j++){
            scanf("%d" , &b);
            p=new nod;
            p -> inf = b;
            if(nivel[i] > nivel[b])
                p ->c = nivel[i]/nivel[b];
            else
                p ->c = nivel[b]/nivel[i];
            p -> urm = l[i];
            l[i] = p;
        }
    }
    fclose(stdin);
}
void swap(int i,int j){
    int aux;
    poz[x[i]] = j;
    poz[x[j]] = i;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}
void HeapUp(int k){
    if(k<=1)
        return;
    if(d[x[k]]<d[x[k/2]]){
        swap(k,k/2);
        HeapUp(k/2);
    }
}
void HeapDw(int r,int k){
    int st,dr,i;
    if(2*r<=k){
        st=d[x[2*r]];
        if(2*r+1<=k)
            dr=d[x[2*r+1]];
        else
            dr=st+1;
        if(st<dr)
            i=2*r;
        else
            i=2*r+1;
        if(d[x[r]]>d[x[i]]){
            swap(i,r);
            HeapDw(i,k);
        }
    }
}
void BuildH(int k){
    int i;
    for(i=1;i<=k;i++)
        HeapUp(i);
}
int scoate_heap(){
    swap(1,nh);
    poz[x[nh]]=0;
    nh--;
    HeapDw(1,nh);
    return x[nh+1];
}
void dijkstra(int S)
{
    int i,k;
    nod *p;
    for(i=1;i<=n;i++){
        x[i]=poz[i]=i;
        t[i]=0;
        d[i]=infinit;
    }
    d[S]=0;
    BuildH(n);
    nh=n;
    while(nh > 0){
        k = scoate_heap();
        p = l[k];
        while( p ){
            if(d[p->inf] > d[k]+p->c)
            {
                d[p->inf]=d[k]+p->c;
                t[p->inf]=k;
                HeapUp(poz[p->inf]);
            }
            p = p -> urm;
        }
    }
}
void lant(int i){
    if(i!=0){
        lant(t[i]);
        nr++;
        x[nr]=i;
    }
}
int main(){
    cit();
    dijkstra( S );
    FILE *f;
    f=fopen("joc.out","w");
    if(P==1)
        fprintf(f,"%d
",d[F]);
    else{
        lant(F);
        fprintf(f,"%d
",nr);
        for(int i=1;i<=nr;i++)
            fprintf(f,"%d ",x[i]);
    }
    fclose(f);
    return 0;
}