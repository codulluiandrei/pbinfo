//prof. Chesca Ciprian - 100 p
#include <fstream>
#define nmax 100001
using namespace std;
struct lichid
{
	long cant; 	// cantitatea de substanta;
	char ram; 	// ramura pe unde se toarna
	long cul;     //culoarea substantei
};
lichid st[nmax],dr[nmax];
long long vst=0,vdr=0;
ifstream f("vase1.in");
ofstream g("vase1.out");
int main()
{
long long i,n,x,z,mij,l1=0,l2=0,h1,h2,gasit,s=0;
char c,l1r=' ',l2r=' ';
f>>n;
// citesc datele sub forma a 2 stive st si dr si calculez suma totala
for(i=1;i<=n;i++)
{
	f>>x>>c;
	s+=x;
	switch (c)
	{
	case 'S': 
			st[++vst].cant=x;
			st[vst].ram=c;
			st[vst].cul=i;
			break;
	case 'D': 
			dr[++vdr].cant=x;
			dr[vdr].ram=c;
			dr[vdr].cul=i;
			break;
	}		
}	
// culoarea pe care o caut
f>>z;
//calculez punctul de echilibru
mij=s/2;
h1=mij;gasit=0;
while(h1>-mij&&vst>0&&!gasit)
{
	if (st[vst].cul==z) 
			{
			if (h1<0) {l1=-h1;l1r='D';}
				else  {l1=h1;l1r='S';}
			if (h1-st[vst].cant<0) {l2=-(h1-st[vst].cant);l2r='D';} 
			    else  {l2=h1-st[vst].cant;l2r='S';}  
			gasit=1;
			}	
	h1-=st[vst--].cant;	
}
h2=mij;
while(h2>-mij&&vdr>0&&!gasit)
{
	if (dr[vdr].cul==z) 
			{
			if (h2<0) {l1=-h2;l1r='S';}
				else  {l1=h2;l1r='D';}
			if (h2-dr[vdr].cant<0) {l2=-(h2-dr[vdr].cant);l2r='S';}
						else	   {l2=h2-dr[vdr].cant;l2r='D';}
			gasit=1;
			}
	h2-=dr[vdr--].cant;
}	
if (l1==0) l1r=l2r;
if (l2==0) l2r=l1r;
// scriu rezultatele in fisier
g<<mij<<"\n";
if (l1r=='D'&&l2r=='S')
		{
		g<<l2<<" "<<l2r<<"\n";
		g<<l1<<" "<<l1r<<"\n";
		}
	else
		if (l1r=='S'&&l2r=='D')
				{
				g<<l1<<" "<<l1r<<"\n";
				g<<l2<<" "<<l2r<<"\n";
				}
			else
				if (l1>l2)
						{
						g<<l1<<" "<<l1r<<"\n";
						g<<l2<<" "<<l2r<<"\n";
						}
					else
						{
						g<<l2<<" "<<l2r<<"\n";
						g<<l1<<" "<<l1r<<"\n";
						}
f.close();
g.close();
return 0;
}