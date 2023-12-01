#include<iostream>
#include<cstdio>
FILE *f=fopen("flori2.in","r");
FILE *g=fopen("flori2.out","w");

int n,k,a[150][150];

int irelj(int i,int j) //verifica daca fata i e in relatie cu j(au cel putin o floare in comun)
{int u,v;
 for(u=1;u<=a[i][0];u++)   //a[i][0] e numarul de elemente pe linia i
	for(v=1;v<=a[j][0];v++)
	  if (a[i][u]==a[j][v])
		 return 1;
 return 0;
}
int apartine(int val,int linie) //caut val in multimea de pe linia linie
{int j,lg=a[linie][0];
 for(j=1;j<=lg;j++)
	if (val==a[linie][j])
		return 1;
 return 0;
}

void reuneste(int i,int j) //reuneste in linia i linia j
{int u;
 for(u=1;u<=a[j][0];u++)
	if(!apartine(a[j][u],i))
	  {a[i][0]++;
		a[i][ a[i][0] ]=a[j][u];
	  }
}

int main()
{int viz[150],i,j,val,ok;
 fscanf(f,"%d %d",&n,&k);
 for(i=1;i<=n;i++)
  for(j=1;j<=k;j++)
	{fscanf(f,"%d",&val);
	 if(!apartine(val,i))
		{a[i][0]++;  //pe prima coloana am nr. de tipuri distincte de flori
		 a[i][ a[i][0] ]=val;  //in multimea de pe linia i am tipurile distincte de flori al fetitei i
		}
	}
 for(i=1;i<=n;i++)
  viz[i]=i;     //initial exista n grupe
 for(i=1;i<=n;i++)
  {ok=0;
	if(a[i][0])
	{
	 for(j=i+1;j<=n;j++)
		if(irelj(i,j))
			{
				viz[j]=viz[i];  //j trebuie sa ajunga in grupa cu i
				reuneste(i,j);  //reunesc in linia i linia j
				a[j][0]=0;//consider ca in multimea j am 0 elemente acuma
				ok=1;
				}
			}
	 if (ok) i--;//faptul ca am reunit in i cel putin o multime j implica sa continui cu aceeasi linie i
                     //daca as lasa i sa se incrementeze conform for-ului,ar gresi in sensul ca
                     //pt. i rel j si i nu e in rel cu k si j rel k
                     //ar pune j in grupa i dar k ar ajunge in alta grupa
  }


 for(i=1;i<=n;i++)
	if(viz[i])
	 {fprintf(g,"%d ",i);
	  for(j=i+1;j<=n;j++)
	if(viz[i]==viz[j])
		{fprintf(g,"%d ",j);
		 viz[j]=0;       //ca sa nu mai fie prelucrat
		}
	  fprintf(g,"\n");
	 }
 fclose(g);
return 0;
}

