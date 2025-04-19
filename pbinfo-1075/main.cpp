#include <fstream>
using namespace std;
int x[10002],y[10002],g,n,k,pmax,gmax,aux;
ifstream fin("grad1.in");
ofstream fout("grad1.out");
void cit(){
 int i;
 fin>>n>>k;
 for(i=1;i<=n;i++)
  fin>>x[i];
 fin.close();
}
void ordonare(int n){
 int i,sw,aux;
 do{
  sw=0;
  for(i=1;i<n;i++)
   if(y[i]>y[i+1])
   {
    aux=y[i];y[i]=y[i+1];y[i+1]=aux;sw=1;
   }
   //n--;
 }while(sw);
}
int main(){
int i,j,gr;
cit();
for(i=1;i<=n;i++)
 y[i]=x[i];
ordonare(n);
g=0;
for(i=1;i<=n;i++)
 if(x[i]==y[i])
  g++;
fout<<g<<'\n';
for(i=1;i<=k;i++)
 y[i]=x[i];
ordonare(k);
gmax=0;
for(i=1;i<=k;i++)
 if(x[i]==y[i])
  gmax++;
pmax=1;
for(i=2;i<=n-k+1;i++)
 {
  for(j=1;j<=k;j++)
   if(y[j]==x[i-1])
    break;
  y[j]=x[i+k-1];//ducem y[j] pe pozitia corespunzatoare a. i. y sa ramana ord. cresc.
  while(j>1&&y[j-1]>y[j]){
   aux=y[j];y[j]=y[j-1];y[j-1]=aux; j--;
  }
  while(j<k&&y[j]>y[j+1]){
   aux=y[j];y[j]=y[j+1];y[j+1]=aux;j++;
  }
  //determin gradul secventei care incepe cu x[i]
  gr=0;
  for(j=1;j<=k;j++)
   if(y[j]==x[i+j-1])
    gr++;
  if (gr>gmax){
   gmax=gr;pmax=i;
  }
 } 
fout<<pmax<<" "<<gmax;
fout.close();
return 0;
}