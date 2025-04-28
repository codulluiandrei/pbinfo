///yin-yang
///O(n*m*(n+m))
#include<stdio.h>
int n,m,a[1002][1002],i,j,k,x,nr,c1,c2;
int main(){
    FILE *fin,*fout;
    fin= fopen("yinyang.in","rt");
    fout=fopen("yinyang.out","wt");
    fscanf(fin,"%d %d\n",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            fscanf(fin,"%d ",&x);
            a[i][j]=x;
        }
    }
    nr=0;
    for(i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++){
            int r=0;c1=0;c2=0;
            for(k=1;k<=m;k++){
                if(a[i][k]<a[j][k]){
                    if(r==0)r=-1;
                    c1++;
                }
                if(a[i][k]>a[j][k]){
                    if(r==0)r=+1;
                    c2++;
                }
            }
            if(c1 && c2){fprintf(fout,"-1");fclose(fout);fclose(fin);return 0;}
            if(r>0)nr++;
        }
    }
    for(i=1;i<=m-1;i++){
        for(j=i+1;j<=m;j++){
            int r=0;c1=0;c2=0;
            for(k=1;k<=n;k++){
                if(a[k][i]<a[k][j]){
                    if(r==0)r=-1;
                    c1++;
                }
                if(a[k][i]>a[k][j]){
                    if(r==0)r=+1;
                    c2++;
                }
            }
            if(c1 && c2){fprintf(fout,"-1");fclose(fout);fclose(fin);return 0;}
            if(r>0)nr++;
        }
    }
    fprintf(fout,"%d",nr);
    fclose(fout); fclose(fin);
    return 0;
}