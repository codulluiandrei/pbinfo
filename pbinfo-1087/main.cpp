#include<fstream>
#include<cstring>
using namespace std;
char x[25][255],y[25][255];
int poz[25];
void transforma(char s[255])
{
	unsigned int i;
	for(i=0;i<strlen(s);i++)
	{ 
		char t[255];
		strcpy(t, s + 1);
		strncat(t,s,1);
		strcpy(s , t);
		strcpy(y[i],s);
	}
}	
int verifica(unsigned int j, unsigned int n)
{
	unsigned int i;
	for(i=0;i<n;i++)
		if (strcmp(x[j],y[i])==0) 
			return 1;
	return 0;
}
int  main()
{
	char s[255] , *p;
	unsigned int n,i=0,t,j,prima=0;
	ifstream f("cuvinte4.in");
	ofstream g("cuvinte4.out");
	f.get(s,255);
	p=strtok(s," !");
	while(p)
	{   
		strcpy(x[i++],p);
		poz[i-1]=i; 
		p=strtok(NULL," !");
	}
	n=i;
	i=0;
	j=1;
	while(i<n-1)
	{
		transforma(x[i]);
		if (verifica(j,strlen(x[i])-1)) 
		{
			for(t=j;t<n-1;t++)
			{
				strcpy(x[t],x[t+1]);
				poz[t]=poz[t+1];
			}
			if (prima==0) 
				prima=j+1;
			n--;
		}
		else 
		{
			i++;j=i+1;
		}
	}
	g<<prima<<"\n";
	for(j=0;j<n;j++)
		g<<poz[j]<<" ";	
	f.close();
	g.close();
	return 0;
}