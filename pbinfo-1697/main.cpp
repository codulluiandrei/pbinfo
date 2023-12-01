#include <stdio.h>
#include<stdlib.h>
FILE *in,*out;
long cate=0;
long N,M,i,j;char c; int P,n,nr;
long v[300],gr_i[20],gr_g[20],g[20];

int selectie(long v[300],long m,long g[16])
{ int i;long s=0;
for(i=0;i<=19;i++) g[i]=0;
//grupa 2,3,4,5,6,7,8,9,10,11,12,13,14,15
v[0]=0;
//2
if(v[m]%2==0) g[2]++;

//3
s=0;
for(i=1;i<=m;i++) s+=v[i];
if(s%3==0)g[3]++;

//4
if((v[m-1]*10+v[m])%4==0)g[4]++;

//5
if(v[m]%5==0)g[5]++;

//6
if(g[2]&&g[3]) g[6]++;

//7
int s1=0,s2=0,s3=0;
for(i=m;i>5;i=i-6)
{
    s1=v[i-2]*100+v[i-1]*10+v[i];
    s2=v[i-5]*100+v[i-4]*10+v[i-3];
    s3+=s1-s2;
}
if(i==5)
{
    s1=v[i-2]*100+v[i-1]*10+v[i];
    s2=v[i-4]*10+v[i-3];
    s3+=s1-s2;
}
if(i==4)
{
    s1=v[i-2]*100+v[i-1]*10+v[i];
    s2=v[i-3];
    s3+=s1-s2;
}
if(i==3) s3+=v[i-2]*100+v[i-1]*10+v[i];
if(i==2) s3+=v[i-1]*10+v[i];
if(i==1) s3+=v[i];
if(s3<0) s3=-s3;
if(s3%7==0)g[7]++;

//8
if(m>=3&&(v[m-2]*100+v[m-1]*10+v[m])%8==0)g[8]++;
if(m==2&&(v[m-1]*10+v[m])%8==0)g[8]++;
if(m==1&&(v[m])%8==0)g[8]++;

//9
if(s%9==0)g[9]++;

//10
if(v[m]==0)g[10]++;

//11
s1=0, s2=0;
for(i=1;i<=m;i++)
    if(i%2) s1+=v[i]; else s2+=v[i];
if(s1>s2) s=s1-s2;else s=s2-s1;
if(s%11==0)g[11]++;

//12
if(g[4]&&g[3])g[12]++;

//13
if(s3%13==0)g[13]++;

//14
if(g[2]&&g[7])g[14]++;

//15
if(g[3]&&g[5])g[15]++;
return 0;
}

int main()
{
    long nrc=0;
    freopen("cod1.in","r",stdin);
    freopen("cod1.out","w",stdout);
    scanf("%d\n%ld\n", &P, &N);
    for(i=0;i<=15;i++){gr_i[i]=0;gr_g[i]=0;}

    for(i=1;i<=N;i++)
    {   n=0;
        scanf("%c",&c);
        while(c!='#'&&c!='\n')
        {
            n++;
            v[n]=c-'0';
            if(v[n])nrc++;
            scanf("%c",&c);
        };
        selectie(v,n,g);
        long numar=0;
        for(j=2;j<=15;j++) numar+=g[j];
        if(numar==0) cate++;
        for(j=2;j<=9;j++) gr_i[j]+=g[j];
        for(j=10;j<=15;j++) gr_g[j]+=g[j];
    }

  long cod_i=0,cod_g=0;
  for(i=2;i<=9;i++)
   if(gr_i[i]!=0)cod_i+=gr_i[i];
  for(i=10;i<=15;i++)
   if(gr_g[i]!=0)cod_g+=gr_g[i];

  if(P==1)printf("%ld\n",cate);
  if(P==2)printf("%ld\n",cod_i);
  if(P==3)printf("%ld\n",cod_g);
    return 0;
}
