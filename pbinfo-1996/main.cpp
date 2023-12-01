#include<fstream>
#include<string>
using namespace std;
FILE *fin;

ofstream fout("zigzag.out");
char s[100010], a[50010],chr;
int n,c,x,p,k,nr,m,i;
int main()
{
	fin=fopen("zigzag.in","r");
	fscanf(fin,"%d%d",&c,&n);
	fscanf(fin,"%c",&chr);
	for(i=1;i<=n;i++)
		{fscanf(fin,"%c",&chr);a[i]=chr;}
	nr=(n%(2*c-2)==0?n/(2*c-2):n/(2*c-2)+1);
	m=nr*(2*c-2);
	for(i=n+1;i<=m;i++)
		      s[i]='X';
	k=1;
	//rand 1
	for(x=0;x<=nr-1;x++)
	{
		
		if(s[x*(2*c-2)+1]!='X')
				{s[x*(2*c-2)+1]=a[k++];}
	}
	//randuri de la 2 la c-1
	for(p=2;p<=c-1;p++)
	{
		for(x=0;x<=nr-1;x++)
		{
			if(s[x*(2*c-2)+p]!='X')
				s[x*(2*c-2)+p]=a[k++];
			if(s[x*(2*c-2)+2*c-p]!='X')
				s[x*(2*c-2)+2*c-p]=a[k++];
		}
	}
	//rand c
	for(x=0;x<=nr-1;x++)
	{
		
		if(s[x*(2*c-2)+c]!='X')
				s[x*(2*c-2)+c]=a[k++];
	}
	for(i=1;i<=n;i++)
		fout<<s[i];
	fout<<'\n';
	fout.close();
	return 0;
}
