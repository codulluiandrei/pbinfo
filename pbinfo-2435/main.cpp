// Prof Marcel Dragan
// Colegiul National Samuel von Bruckenthal
// Complexitate: O(n^2)

#include <fstream>
using namespace std;
ifstream in("fadema.in");
ofstream out("fadema.out");

short n,m,a[1001][1001],mr1[1001][1001],mr2[1001][1001],mc[1001][1001],mc1[1001][1001],mc2[1001][1001];

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            in>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>0;j--){
            if(j==m){
                mr2[i][j]=1;
            }
            else{
                if(a[i][j]+a[i][j+1]==1){
                    mr2[i][j]=mr2[i][j+1]+1;
                }
                else{
                    mr2[i][j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==1){
                mr1[i][j]=1;
            }
            else{
                if(a[i][j]+a[i][j-1]==1){
                    mr1[i][j]=mr1[i][j-1]+1;
                }
                else{
                    mr1[i][j]=1;
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1){
                mc1[i][j]=mr1[i][j];
                mc2[i][j]=mr2[i][j];
                mc[i][j]=1;
            }
            else{
                if(a[i][j]+a[i-1][j]==1){
                    mc1[i][j]=min(mc1[i-1][j],mr1[i][j]);
                    mc2[i][j]=min(mc2[i-1][j],mr2[i][j]);
                    mc[i][j]=mc[i-1][j]+1;
                }
                else{
                    mc1[i][j]=mr1[i][j];
                    mc2[i][j]=mr2[i][j];
                    mc[i][j]=1;
                }
            }
        }
    }
    int M=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M<mc[i][j]*(mc1[i][j]+mc2[i][j]-1))
                M=mc[i][j]*(mc1[i][j]+mc2[i][j]-1);
        }
    }
    out << M << endl;
    return 0;
}
