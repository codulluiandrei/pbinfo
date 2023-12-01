#include <stdio.h>
#include <assert.h>
#define NMAX 100001
long long n, lg;
long long nr;
long long x[NMAX], fr[NMAX];
long long complementar(long long x);
long long redus (long long x);
long long farazero(long long x);
long long lungime(long long x);
int main(){
    long long i, aux, v, ok;
    FILE *fin=fopen("puzzle.in","r");
    FILE * fout=fopen("puzzle.out","w");
    ok=fscanf(fin,"%d", &n);
    assert(ok==1);
    assert(n>1 && n<=100000);
    for (i=1; i<=n; i++){
        ok=fscanf(fin,"%d", &x[i]);
        assert(ok==1);
        assert(x[i]>0 && x[i]<=99999);
        assert(farazero(x[i]));
        aux=redus(x[i]);
        fr[aux]++;
    }
    aux=x[1];
    v=0;
    while (aux>0) {
        v=v*10+1;
        aux/=10;
    }
    lg=lungime(x[1]);
    for (i=2; i<=n; i++)
        assert(lungime(x[i])==lg);
    for (i=1; i<=9*v; i++){
        aux=complementar(i);
        nr=nr+fr[i]*fr[aux];
    }
    nr=nr+fr[0]*(fr[0]-1);
    nr/=2;
    fprintf(fout,"%lld\n",nr);
    fclose(fout);
    return 0;
}

long long complementar(long long x){
    long long p=1, cx=x, uc, i;
    long long cmax=0;
    long long nr=0;
    while (x) {
        if (x%10>cmax)
            cmax=x%10;
        x/=10;
    }
    for (i=0; i<lg; i++){
        uc=cmax-cx%10;
        nr=nr+uc*p;
        p*=10;
        cx/=10;
    }
    return nr;
}

long long redus (long long x){
    long long p=1, cx=x, uc;
    long long cmax=0, cmin=9;
    long long nr=0;
    while (x){
        if (x%10>cmax)
            cmax=x%10;
        if (x%10<cmin)
            cmin=x%10;
        x/=10;
    }

    while (cx>0){
        uc=cx%10-cmin;
        nr=nr+uc*p;
        p*=10;
        cx/=10;
    }
    return nr;
}
long long farazero(long long x){
    while (x>0){
        if (x%10==0)
            return 0;
        x/=10;
    }
    return 1;
}

long long lungime(long long x){
    long long lg=0;
    while (x>0){
        lg++;
        x/=10;
    }
    return lg;
}
