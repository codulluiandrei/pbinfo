//prof. Liliana Schiopu, CNFB-Craiova
#include<stdio.h>
using namespace std;
FILE *f=fopen("easyocr.in","r");
FILE *g=fopen("easyocr.out","w");
int n,m,i,j,aparitii[10],nrcif=0,nr,x,y,ok;
char a[1000][1000],c2,c5,c6;
struct el
{
    int x,y;
};
int coada(int x,int y,char a1,char b)
{ register el coada1[30];
  register int ic=0,sf=0,i,x1[9]={-1,-1,0,1,1,1,0,-1},y1[9]={0,1,1,1,0,-1,-1,-1};
  nr++;
  ic=1;
  sf=1;
  coada1[sf].x=x;
  coada1[sf].y=y;
  a[x][y]=b;
  while(ic<=sf)
  {
      for(i=0;i<8;i++)
      if(a[coada1[ic].x+x1[i]][coada1[ic].y+y1[i]]==a1)
      {
          nr++;
          sf++;
          coada1[sf].x=coada1[ic].x+x1[i];
          coada1[sf].y=coada1[ic].y+y1[i];
          a[coada1[ic].x+x1[i]][coada1[ic].y+y1[i]]=b;
      }
      ic++;
  }
  return nr;
}
int main()
{ fscanf(f,"%d%d\n",&n,&m);
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=m;j++)
      a[i][j]=fgetc(f);
     fgetc(f);
  }
    fclose(f);
   do{
    ok=0;
    for(i=1;i<=n && ok==0;i++)
        for(j=1;j<=m && ok==0;j++)
            if(a[i][j]=='1')
            {ok=1;
             x=i;y=j;
            }
    c5=a[x+1][y];
    c2=a[x+4][y];
    c6=a[x+4][y];
    nr=0;
    coada(x,y,'1','0');
    switch(nr){
      case 20: aparitii[0]++;nrcif++;break;
      case 8: aparitii[1]++;nrcif++;break;
      case 14: aparitii[4]++;nrcif++;break;
      case 11: aparitii[7]++;nrcif++;break;
      case 23: aparitii[8]++;nrcif++;break;
      case 19: if(c5=='1'){aparitii[5]++;nrcif++;}
               else if(c2=='1'){aparitii[2]++;nrcif++;}
                  else {aparitii[3]++;nrcif++;}
               break;
      case 21: if(c6=='1'){aparitii[6]++;nrcif++;}
                  else {aparitii[9]++;nrcif++;}
              break;
    }
   }while(ok==1);
   fprintf(g,"%d\n",nrcif);
   for(i=0;i<=9;i++)
      if(aparitii[i]!=0) fprintf(g,"%d %d ",i,aparitii[i]);
    fclose(g);
   return 0;
}