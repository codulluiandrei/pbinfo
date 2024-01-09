#include <iostream>
#include <fstream>


using namespace std;

short v;
int n,m;
struct nod
  { int e1,e2;
    nod* urm;
  };

nod* lm[2501];

int T[31202], H[31202];

void citire()
 {
   ifstream fin("ninjago.in");
   int i,j,p5,c;
   char o;
   nod *p;
   fin >> v;
   fin >> n >> m;
   for (i=156;i<=2500;i++)
        lm[i]=NULL;
   for (int i = 1; i <= m; i++)
    { p=new nod;
      fin >> p->e1 >> p->e2;
      c=0; p5=1;
      for (int j = 0; j < 4; j++)
        {
          fin >> o;
          switch (o)
            {
              case 'A': c+=p5;break;
              case 'B': c+=2*p5;break;
              case 'C': c+=3*p5;break;
              case 'D': c+=4*p5;break;
              case 'E': c+=625;
            }
           p5*=5;
        }
      p->urm=lm[c];
      lm[c]=p;
    }
  fin.close();
 }

int radacina(int x)
  {
      int r,y;
      r=x;
      while (T[r]!=r)
        r=T[r];
      while (T[x]!=x)
        {
          y=T[x];
          T[x]=r;
          x=y;
        }
      return r;
  }

void UnesteArbori(int x, int y)
  {
    if (H[x]>H[y])
       T[y]=x;
    else T[x]=y;
    if (H[x]==H[y])
        H[y]++;
  }

int main()
{   ofstream fout("ninjago.out");

    int i,j,nn, ma,obst,r1;
    long cost;
    nod *p;
    citire();

    for (i=1;i<=n;i++)
      {
        T[i]=i; H[i]=1;
      }

    ma=0, cost=0, obst=0;

    i=156;
    while (ma<n-1 && i<625)
    {   p=lm[i];
        while (ma<n-1 && p)
         {
           if (radacina(p->e1)!=radacina(p->e2))
             {
                ma++;
                cost+=i;
                UnesteArbori(radacina(p->e1),radacina(p->e2));
             }
            p=p->urm;
         }
        i++;
    }
   if (ma==n-1)
       switch (v)
         { case 1:
             fout<<n<<'\n'; break;
           case 2:
              fout<<"0" << endl <<"0"; break;
           case 3: fout << cost;
         }
      else
      {
          if (v==1)
            {
              nn=0;
              r1=radacina(1);
              for (j = 1; j <= n; j++)
                 if (radacina(j)==r1) nn++;
              fout << nn;
            }
           else
             {
                nn=n-1-ma;
                while (ma<n-1)
                  {
                    p=lm[i];
                    while (ma<n-1 && p)
                      { if (radacina(p->e1)!=radacina(p->e2))
                          {
                            ma++;
                            cost+=i%625;
                            obst+=i/625;
                            UnesteArbori(radacina(p->e1),radacina(p->e2));
                          }

                         p=p->urm;
                      }
                    i++;
                  }

                if (v==2) fout <<nn << endl << obst;
                   else fout << cost;
             }
      }
    fout.close();

    return 0;
}
