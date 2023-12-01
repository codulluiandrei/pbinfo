#include <fstream>
using namespace std;
int a,v,i,n,p,b,a1,b1,x,y,nr,j,k,l,r,nr1,aux;
int main()
{
	int max=0;
	ifstream f("pprim.in");
	ofstream g("pprim.out");
	f>>n>>p;
	max=0;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		if(a>b)
		{
			aux=a;
			a=b;
			b=aux;
		}
		nr1=0;
		for(j=a;j<=b;j++)
		{
			nr=0;
			for(k=1;k<=j/2;k++)
				if (j%k==0)
				//for (l=k+1;l<=j;l++)
				{
				 x=k;y=j/k;//g<<x<<" "<<y;
					if(x<y)
					{
						while(y)
						{
							r=x%y;
							x=y;
							y=r;
						}
						if (x==1)
						{
							nr++;
						}
					}
				  }
		  if(nr==p)
		  {
			  nr1++;//g<<j<<" ";
		  }
		}
		if(nr1>=max)
		{
			max=nr1;
			a1=a;
			b1=b;
		}
	  //g<<endl;
	}
	if(max==0)
		g<<"nu exista";
	else
		g<<a1<<" "<<b1;
    return 0;
}
