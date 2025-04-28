#include<fstream>
#define LgNr 500
using namespace std;
typedef int BIG[LgNr];
int n,d,m,i,j,k,r,q,aux;
BIG Lc[501],Lp[501];
void sum(BIG a, BIG b, BIG & s)
{  
    int i,cifra,t = 0,max;
    if(a[0] < b[0]) 
	{ 
		max=b[0]; 
	  	for(i=a[0]+1;i<=b[0];i++)
			 a[i] = 0;
	 }
    else
        {
	  max=a[0];
	  for(i=b[0]+1;i<=a[0];i++)
	 	 b[i]=0;
	}
    for(i=1;i<=max;i++)
    {
      cifra=a[i]+b[i]+t; 
      s[i]=cifra%10;     
      t=cifra/10;            
    }
    if(t)s[i]=t;
    else i--;
    s[0]=i;    
}
int main()
{
	ifstream fin("expozitie.in");
	ofstream fout("expozitie.out");
	fin>>n>>d>>k;
	r=n-k*d;
	if(r<0)fout<<0;
	else
	if(r==0)fout<<1;
	else
	{ 
	m=r+d-1;
	for(i=1;i<=r;i++)
			Lp[i][0]=Lp[i][1]=1;
	for(i=2;i<=d;i++)
	{	
		aux=i;Lc[1][0]=0;
		while(aux)
		    {
			Lc[1][0]++;
			Lc[1][Lc[1][0]]=aux%10;
			aux=aux/10;
		    }
		for(j=2;j<=r;j++)
			sum(Lp[j],Lc[j-1],Lc[j]);
		for(j=0;j<=r;j++)
			for(q=0;q<=Lc[j][0];q++)
				Lp[j][q]=Lc[j][q];
	}
	for(j=Lc[r][0];j>=1;j--)
		fout<<Lc[r][j];
	}	
	fout.close();
	return 0;
}