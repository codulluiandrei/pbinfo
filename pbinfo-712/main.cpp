// Cristina Iordaiche
// PD + greedy - 100 puncte
#include <stdio.h>
#include <math.h>
#define MX 50010
#define MX_c 2000
#define fin "pirati.in"
#define fout "pirati.out"
using namespace std;
FILE *f;
unsigned char a[MX_c],b[MX],c[MX_c];
int t;
long max,s1,s,r,d,i,j,n,m,q,q1;
void din()
{
 b[0]=1;max=0;
 for (i=1;i<=q;i++) b[i]=0;
 for (i=0;i<n;i++){
  for (j=max;j>=0;j--)
   if ((b[j]) && (j+a[i]<=q)) {
    b[j+a[i]]=1;
    if (j+a[i]>max) max=j+a[i];
   }
 }
 q1=q;
 while (!b[q1]) q1--;
}
void sort()
{
 unsigned char k;
 for (i=0;i<m-1;i++)
  for (j=i+1;j<m;j++)
   if (c[i]<c[j]) {k=c[i];c[i]=c[j];c[j]=k;}
}
int main(void)
{
 f=fopen(fin,"r");s=0;
 fscanf(f,"%ld %ld %ld",&q,&n,&m);
 for (i=0;i<n;i++){
  fscanf(f,"%d",&a[i]);
  s=s+a[i];
 }
 for (i=0;i<m;i++)
  fscanf(f,"%d",&c[i]);
 fclose(f);
  r=0;
  if (s>q){
   din();
   if (q1!=q) r=1;
   else r=0;
  }
  else if (s==q) r=0;
	else{
	   sort();
	   q1=s;r=0;//r=q-q1;
	   for (i=0;i<m;i++){
	    q1=q1+(int)c[i];r=i+1;
	    if (q1>=q) break;
	   }
	  }
 f=fopen(fout,"w");s=0;
 fprintf(f,"%ld
",q-r);
 fclose(f);
  return 0;
}