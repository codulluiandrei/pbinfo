//Florentina Ungureanu - Colegiul National de Informatica Piatra-Neamt
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
unsigned n, v, a, b, c;
ifstream f("babilon.in");
ofstream g("babilon.out");
int main()
{
    long long z=0;
    unsigned i, fr, fmax;
    f>>v>>n;
    if(v==1)
    {
        f>>a;
        fmax=fr=a==1;
        for(i=2;i<=n;i++)
        {
            f>>b;
            if(a*b==1) fr++;
              else  {
                        if (fr>fmax) fmax=fr;
                        fr=b==1;
                    }
            a=b;
        }
      if (fr>fmax) fmax=fr;
      g<<fmax<<'\n';
    }
    else
    { f>>a;
      if(a==1)z=1;
          else if(a==2)z=10;
                else z=0;
      for(i=2;i<=n;i++)
        {
            f>>b;
            if (b>a) z=z*60;
            if(b==1)z++;
                else if(b==2)z+=10;
            if (b!=3)   a=b;
        }
      g<<z<<'\n';
    }
    f.close();
    g.close();
    return 0;
}