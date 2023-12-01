#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cassert>
#define MRD 999999999
using namespace std;
int K, N, A, P, B, N1, N2, Nr, Na1, Na2, Special, i, p, x, d, u, nr;
bool ok;
int main()
{
    freopen("speciale.in", "r",stdin);
    freopen("speciale.out","w",stdout);
    scanf("%d
",&P);
    scanf("%d%d%d%d",&K, &N, &A, &B);
    assert(P>0 && P<=3 && K<10 && K>0 && N<=MRD && A<=MRD && B<=MRD && N>0 && A>0 && B>0 && A<=B);
    if(P==1){
    for(int i=1; i<=K; i++)
        N2=N2*10 + 10 - i;
    printf("%d
", N2);
    }
    else
    if(P==2){
    p = 1; Special=0;
    while (N/p>0 && !Special){
        Nr=N/(p*10)*p + N%p; int cn=Nr; while (cn>9)cn/=10;
        if(Nr==1 ||Nr == 9) Special = Nr;
        else{
        d=(cn==9? 1: -1);
        u=Nr%10;  ok=true;
        while (Nr>0){
          if ( u != Nr % 10 ) ok=false;
          Nr/=10; u += d;
        }
        if (ok && (d==1 && u==10 || d==-1 && u==0))
                        Special=N/(p*10)*p + N%p;
        }
        p*=10;
    }
    printf("%d
", Special);
    }
    else{
    Na1=Na2=nr=0;
    for(int i=1; i<=9 ; i++ ){
        Na1=Na1*10 + i;
        if(Na1>=A&&Na1<=B ) nr++;
        Na2=Na2*10 + 10 - i;
        if(Na2>=A&&Na2<=B) nr++;
    }
    printf("%d
", nr);
    }
    return 0;
}
