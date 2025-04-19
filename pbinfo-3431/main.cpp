#include <fstream>
using namespace std;
int main()
{   ifstream in ("cartonase.in");
    ofstream out ("cartonase.out");
    int n,L=1,P=0,C,s1,d1,s2,d2,i,nr=0,i1,i2,cate;
    in>>C>>n;
    if(C==1)
    {
      in>>s1>>d1;
      for(i=2;i<=n;++i)
      {
          in>>s2>>d2;
          if(d1==s2)
            P++;
          s1=s2;d1=d2;
      }
     out<<P<<endl;
    }
     if(C==2)
    {
        in>>s1>>d1; nr=1;i1=1;i2=1;
      for(i=2;i<=n;++i)
      {
          in>>s2>>d2;
          if(d1==s2)
            {
                nr++;
                if(nr>L){L=nr;}
            }
            else {nr=1;}
          s1=s2;d1=d2;
      }
      out<<L<<endl;
    }
 if(C==3)
    {
        in>>s1>>d1; nr=1;cate=1;
      for(i=2;i<=n;++i)
      {
          in>>s2>>d2;
          if(d1==s2)
            {
                nr++;
                if(nr>L){L=nr;cate=1;}
                else if(nr==L) cate++;
            }
            else {nr=1;}
          s1=s2;d1=d2;
      }
      out<<cate<<endl;
    }
    return 0;
}