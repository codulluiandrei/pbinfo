/*
  implementare Adrian Panaete
  Complexitate O((m + n) log(m+n))
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,k,x,sol,v[100010];
int main()
{
    freopen("unudoi.in","r",stdin);
    freopen("unudoi.out","w",stdout);
    scanf("%d%d",&n,&m);
    //pun toate valorile intr-un sir
    for(i=1;i<=n;i++){scanf("%d",&x);v[++k]=2*x;}//valorile x din a[] se inlocuiesc cu 2*x
    for(i=1;i<=m;i++){scanf("%d",&x);v[++k]=2*x+1;}//valorile din b[] se inlocuiesc cu 2*x+1
    //daca aveam a[i]<=b[i] acum am a[i]< b[i]
    //deoarece x<=y => 2x<=2y => 2x<2y+1
    //daca aveam a[i] > b [i] ramane valabil a[i] > b[i]
    // deoarece x > y => x>=y+1 => 2x >= 2y+2 2x > 2y+1
    //sortez valorile
    sort(v+1,v+k+1);
    // daca aveam a[i]=b[j] atunci a[i] apare inaintea lui b[j]
    //deci orice a este dupa b-urile strict mai mici si inaintea celor mai mari sau egale
    //toate a-urile situate consecutiv in sirul sortat dau linii identice
    //trebuie sa gasesc numarul "platourilor" formate numai din a-uri deci platourile de valori pare
    // deci e suficient sa pastrez resturile modulo 2
    for(i=1;i<=k;i++)v[i]=v[i]%2;
    //gasesc secventele de 0 consecutive varificand de cate ori am un 0 precedat de un 1
    //pentru a nu pierde prima secventa pun v[0] = 1
    v[0]=1;
    for(i=1;i<=k;i++)if(v[i]==0&&v[i-1]==1)sol++;
    printf("%d\n",sol);
    return 0;
}