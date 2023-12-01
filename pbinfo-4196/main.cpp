#include <iostream>
#include <cstdio>
#define XMAX 4000000
#define PMAX 500000
#define FMAX 50

using namespace std;
//FILE * fin=fopen("mpf.in","r");
//FILE * fout=fopen("mpf.out","w");

//ifstream fin("308.in");
//ofstream fout("mpf.out");
bool ciur[XMAX];
int prime[PMAX];
int nrp, nrx, nry, nrmin;
int fx[FMAX];
int mx[FMAX];
int fy[FMAX];
int my[FMAX];

void eratostene();
void desc(int x, int&nrx, int fx[], int mx[]);
int rezolva();

int main()
{int i, q, x, y;
ios_base :: sync_with_stdio(false);  
   cin.tie(nullptr);  
 //cin>>q;
 scanf("%d", &q);
 eratostene();
 for (i=0; i<q; i++)
     {
      //cin>>x>>y;
      scanf("%d %d", &x, &y);
      desc(x,nrx,fx,mx);
      desc(y,nry,fy,my);
      nrmin=rezolva();
      //cout<<nrmin<<'\n';
      printf("%d\n",nrmin);
     }
  //fout.close();
//  fclose(fout);
  return 0;
}

void eratostene()
{int i, j;
 ciur[0]=ciur[1]=1;
 for (i=2; i*i<XMAX; i++)
     if (ciur[i]==0)
         for (j=i*i; j<XMAX; j+=i) ciur[j]=1;
 prime[1]=2; nrp=1;
 for (i=3; i<XMAX; i+=2)
      if (ciur[i]==0) prime[++nrp]=i;
 }

 void desc(int x, int& nrx, int fx[], int mx[])
 {int i, m;
  if (ciur[x]==0) {nrx=1; fx[nrx]=x; mx[nrx]=1; return;}
  nrx=0;
  for (i=1; prime[i]*prime[i]<=x; i++)
      {
        m=0;
        while (x%prime[i]==0) {x/=prime[i]; m++;}
        if (m) {++nrx; fx[nrx]=prime[i]; mx[nrx]=m;}
      }
 if (x>1) {++nrx; fx[nrx]=x; mx[nrx]=1;}
 }

 int rezolva()
 {int rez=0;
  int i, j, unde;
  if (nrx==0) {for (i=1; i<=nry; i++) rez+=my[i]; return rez;}
  if (nry==0) {for (i=1; i<=nrx; i++) rez+=mx[i]; return rez;}
  unde=nrx; if (nry<unde) unde=nry;
  for (i=1; i<=unde; i++)
       if (fx[i]!=fy[i] || fx[i]==fy[i] && mx[i]!=my[i]) break;
  if (i<=nrx && i<=nry && fx[i]==fy[i]) if (mx[i]<my[i]) rez+=my[i]-mx[i];
                         else rez+=mx[i]-my[i];
      else i--;
   for (j=i+1; j<=nrx; j++) rez+=mx[j];
   for (j=i+1; j<=nry; j++) rez+=my[j];
   return rez;
 }
