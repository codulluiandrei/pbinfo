#include <fstream>
using namespace std;
ifstream fin("traseu.in");
ofstream fout("traseu.out");
# define NRMAX 1000000
int ciur[NRMAX+1], c[1001], n, maxi, lgmax, i, poz, j, cer;
int main()
{
    fin>>n>>cer;
    for(i=1; i<=n;i++) fin>>c[i];
    for(i=2; i<=NRMAX; i++)
        if (ciur[i]==0)
            for(j=i; j<=NRMAX; j+=i)
                ciur[j]++;
    for(i=1; i<=n;i++)
        if (ciur[c[i]]>maxi)maxi=ciur[c[i]];
     if(cer==1){
        for(i=1; i<=n;i++)
            if(ciur[c[i]]==maxi) fout<<c[i]<<" ";
                }
    else {
        lgmax=0;
        for(i=1; i<=n;i++)
            if(ciur[c[i]]==maxi){
                if(lgmax==0)lgmax=i;
                else if(i-poz>lgmax)lgmax=i-poz;
                poz=i;
                }
        if (ciur[c[n]]!=maxi)
            if(n-poz+1>lgmax) lgmax=n-poz+1;
        fout<<lgmax;
    }
    return 0;
}