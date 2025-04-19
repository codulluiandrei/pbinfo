/* autor prof.Minca Carmen
   Liceul Teoretic "Ion Neculce" Bucuresti */
#include<fstream>
using namespace std;
int main()
{
	ofstream g("sir5.out");
	 long x,y,p=1,z;
	 int k,s=0,a,b,i,c,sa;
	 ifstream f("sir5.in");
	 f>>k>>x>>a>>b;
	 s=1;  sa=1; 
	 for(i=2;i<=k;i++)
	 {
	   s=(s+sa+i)%10; 
	   sa=(sa+i)%10; 
	 }
	 g<<s<<endl;
	 //cerinta b)
	 y=x; k=1;
	 while(y>9)   
	   { k++; y/=10; p=p*10; }
	 if(y==k)                     
	   { z=0;                     
		 for(i=1;i<=k+1; i++)
		 z=z*10+i;
	   }
	 else  z=(x%p)*10+y;         
	g<<z<<endl;
	//cerinta c)
	 if(a<b) g<<b-a;
	   else g<<0;
	f.close();
	g.close();
}