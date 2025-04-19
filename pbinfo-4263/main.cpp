#include <fstream>
using namespace std;
ifstream fin("ifelse.in");
ofstream fout("ifelse.out");
char s[60001];
int n,i,op,nr;
int main()
{
    fin>>n;
    fin.get();
    for(i=1; i<=n; i++)
    {
        fin.getline(s,60001);
        op=0,nr=0;
        int k=0;
        for(int j=0; s[j]!=0; j++)
            if(s[j]=='i')
            {
                nr++;
                j++;
                k++;
            }
            else if(s[j]=='e')
            {
                nr--;
                k++;
                if(nr<0)
                {
                    op++;
                    nr=1;
                }
                j=j+3;
            }
        if(k%2!=0)
            fout<<-1<<'\n';
        else
            fout<<nr/2+op<<'\n';
    }
    return 0;
}