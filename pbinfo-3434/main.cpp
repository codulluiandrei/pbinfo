/**
Cristina Iordaiche
*/
#include <fstream>

using namespace std;
ifstream f("furnica.in");
ofstream g("furnica.out");
long long dist_coborare,dist_urcare,dist_oriz,lungime,maxi,TIMP;
int main()
{
    int H,L,H1,L1,n,i,cerinta,t_oriz,t_urcare,t_coborare,cladire;
    t_urcare=5;t_oriz=3;t_coborare=2;

    f>>cerinta>>n;
    if (cerinta==3)
        f>>TIMP;
    f>>L1>>H1;
    H=H1;
    dist_urcare=H1;dist_oriz=L1;dist_coborare=0;
    lungime=H1+L1;
    maxi=lungime;
    i=1;
    TIMP=TIMP-(dist_urcare*t_urcare+dist_oriz*t_oriz);
    if (TIMP<=0)
        cladire=1;
    for(i=2; i<=n; i++)
    {
        f>>L>>H;
        dist_oriz=dist_oriz+L;
        if(H>=H1)           //  URCARE
        {
            lungime=lungime+H-H1+L;
            dist_urcare=dist_urcare+H-H1;
            if (TIMP>0)
            {
                TIMP=TIMP-(H-H1)*t_urcare;
                if(TIMP<=0)
                    cladire=i;
            }
        }
        else          // COBORARE
        {
            dist_coborare=dist_coborare+H1-H;
            lungime=L;
            if (TIMP>0)
            {
                TIMP=TIMP-(H1-H)*t_coborare;
                if(TIMP<=0)
                    cladire=i-1;
            }
        }
        if (TIMP>0)
        {
            TIMP=TIMP-L*t_oriz;
            if (TIMP<=0)
                cladire=i;
        }
        if (lungime>maxi)
            maxi=lungime;
        H1=H;
        L1=L;
    }
    if (TIMP>0)
        if(TIMP-H*t_coborare<=0)
            cladire=n;
        else cladire=-1;

    if (cerinta==1)
        g<<(dist_oriz*t_oriz+dist_urcare*t_urcare+(dist_coborare+H)*t_coborare)<<'\n';
    else if (cerinta==2)
        g<<maxi<<'\n';
    else if (cerinta==3)
        g<<cladire<<'\n';
    return 0;
}
