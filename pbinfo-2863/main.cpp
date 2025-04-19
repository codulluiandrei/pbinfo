#include <fstream>
using namespace std;
int ciur[10001], pt[10001];
int main()
{
    ifstream f("pyk.in");
    ofstream g("pyk.out");
    int n, k, y, x,s, c,t,i, j, xmin=10000, xmax=-1,p,d,m=0,nr=0,eg=0, mare=0,pmax=0;
    bool ok;
    f>>c;
    if(c==1)
        {f>>k>>n;
         for(i=1;i<=n;i++) {f>>x;
                            y=x;
                            ok=0;
                            while(y>9 && ok==0)
                                if(y%10!=y/10%10) ok=1;
                                            else y=y/10;
                            if (ok==0) {if(x>xmax) xmax=x;
                                        if(x<xmin) xmin=x;
                                       }
                             }
            if(xmax==-1) g<<1;
                    else g<<xmin<<' '<<xmax;
        }
    else {f>>k>>n;
    for(i=2;i<=10000;i++)
        if(ciur[i]==0)
         for(j=2;j*i<=10000;j++) ciur[i*j]=1;
         ciur[1]=1;
    //    for(i=1;i<=10000;i++) if (ciur[i]==0) g<<i<<' ';
            xmax=0;
          for(i=1;i<=n;i++) {f>>x;
                             d=2;
                             p=0;
                             while(x%2==0) {p++; x=x/2;}
                             if(p!=0) {pt[2]=pt[2]+p;
                                       if(d>xmax) xmax=d;}
                             if(x!=1) {d=3;
                                        while(x!=1){p=0;
                                                    while(x%d==0&&x!=1)  {p++;
                                                                          x=x/d;}
                                                    if(p!=0) {pt[d]=pt[d]+p;
                                                              if(d>xmax) xmax=d;}
                                                    if(d*d<=x) d=d+2;
                                                         else d=x;
                                                   }
                                           }
                     //       if(x!=1) pt[x]++;
                             }
           for(i=2;i<=xmax;i++) if (pt[i]!=0)
                                        if(pt[i]%k!=0) m++;
           if (m!=0) {g<<m<<'\n';
                      for(i=2;i<=xmax;i++) if (pt[i]!=0 && pt[i]%k!=0) g<<i<<' '<<k-pt[i]%k<<'\n';}
                else  g<<1<<'\n'<<2<<' '<<k;
         }
}