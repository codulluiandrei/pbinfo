// sursa oficiala - prof.Ana Intuneric
#include <fstream>
using namespace std;
ifstream f("martisoare.in");
ofstream g("martisoare.out");
int N,i,c1,c2,c3,c4,x,y,maxi,gasit;
int main()
{
    f>>N;
    f>>c1>>c2;
    //caut primul numar modificat
    if(c2-c1==1)
    {
        maxi=c1+N-1;
        for(i=3;i<=N && !gasit;i++)
        {
            f>>c3;
            if(c3-c2!=1)
            {
              x=c2+1;y=c3;gasit=1;
              while(x!=0 && y!=0)
              {
                  if(x%10!=y%10)
                        {if(x%10<y%10) g<<x%10<< " " <<y%10<<endl;
                        else  g<<y%10<< " " <<x%10<<endl;break;}
                  else x/=10,y/=10;
              }
            }
            else c2=c3;
        }
    }
    else
    {
      f>>c3>>c4;
      //c1 modificat
      if(c3-c2==1){x=c2-1;y=c1;gasit=1;maxi=c2+N-2;}
      else if(c4-c2==2){x=c2-1;y=c1;gasit=1;maxi=c4+N-4;}
           //c2 este modificat
           else if(c4-c3==1){x=c2;y=c3-1;gasit=1;maxi=c3+N-3;}
                else if(c3-c1==2) {x=c2;y=c3-1;gasit=1;maxi=c3+N-3;}//c2 modificat si c3 este bun
                     else {x=c2;y=c4-2;gasit=1;maxi=c4+N-4;}//c2 modificat si c4 este bun
      while(x!=0 && y!=0)
      {
                  if(x%10!=y%10)
                        {if(x%10<y%10) g<<x%10<< " " <<y%10<<endl;
                         else  g<<y%10<< " " <<x%10<<endl;break;
                        }
                  else x/=10,y/=10;
      }
    }
    if(!gasit) g<<"0 0\n";
    g<<maxi<<endl;
    f.close();g.close();return 0;
}