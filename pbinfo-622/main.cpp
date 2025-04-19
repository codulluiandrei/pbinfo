#include<stdio.h>
#define min(a,b) (a)<(b) ? (a) : (b)
#define max(a,b) (a)>(b) ? (a) : (b)
int n,m,p1,p2,p,minim,maxim,i;
void swap(int &a,int &b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}
int main(){
    FILE *f,*g;
    f=fopen("multimi2.in","r");
    fscanf(f,"%d%d%d%d%d",&p,&n,&p1,&m,&p2);
    fclose(f);
    if(p1>p2){
        swap(p1,p2);
        swap(n,m);
    }
    g=fopen("multimi2.out","w");
    if(p==2){
        if(p2>p1+n-1)
            fprintf(g,"-1\n");
        else{
            minim=min(p1+n-1,p2+m-1);
            for(i=p2;i<=minim;i++)
                fprintf(g,"%d ",i);
        }
    }else{
        if(p2>p1+n-1){
            for(i=p1;i<=p1+n-1;i++)
                fprintf(g,"%d ",i);
            for(i=p2;i<=p2+m-1;i++)
                fprintf(g,"%d ",i);
        }else{
            maxim=max(p1+n-1,p2+m-1);
            for(i=p1;i<=maxim;i++)
                fprintf(g,"%d ",i);
        }
    }
    fclose(g);
    return 0;
}