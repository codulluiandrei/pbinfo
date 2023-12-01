/* 
Raluca Costineanu 
cerinta 1 n * (nr patrate perfecte) 
cerinta 2 ciur (pt 1000) cu sume partiale 
*/
#include <bits/stdc++.h> 
  
using namespace std; 
  
ifstream f("cate.in"); 
ofstream g("cate.out"); 
  
int prime[1010]; 
int n, C, a, b; 
  
int main() 
{ 
    f>>C>>n; 
    if(C==1) 
    { 
        int x, ra, rb; 
        for(int i=1; i<=n; ++i) 
        { 
            f>>a>>b; 
            if(a>b) 
                x=a, a=b, b=x; 
            ra=sqrt(a); 
            rb=sqrt(b); 
            if(ra*ra<a) ra++; 
            g<<rb-ra+1<<'\n'; 
        } 
    } 
    else
    { 
        int i, j, x, ra, rb; 
        for(i=2; i<=1000; ++i) 
            prime[i]=1; 
        for(i=2; i<=31; ++i) 
            for(j=i*i; j<=1000; j += i) 
                prime[j]=0; 
        for(i=1; i<=1000; ++i) 
            prime[i]+=prime[i-1]; 
        for(int i=1; i<=n; ++i) 
        { 
            f>>a>>b; 
            if(a>b) 
                x=a, a=b, b=x; 
            ra=sqrt(a); 
            rb=sqrt(b); 
            if(ra*ra<a) ra++; 
            g<<prime[rb]-prime[ra-1]<<'\n'; 
        } 
    } 
    return 0; 
} 
