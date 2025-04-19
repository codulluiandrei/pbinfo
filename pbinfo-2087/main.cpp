# include <cstdio>
# include <climits>
# include <cstring>
# define maxn 10002
using namespace std;
int A[maxn],B[maxn],ind[maxn];
int n,m,k;
int main()
{
    int i,j,min_sum,min_index;
    freopen("kminsum.in","r",stdin);
    freopen("kminsum.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(i=0; i<n; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i=0; i<m; ++i)
    {
        scanf("%d", &B[i]);
    }
    while (k--)
    {
        min_sum=INT_MAX;
        min_index=0;
        for (j=0; j<n; ++j)
        {
            if (ind[j]<m && A[j]+B[ind[j]]<min_sum)
            {
                min_index=j;
                min_sum=A[j]+B[ind[j]];
            }
        }
        printf("%d %d\n",A[min_index],B[ind[min_index]]);
        ind[min_index]++;
    }
    return 0;
}