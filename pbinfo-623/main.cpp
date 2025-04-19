#include<stdio.h>
FILE *f,*g;
int play(int a,int b,int c,int p){
    int s,aux;
    if(p==1){
        s=0;
        while(a){
            s+=a%10;
            a/=10;
        }
        while(b){
            s+=b%10;
            b/=10;
        }
        while(c){
            s+=c%10;
            c/=10;
        }
        fprintf(g,"%d\n",s);
        return 0;
    }
    fprintf(g,"%d %d\n",a,b);
    while(a<c&&b>c){
        aux=a;
        s=0;
        while(aux){
            s+=aux%10;
            aux/=10;
        }
        a+=s;
        aux=b;
        s=0;
        while(aux){
            s+=aux%10;
            aux/=10;
        }
        b-=s;
        fprintf(g,"%d %d\n",a,b);
    }
    if(a>=c)
        if(b<=c)
            return 0;
        else
            return 1;
    else
        return 2;
}
int main(){
    int p,a,b,c,w;
    f=fopen("numere3.in","r");
    g=fopen("numere3.out","w");
    fscanf(f,"%d%d%d%d",&p,&a,&c,&b);
    fclose(f);
    w=play(a,b,c,p);
    if(p==2)
        fprintf(g,"%d\n",w);
    fclose(g);
    return 0;
}