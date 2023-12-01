///100p
#include <fstream>
using namespace std;
ifstream fin("ceas.in");
ofstream fout("ceas.out");
int n,C,k;
int main()
{
    fin>>C>>k>>n;
    ///cerinta C=1
    int nr_k=0,nr_t=0,x;
    if(C==1)
    {
        for(int i=1; i<=n; i++)
        {
            fin>>x;
            if(x==k) nr_k++;
            else
            while(x>0)
            {
                if(x%10==k) nr_k++;
                x/=10;
            }
        }
        fout<<nr_k;
    }
    if(C==2)///cerinta C=2
    {
        for(int i=1; i<=n; i++)
        {
            fin>>x;
            while(x>12)
            {
                if(x%100<=12&&x%100>=10)
                    x/=100;
                else
                    x/=10;
                nr_t++;
            }
        }
        fout<<nr_t;
    }
    fin.close();
    fout.close();
    return 0;
}
