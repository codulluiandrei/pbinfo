#include <fstream>
#include <cmath>
using namespace std;
ifstream in("spiralmatrix.in");
ofstream out("spiralmatrix.out");
int l0=1,l1=1,l2=1,c0=1,c1=1,c2=1;
int main(){
    long long n,nc=0;
    int l=1,c=0,dl=0,dc=1;
    in>>n;
    long long p2=n/sqrt(2);
    if(p2*p2==n*n/2)p2--;
    nc=n*n/2-p2*p2;
    if(n%2==0){
        if(p2%2==0){
            dl=1;dc=0;
            l=c=n/2-p2/2+1;c--;
            if(nc<=p2+1){l+=nc-1;}
            else{l+=p2;c+=nc-p2-1;}
        }
        else{l=c=n/2+1+p2/2;
            dl=-1;dc=0;
            if(nc<=p2+1){l-=nc-1;}
            else{   l=n-l+1;
                    c-=nc-p2-1;
                    dl=0;dc=-1;}}}
    else{
        if(p2%2==0){
            dl=-1;dc=0;
            l=c=n/2+1+p2/2;
            if(nc<=p2+1){l+=dl*(nc-1);}
            else{   dl=0;dc=-1;
                    l-=p2;c-=nc-p2-1;}
        }
        else{l=c=n/2-p2/2+1;c--;
            dl=1;dc=0;
            if(nc<=p2+1){l+=nc-1;}
            else{   l+=p2;
                    c+=nc-p2-1;
                    dl=0;dc=1;}}}
    if(n%2==0){l1=l;c1=c;}
    else{l2=l;c2=c;
        if(l2+dl<=(n-p2)/2 || n-(n-p2)/2+1<l2+dl || c2+dc<(n-p2)/2 || n-(n-p2)/2+1<c2+dc){
            if(dl==-1 && dc==0){dl=0;dc=-1;}
            else{if(dl==0 && dc==-1){dl=1;dc=0;}
                 else{ if(dl==1 && dc==0){dl=0;dc=1;}
                       else{if(dl==0 && dc==1){dl=-1;dc=0;}}}}}
         l1=l2+dl;c1=c2+dc;}
    if(l1+dl<=(n-p2)/2 || n-(n-p2)/2+1<l1+dl || c1+dc<(n-p2)/2 || n-(n-p2)/2+1<c1+dc){
        if(dl==-1 && dc==0){dl=0;dc=-1;}
        else{if(dl==0 && dc==-1){dl=1;dc=0;}
             else{ if(dl==1 && dc==0){dl=0;dc=1;}
                   else{if(dl==0 && dc==1){dl=-1;dc=0;}}}}}
    l0=l1+dl;c0=c1+dc;
    out <<  l0 <<  << c0 << endl;
    if(n%2==0)out <<  l1 <<  << c1 << endl;
    else out <<  l2 <<  << c2 << endl;
    return 0;}