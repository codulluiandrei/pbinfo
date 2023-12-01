#include <iostream>///Flavius Boian 
#include <fstream> 
#include <algorithm> 
using namespace std; 
  
ifstream f("cort.in"); 
ofstream g("cort.out"); 
  
int C,N,M,i,j,x,ok,nr,maxim,k,v[1001],s,t; 
int main() 
{ 
    f>>C; 
    if(C==1) 
    { 
        f>>N>>M; 
        for(i=1; i<=N; i++) 
        { 
            ok=0; 
            for(j=1; j<=M; j++) 
            { 
                f>>x; 
                if(x==1) 
                    ok=1; 
            } 
            if(ok==1) 
                nr++; 
        } 
        g<<nr; 
    } 
    if(C==2) 
    { 
        f>>N>>M; 
        for(i=1; i<=N; i++) 
        { 
            k=0; 
            for(j=1; j<=M; j++) 
            { 
                f>>x; 
                k=k+x; 
            } 
            v[++t]=k; 
        } 
        sort(v+1,v+t+1); 
        for(i=1; i<=t; i++) 
            if(v[i]*(N-i+1)>maxim) 
                maxim=v[i]*(N-i+1); 
        g<<maxim; 
    } 
    return 0; 
} 