#include <cstdio>
#define NRMAX 2000004
FILE *fin=fopen("teatru.in","r");
FILE *fout=fopen("teatru.out","w");
long long int N, P, L, nr;
struct segm {long long int st, dr, poz;
             segm * urm;
};
typedef segm * Lista;
long long int lg[3];
Lista f;
char sir[NRMAX];
int main()
{int ia, ib, ic, aux;
 long long int i, pas;
 Lista p, q;
 segm s;
 fscanf(fin,"%lld %lld %lld", &N, &P, &L);
 //fin>>N>>P>>L;
 //determin lungimile ultimelor 3 acte
 ia=2; ib=0; ic=1;
 lg[0]=lg[1]=1;
 for (i=3; i<=N; i++)
     {aux=ia; ia=ib; ib=ic; ic=aux; lg[ic]=lg[ia]+lg[ib];}
 //ic indica lungimea actului N, ib a actului N-1, iar ia a actului N-2
 f=new segm;
 f->st=P; f->dr=P+L-1; f->poz=N; f->urm=NULL;
 pas=N;
 while (pas>2)
       {//din ic generez segmente pentru ib / ia
        for (p=f; p; p=p->urm)
            if (p->poz==pas)
                {
                  //lg[ic]=lungimea pentru pas
                  if (p->dr<=lg[ia]) {p->poz-=2;}
                     else
                     if (p->st>lg[ia])
                        {p->poz--; p->st-=lg[ia]; p->dr-=lg[ia];}
                        else
                        {q=new segm;
                         q->st=1; q->dr=p->dr-lg[ia]; q->poz=p->poz-1;
                         p->dr=lg[ia]; p->poz-=2;
                         q->urm=p->urm;
                         p->urm=q;
                        }
                }
         /* for (it=f.begin(); it != f.end(); ++it)
               fout<<it->st<<' '<<it->dr<<' '<<it->poz<<'\n';
          fout<<'\n';*/
         //ma pregatesc pentru pasul urmator
         aux=ic; ic=ib; ib=ia; ia=aux;
         lg[ia]=lg[ic]-lg[ib];
         pas--;
       }
 nr=0;
 for (p=f; p; p=p->urm)
     if (p->poz==1)
         for (i=p->st; i<=p->dr; i++)
             sir[nr++]='A';
             else
             for (i=p->st; i<=p->dr; i++)
                 sir[nr++]='D';
sir[nr]=0;
fprintf(fout,"%s",sir);
fclose(fout);
return 0;
}