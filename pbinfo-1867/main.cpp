#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cuvant2.in");
ofstream fout("cuvant2.out");
char cuv[256];
int sol,mx=0;
bool e_palindrom(int st, int dr)
{
    while(st<dr)
    {
        if(cuv[st]!=cuv[dr])
            return false;
        st++;
        dr--;
    }
    return true;
}
int main()
{
    fin>>cuv;
    int L=strlen(cuv);
    fin.close();
    int i,j,s[256],nrmin;
    for(i=0;i<L;i++)
        if(e_palindrom(0,i))
        {
            s[i]=1;
            mx=max(mx,i+1);;
        }
        else
        {
            nrmin=257;
            for(j=0;j<i;++j)
                if(e_palindrom(j+1,i) && s[j]<nrmin)
                {
                    nrmin=s[j];
                    mx=max(mx,i-j);
                }
            s[i]=nrmin+1;
        }
    sol=s[L-1];
    fout<<sol<<' '<<mx;
    fout.close();
    return 0;
}