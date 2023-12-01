#include<fstream>

using namespace std;
ifstream f("lego.in");
ofstream g("lego.out");

int v, nc1[10], nc2[10], nr[10], cif[10], ncif, nrcif;
unsigned long long S,n1,n2,dif;

unsigned long long construire_N2(unsigned long long m, int rep[]){
    unsigned long long nr=m;
    int i,j;
    for(i=9;i>=0;i--){
        for(j=1;j<=rep[i];j++){
            nr=nr*10+i;
        }
    }
    return nr;
}
int cifre(int v, int rep[]){
    int i;
    for(i=v+1;i<=9 && rep[i]==0;i++);
    return i;
}
int cifre2(int v, int rep[]){
    int i;
    for(i=v-1;i>=0 && rep[i]==0;i--);
    return i;
}
unsigned long long construire_N1(unsigned long long m, int rep[]){
    unsigned long long nr=m;
    int i,j,y;
    if(m==0){
        y=cifre(0,rep);
        nr=nr*10+y;
        rep[y]--;
    }
    for(i=0;i<=9;i++){
        for(j=1;j<=rep[i];j++){
            nr=nr*10+i;
        }
    }
    if(m==0)rep[y]++;
    return nr;
}
void nr_mic(unsigned long long z,int rep[], int cif){
    int y;
    unsigned long long x;
    y=cifre(cif,rep);
    if(y<10){
        rep[y]--;
        x=construire_N1(z*10+y,rep);
        rep[y]++;
        if(x<n2){
            n2=x;
        }
    }
}
void nr_mare(unsigned long long z,int rep[], int cif){
    int y;
    unsigned long long x;
    y=cifre2(cif,rep);
    if(y>=0){
        rep[y]--;
        x=construire_N2(z*10+y,rep);
        rep[y]++;
        if(x>n1){
            n1=x;
        }
    }
}
int main(){

    int xn, xc,ns,cifs[30],i;
    unsigned long long x,z;
    f>>v>>S;
    ncif=0;
    nrcif=0;
    while(f>>xn>>xc){
        nc1[xc]=xn;
        nc2[xc]=xn;
        nr[ncif]=xn;
        nrcif+=xn;
        cif[ncif]=xc;
        ncif++;
    }
    f.close();
    x=S;
    ns=0;
    do{cifs[ns]=x%10; ns++;x=x/10;}while(x!=0);
    if(nrcif<ns){
        n2=0;
    }
    else{
        if(nrcif>ns){n2=construire_N1(0,nc2);}
        else{
            n2=construire_N2(0,nc2);
            if(n2<=S){
                n2=0;
            }
            else{
                i=ns-1;
                nr_mic(0,nc2,cifs[i]);
                z=0;
                i=ns-1;
                while(i>=0 && nc2[cifs[i]]>0){
                    z=z*10+cifs[i];
                    nc2[cifs[i]]--;
                    i--;
                    if(i>=0){
                        nr_mic(z,nc2,cifs[i]);
                    }
                }
                if(i>=0){
                    nr_mic(z,nc2,cifs[i]);
                }
            }
        }
    }
    if(nrcif>ns){
        n1=0;
    }
    else{
        if(nrcif<ns){n1=construire_N2(0,nc1);}
        else{
            n1=construire_N1(0,nc1);
            if(n1>=S){
                n1=0;
            }
            else{
                i=ns-1;
                nr_mare(0,nc1,cifs[i]);
                z=0;
                i=ns-1;
                while(i>=0 && nc1[cifs[i]]>0){
                    z=z*10+cifs[i];
                    nc1[cifs[i]]--;
                    i--;
                    if(i>=0){
                        nr_mare(z,nc1,cifs[i]);
                    }
                }
                if(i>=0){
                    nr_mare(z,nc1,cifs[i]);
                }
            }
        }
    }
    if(v==1){
        g<<n1<<' '<<n2<<'\n';
    }
    else{
        if(n1==0){
            dif=n2-S;
        }
        else{
            if(n2==0){
                dif=S-n1;
            }
            else{
                if(S-n1<n2-S){
                    dif=S-n1;
                }
                else{
                    dif=n2-S;
                }
            }
        }
        g<<dif;
    }
    g.close();
    return 0;
}

