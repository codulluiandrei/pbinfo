//sursa oficiala - prof. Carmen Minca - C.N.I.T.Vianu- Bucuresti

#include <fstream>
using namespace std;
/*a) numarul P al piramidei ce conține cartonasul numerotat cu X;
  b) numarul M maxim de piramide construite de Gigel;
  c) numarul C de cartonașe nefolosite;
  d) numarul A al primei piramide care contine cele mai multe cartonașe albe.
*/
int n, x, k;
ifstream f("piramide.in");
ofstream g("piramide.out");

int main()
{
    int p=0, a=0, m=0, c=0,i,ca,b=1,cfol=0,cp,nra, maxnra=0;
    f>>n>>x>>k;
    i=1;
    f>>ca;
    do  //caut piramida ce contine cartonasul alb cu numarul ca
        {  b++;//nr cartonase din baza piramida curenta
           nra=0;//caut in piramida curenta cartonasele albe
           cp=b*(b+1)/2; //nr cartonase din care e formata piramida curenta
           if(cp+cfol<=n)  //daca am cele cp cartoane atunci pot construi piramida
             {  m++; //numar piramida construita
                if(cfol<x && x<=cp+cfol) p=m; //verif daca contine cartonasul x
                cfol+=cp;
                while(ca<=cfol && i<=k)
                    { nra++;f>>ca;i++;} //numar cartonasele albe din piramida
                if(nra>maxnra)
                    { a=m; maxnra=nra; }
             }
             else break;
         } while (cfol<n);
    c=n-cfol;
    g<<p<<endl<<m<<endl<<c<<endl<<a<<endl;
    return 0;
}

