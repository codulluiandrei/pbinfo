/*
Solutie de 70 puncte. Complexitate O(T*N*logM + MlogM)
- sortare + cautare binara pe fiecare linie
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const char InFile[]="gustare.in";
const char OutFile[]="gustare.out";
const int MaxN=100111;
int N,M,T;
int V1[MaxN],V2[MaxN];
int X;
inline void Precompute()
{
    sort(V2+1,V2+1+M);
}
inline bool BinarySearch(const int &val)
{
    int first=0;
    int step=1<<16;
    for(;step;step>>=1)
    {
        int index=first+step;
        if(index<=M)
        {
            if(V2[index]<=val)
            {
                first=index;
            }
        }
    }
    if(first==0)
    {
        return false;
    }
    return val==V2[first];
}
inline bool Query(const int &val)
{
    for(int i=1;i<=N;++i)
    {
        if(BinarySearch(val-V1[i]))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen(InFile,"r",stdin);
    freopen(OutFile,"w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d",V1+i);
    }
    scanf("%d",&M);
    for(int i=1;i<=M;++i)
    {
        scanf("%d",V2+i);
    }
    Precompute();
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        scanf("%d",&X);
        if(Query(X))
        {
            printf("DA\n");
        }
        else
        {
            printf("NU\n");
        }
    }
    return 0;
}