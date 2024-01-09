#include <fstream>
using namespace std;
ifstream fin("summax_xi.in");
ofstream fout("summax_xi.out");

int main()
{
   int n,A[101][101],smax=0;
   fin>>n;
   for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          fin>>A[i][j];
   for(int i=1;i<=n;i++)
   {
       int max=-10000;
       for(int j=1;j<=n;j++)
            if(A[i][j]>max)
                max=A[i][j];
       smax=smax+max;
   }
   fout<<smax;
   return 0;
}
