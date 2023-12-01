#include <fstream>

using namespace std;
ifstream fin("tan.in");
ofstream fout("tan.out");

unsigned long long n;
int f[10],i,p;

int main()
{
    fin>>n;
    while(n)
    {
        f[n%10]++;
        n/=10;
    }
    if (f[0])
    {
        i=1;
        while (!f[i]) i++;
        fout<<i;
        f[i]--;
    }
    i=8;
    while(i>=0 && f[i]==0) i=i-2;
    p=i;
    f[i]--;
    for(i=0;i<10;i++)
        while(f[i])
        {
            fout<<i;
            f[i]--;
        }
    fout<<p;
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}
