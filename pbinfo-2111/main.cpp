#include <fstream>

using namespace std;
ifstream fin("centrale.in");
ofstream fout("centrale.out");
int n,x,i,a,k;
int main()
{
    fin>>n;
    k=0; int nr=0;
    for(i=1;i<=n;i++)
     {
        fin>>x;
        x=x/10;
        a=x%10;
        while(x>9 && x%10==a)
           x=x/10;
        if(x<=9)
           k++;
    }
    fout<<k<<'\n';
    fout.close();
    return 0;
}
