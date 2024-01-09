#include <fstream>
#include<stdio.h>
#include <iomanip>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int conditie(char a[], char b[])
{
  if(strcmp(a,b)>=0)
     return 0;
  return 1;
}
main()
{
char rez[100][255], p[255],l,c, aux[255];
ifstream fin("fraze.in");
ofstream fout("fraze.out");
int poz=0,k=0, fp=0, fpp=0, okp, okpp, i, nr, sort;
while(fin.get(c))
{
if(c!='.')p[poz++]=c;
else
{
p[poz++]='.';p[poz]=0;fin.get();
okp=1;okpp=1;
for(l='a';l<='z'&&okp==1;l++)
{nr=0;
for(i=0;i<poz;i++)
if(p[i]==l || p[i]==(char)(l-32) )nr++;
if (nr==0){okp=0;okpp=0;}
if(nr>1)okpp=0;
}
if(okp){fp++;strcpy(rez[k++],p);}
if(okpp)fpp++;
poz=0;
}
}
fout<<fp<<' '<<fpp<<'\n';
do
{
sort=1;
for(i=0;i<k-1;i++)
	if(strcmp(rez[i],rez[i+1])>0)
	{strcpy(aux,rez[i]);strcpy(rez[i], rez[i+1]);strcpy(rez[i+1],aux);
	sort=0;
	}
}while(!sort);
for(i=0;i<k;i++)
	fout<<rez[i]<<'\n';

fout.close();
return 0;
}
