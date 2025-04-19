#include <fstream>
using namespace std;
ifstream f("echer.in");
ofstream g("echer.out");
int m,n,l1,l2,x,y,cer,k=0, mi, ma,i;
int main()
{
    f>>cer>>l1>>l2>>m>>n;
    x=m/l1;y=n/l2;
    mi=x>y?y:x;ma=x+y-mi;
    if(x==y) k=3*x-2;
        else if(x-y==1)k=3*y-1;
         else if(y-x==1)k=3*x-1;
          else
            {
                k=3*mi-2;
                k+=2*(ma-mi);
                if((ma-mi)%2)k--;
            }
    if(cer==1) g<<k<<'\n';
    else {g<<1;k--;
          for(i=1;i<mi;i++)
            {g<<" 2 3 1";k-=3;}
          if(x==y) {g<<'\n';return 0;}
            else if(x-y==1){g<<" 4\n";k--;return 0;}
            else if(y-x==1){g<<" 2\n";k--;return 0;}
          if(x-y>1)
            {while(k>=4)
                {g<<" 4 6 3 1";k-=4;}
             if(k)g<<" 4\n";}
           else if(y-x>1)
            {while(k>=4)
                {g<<" 2 7 5 1";k-=4;}
             if(k)g<<" 2\n";}
    }
    return 0;
}