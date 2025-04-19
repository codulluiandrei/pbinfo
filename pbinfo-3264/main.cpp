#include <fstream>
using namespace std;
ifstream fin("summin_xi.in");
ofstream fout("summin_xi.out");
int main()
{
   int n,A[101][101],smin=0;
   fin>>n;
   for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          fin>>A[i][j];
   for(int j=1;j<=n;j++)
   {
       int min=10000;
       for(int i=1;i<=n;i++)
            if(A[i][j]<min)
                min=A[i][j];
       smin=smin+min;
   }
   fout<<smin;
   return 0;
}