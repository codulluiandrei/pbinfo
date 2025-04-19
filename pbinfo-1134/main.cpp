/*
	Sursa 100 p - Lee + biti
	Complexitate: O(n*m)
	Adriana Simulescu
	Liceul Teoretic GRIGORE MOISIL Timisoara
*/
#include<fstream>
#include<iostream>
#define Nmax 500
using namespace std;
ifstream in("panda.in");
ofstream out("panda.out");
int a[Nmax+2][Nmax+2],b[Nmax+2][Nmax+2];
int n,m,kod,t,l,c,r,d_min=320000,imin,p,s;
struct tarc{unsigned l,c;};
tarc coada[Nmax*Nmax],papa[Nmax*Nmax];
void citire()
{int i,j,x,y;
in>>p;
in>>n>>m>>t>>l>>c>>kod>>s;
for(i=1;i<=t;i++)
   {in>>papa[i].l>>papa[i].c;}
for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
      in>>a[i][j];
in.close();
}
void lee(int l,int c)
{
int st=1,dr=1,ll,cc,pas;
ll=l;
cc=c;
b[ll][cc]=10;
coada[dr].l=l;
coada[dr].c=c;
while(st<=dr)
{
ll=coada[st].l;
cc=coada[st].c;
pas=b[ll][cc];
if(ll-1>0&&(b[ll-1][cc]==0||b[ll-1][cc]>pas+1))
	{b[ll-1][cc]=pas+1;
	 dr++;
	 coada[dr].l=ll-1;
	 coada[dr].c=cc;
	 }
if(ll+1<=n&&(b[ll+1][cc]==0||b[ll+1][cc]>pas+1))
	{b[ll+1][cc]=pas+1;
	 dr++;
	 coada[dr].l=ll+1;
	 coada[dr].c=cc;
	 }
if(cc-1>0&&(b[ll][cc-1]==0||b[ll][cc-1]>pas+1))
	{b[ll][cc-1]=pas+1;
	 dr++;
	 coada[dr].l=ll;
	 coada[dr].c=cc-1;
	 }
if(cc+1<=m&&(b[ll][cc+1]==0||b[ll][cc+1]>pas+1))
	{b[ll][cc+1]=pas+1;
	 dr++;
	 coada[dr].l=ll;
	 coada[dr].c=cc+1;
	 }
st++;
}
}
void construire()
{int i,j,putere2=1;
for(i=1;i<=s;i++)
    putere2*=2;
for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
       {if((((a[i][j]%putere2)^(kod%putere2))&(putere2-1))==putere2-1)
		b[i][j]=0;
       else b[i][j]=-1;
       }
 }
int  main()
{
int i,j,nt=0,nrt=0;
citire();
construire();
if(p==1)
  {  for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
           if(b[i][j]==0)
              nrt++;
cout<<b[l][c];
      out<<nrt-1<<'\n';
  }
else
{
b[l][c]=10;
lee(l,c);
for (i=1;i<=t;i++)
if(b[papa[i].l][papa[i].c]>1&&b[papa[i].l][papa[i].c]<d_min)
    {d_min=b[papa[i].l][papa[i].c];
    }
for(i=1;i<=t;i++)
        if(b[papa[i].l][papa[i].c]==d_min)
           {nt++;
           }
out<<d_min-10<<' '<<nt<<'\n';
}
out.close();
}