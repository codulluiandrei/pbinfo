//Adriana Simulescu
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{ int N,i,cod,h,m,s,ok,cod1,cod2,ap[10],c,c1,j,T,t,v,r,ncorecte=0,cif,ci,cp,pp,p2,pi;
 ifstream in("robot4.in");
 ofstream out("robot4.out");
 in>>T;
 in>>N>>h>>m>>s;
 in>>t>>v>>r;
 if(T==2)
 for(i=1;i<=N;i++)
 {
     in>>cod;
     cod2=0;
     ci=0;cp=0;pp=1;pi=1;
     for(cif=1;cif<=9;cif=cif+2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;ci++; pi*=10;
                }
            cod1/=10;

            }
        }
        for(cif=8;cif>=0;cif=cif-2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;cp++; pp*=10;}
                cod1/=10;

            }
        }

      if(cod==cod2&&ci*cp!=0)
        out<<cod<<'\n';
      else
      {

        if(ci*cp!=0)
            out<<cod2<<'\n';
        else {if(ci==0)
                cod2=cod2%(pp/10)+9*(pp/10);
              else
                cod2=cod2%(pi/10)*10;
              out<<cod2<<'\n';
            }
     }

}
else
{
    for(i=1;i<=N;i++)
 {
     in>>cod;
     cod2=0;
     ci=0;cp=0;pp=1;pi=1;
     for(cif=1;cif<=9;cif=cif+2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;ci++; pi*=10;
                }
            cod1/=10;

            }
        }
        for(cif=8;cif>=0;cif=cif-2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;cp++; pp*=10;}
                cod1/=10;

            }
        }

    if(cod==cod2&&ci*cp!=0)
       {
           ncorecte++;
       }

}


    s=s+(N-1)*(t+v)+(N-ncorecte)*r+v;
    m=m+s/60;
    s=s%60;
    h=h+m/60;
    m=m%60;
    out<<h<<" "<<m<<" "<<s<<"\n";
}
in.close();
out.close();
return 0;
}

