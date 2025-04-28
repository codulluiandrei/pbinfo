/*prof. Carmen Minca. Liceul "Ion Neculce" Bucuresti
  Sursa 100p. Reducerea fiecarui cerc la intervalul intersectiei acestuia cu dreapta pe care se afla centru sau.
  Problema se reduce la a determina pt fiecare dreapta numarul maxim de intervale disjuncte doua cate doua
  sursa e bazata pe o rezolvare gen problema spectacolelor (greedy)*/
#include <cstdio>
#include <cmath>
struct cerc
  {int x,y,r,d,e; double a,b;};
cerc c[2001];
int n,nr;
int x[2001];
FILE *f,*g;
int ver_dr(cerc p, cerc q)
{ return (((long)p.x*q.y)==((long)p.y*q.x));}
void citire()
{                                      //citire date+ crearea lui X si Y
  f=fopen("cerc4.in","r");
  fscanf(f,"%d",&n);
  int i; double d;
  for(i=1;i<=n;i++)
{ fscanf(f,"%d%d%d",&c[i].x,&c[i].y,&c[i].r);
  c[i].e=1;  c[i].d=0;
  d=sqrt(pow(c[i].x,2)+pow(c[i].y,2));
  c[i].a=d-c[i].r;
  c[i].b=d+c[i].r;
}
  fclose(f);
}
int poz(int i,int j)
{ int m=-1, ind; cerc s;
  while(i<j)
  { ind=0;
    if((c[i].b>c[j].b)||(c[i].b==c[j].b)&&(c[i].a>c[j].a))
     {ind =1; s=c[i]; c[i]=c[j]; c[j]=s;}
    if(ind)
     {if(m==-1)i++;
	else j--;
      m=-m;
     }
     else
      if(m==-1)j--;
	else i++;
  }
  return i;
}
void dv(int s, int d)   //sortez crescator cercurile dupa capatul din dreapta prin Qsort
{ if(d>s)
   {int k;
    k=poz(s,d);
    dv(s,k-1);dv(k+1,d);}
}
void drepte()
{int i,p,j;
 for(i=1;i<=n;i++)
  if(c[i].d==0)
   {nr++; c[i].d=nr; p=1;
    for(j=i+1;j<=n;j++)
     if((c[j].d==0)&&ver_dr(c[i],c[j]))
	{c[j].d=nr;p++;}
    x[nr]=p;
    }
}
int main()
{ citire();
  dv(1,n);
  int p,max=1,i,j,k,t=1;
  drepte();
  for(p=1;p<=nr;p++)
  {
   for(i=1;i<=n;i++)
   if(c[i].d==p)
   { k=1;
     j=i+1;
     while(j<=n)
      { if((p==c[j].d)&&(c[i].b<c[j].a))
         {k++;i=j;}
       j++;
      }
     if(max<k){max=k;t=1;}
       else if(max==k)t++;
   }
  }
  g=fopen("cerc4.out","w");
  fprintf(g,"%d %d %d",nr,max,t);
  fclose(g);
return 0;
}