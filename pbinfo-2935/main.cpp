#include<bits/stdc++.h>
using namespace std;

ifstream fin("robot5.in");
ofstream fout("robot5.out");

int t,n,w,x,p,poz,i,k,maxi;

int main(){
    fin>>t;
    if(t==1){
        fin>>n>>w>>x>>p;
        if(w<p-1)
            fout<<w;
        if(w>=p-1 && p>=x+1)
            fout<<w+x;
        if(w>=p-1 && p<x+1 && w<=n-1)
            fout<<p-1+w;
        if(w>=p-1 && p<x+1 && w>=n)
            fout<<p-1+((x-(p-1))/n + 1)*n + (w-n)+(x-(p-1))%n;
    }
    else{
       fin>>n>>w>>x;
       for(i=1;i<=n;i++){
            p=i;
            if(w<p-1)
                k=w;
            if(w>=p-1 && p>=x+1)
                k=w+x;
            if(w>=p-1 && p<x+1 && w<=n-1)
                k=p-1+w;
            if(w>=p-1 && p<x+1 && w>=n)
                k=p-1+((x-(p-1))/n + 1)*n + (w-n)+(x-(p-1))%n;
            if(k>maxi){
                maxi=k;
                poz=i;
            }
       }
       fout<<maxi<<" "<<poz;
    }
    return 0;
}