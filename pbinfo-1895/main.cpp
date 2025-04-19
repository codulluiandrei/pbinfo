//Dobricean Ionuţ 100 pct
#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 1005
using namespace std;
ifstream fin("festivaluri.in");
ofstream fout("festivaluri.out");
int n,m,p,z,cnt,nr,enercons,r;
int fes[MAX]; //vectorul în care vom stoca indicii intersectilor unde se vor afla festivalurile
int a[MAX][MAX] ;//declararea matricii costurilor
int festsort[MAX]; //costul intersectilor unde se organizeaza festivalurile in ordine crescatoare 
void citire()
{ int i;
int x,y,co; //declararea  intersecţiei de unde începe strada, intersecţia unde se  termina strada şi costul acesteia 
fin>>n>>m>>p>>z>>r;
for(i=1; i<=m; i++)
	{ fin>>x>>y>>co;
		a[x][y]=co;
	}
for(i=1; i<=r; i++)
	{	fin>>fes[i];
	}
}
void roy() //Algoritmul lui Roy Floyd 
{ int i,j,k;
    for(k = 1;k <= n;k++)
		for(i = 1;i <= n;i++)
			for(j = 1;j <= n;j++)
				if(a[i][k] && a[k][j] &&(a[i][k] + a[k][j] < a[i][j] || !a[i][j]) && i != j)
					a[i][j] = a[i][k] + a[k][j];
}
void sortare()
{ int i,j;
	for(i=1; i<=r; i++)	
		festsort[i]=a[z][fes[i]];
sort(festsort+1, festsort+1+r);
}
void determinare_cnt() // determinarea numarului de festivaluri
{ int i;
enercons=0;
for(i=1; i<=r; i++)
	if(enercons+festsort[i]<=p && festsort[i]>0)
		{ cnt++;
		enercons+=festsort[i];	
		}
fout<<cnt;
}
int main()
{  citire();
	roy();
	sortare();
	determinare_cnt();
}