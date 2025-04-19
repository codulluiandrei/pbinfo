#include <fstream>
#include<cstring>
using namespace std;
ofstream h("cod.out");
void decodific(char s[])
{ int i=0,n=strlen(s),k=0;
  char c, b[100],x;
  while(i<n)
  { x=(s[i]-'0')+(s[i+1]-'0')*10;
    if ((int)x<23){x=x+(s[i+2]-'0')*100;i++;}
    i+=2;
    if ((x!=32)&&(x!=46))
        {b[++k]=char(x);
        }
    if((x==32)||(x==46)||(i>n-1))
      {for(int j=k;j>0;j--) h<<b[j];
       k=0;
       if((x==32)||(x==46))h<<x;
       }
    }
}
int main()
{ char s[300];
  ifstream g("cod.in");
  g.getline(s,300);
  decodific(s);
  while(!g.eof())
    {h<<endl;
     g.getline(s,300);
     decodific(s);
     }
 g.close();h.close();
 return 0;
}