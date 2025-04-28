#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("turn_1.in");
ofstream fout("turn_1.out");
struct cub { int l; char c[22];};
int H,n,X[20],P[20];
cub A[20];
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        fout<<X[i]<<" ";
    fout<<"\n";
}
void back(int k, int s)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            s=s+A[X[k]].l;
            if(k==1 || (strcmp(A[X[k]].c,A[X[k-1]].c)!=0 && A[X[k]].l<=A[X[k-1]].l && s<=H))
            {
                if(s==H) afisare(k);
                else back(k+1,s);
            }
            s=s-A[X[k]].l;
            P[i]=0;
        }
}
int main()
{
    fin>>n>>H;
    for(int i=1;i<=n;i++)
        fin>>A[i].l>>A[i].c;
    back(1,0);
    return 0;
}