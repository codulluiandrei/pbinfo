/// prof. Szabo Zoltan
/// ISJ Mures Tg Mures 
#include <fstream>
using namespace std;
ifstream fin ("partit.in");
ofstream fout("partit.out");
int main()
{
    long long n,k,cazuri,t;
    int opt;
    fin>>opt;
    if(opt==1)
    {
        fin>>n>>k;
///        fout<<2<<" "<<n<<endl;
        t=1;
        while (n>63)
        {
            fout<<1<<" ";
            n--;
        }
        cazuri=1LL<<(n-1);
        while(cazuri>=1)
        {
            if (k==1)
            {
                fout<<t<<" ";
                while (cazuri>1)
                {
                    fout<<1<<" ";
                    cazuri=cazuri/2;
                }
                fout<<"\n";
            }
            else
                if (k<=cazuri/2)
                {
                    fout<<t<<" ";
                    t=1;
                }
                else
                {
                    t++;
                    k=k-cazuri/2;
                }
            cazuri=cazuri/2;
        }
    }
    else
    {
        fin>>n;
        k=0;
        while(fin>>t)
        {
            if(t>1)
            {
                cazuri=1LL<<(n-1);
                for(long long i=1;i<t;i++)
                {
                    cazuri/=2;
                    k+=cazuri;
                }
            }
            n-=t;
        }
        fout<<k+1;
    }
    return 0;
}