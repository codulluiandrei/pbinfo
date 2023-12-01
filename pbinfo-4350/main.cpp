#include <fstream>
using namespace std;
ifstream fin ("drone.in");
ofstream fout ("drone.out");
int n, i, cod, cerinta, drinlocuite, prcif,  p;
int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>cod;
        p=1;
        if(cod==0) drinlocuite++;
        else
        {

             while(cod>=10)
                {
                    p=p*(cod%10);
                    cod=cod/10;
                }
             prcif=cod;
             p=p*prcif;

         if (prcif<7 && p%2==0 )
                drinlocuite++;

        }
    }
    fout<<drinlocuite;
    return 0;
}
