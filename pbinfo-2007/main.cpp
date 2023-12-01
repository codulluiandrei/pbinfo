//Emanuela Cerchez 90 puncte + 10 din oficiu
#include <fstream>

using namespace std;
ifstream fin("numere17.in");
ofstream fout("numere17.out");
int c, n, K, nr, sum;

int main()
{int lin, col, i, j, d, ultim;
 fin>>c;
 if (c==1)
    {
     fin>>n;
     col=1;
     for (i=0; i<n; i++)
         {
          fin>>d;
          col+=d-1;
         }
      lin=n+1;
      nr=lin*(lin-1)/2;//1+2+...lin-1
      nr+=col;
      fout<<nr<<'\n';
    }
    else
    {
      fin>>K;
      for (lin=1; K>lin*(lin+1)/2; lin++);
      col=K-lin*(lin-1)/2;
      sum=ultim=0;
      for (i=1; i<=col; i++)
            {ultim+=i;
             sum+=ultim;}
       for (i=col+1; i<=lin; i++)
           {
            ultim+=i;
            sum+=(ultim-(i-col));
           }
       fout<<sum<<'\n';
    }
    fout.close();
    return 0;
}
