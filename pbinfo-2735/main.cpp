#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,m,k,j=0;
    cin>>n>>m>>k;
    bitset<64> bn(n),bm(m);
        for(int i=k;;i++)
        {
            bn[i]=bm[j];
            if(j==int(log2(m)))
                break;
            j++;
        }
    cout<<bn.to_ullong();
    return 0;
}