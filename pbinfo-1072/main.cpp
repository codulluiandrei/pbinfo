#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
char s[1001];
int c[10];
int n;
int main()
{
	int i,ncifre=0,j;
	ifstream f("magic.in");
	ofstream g("magic.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>s[i];
		s[i]=toupper(s[i]);
		if(isdigit(s[i]))
		{
			ncifre++;
			c[s[i]-48]++;
		}
	}
	for(i=1;i<=n;i++)
		if(isalpha(s[i]))
			g<<s[i];
	g<<'\n';
	i=1;
	while(c[i]==0)
	   i++;
	if(c[0])
	   g<<i<<0;
	else
	   g<<i;
	for(j=i+1;j<=9;j++)
	   if(c[j])
	       g<<j;
	f.close();
	g.close();
	return 0;
}