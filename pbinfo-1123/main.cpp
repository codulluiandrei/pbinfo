//Ana Intuneric
#include <fstream>
using namespace std;
ifstream f("iepurasi.in");
ofstream g("iepurasi.out");

long long toate[200001],ncurent;
int N,a[10001],dim_sir,TAP,nr1,nr2;
bool viz[10001];
char fr7[200001],fr8[200001],fr9[200001];

int main()
{
  int i,j,k,maxi,imax,aux,c7,c8,c9;;
  //citire
  f>>N;
  for(i=1;i<=N;i++)f>>a[i];

  //sortare descrescatoare
  for(i=1;i<=N;i++)
  {
       imax=i;maxi=a[i];
       for(j=i+1;j<=N;j++)
         if(a[j]>maxi)maxi=a[j],imax=j;
       if(imax!=i)
       {
           if(a[N]!=maxi)
           {
               TAP++;
               //TAP pe iepurasul imax
               for(j=imax,k=N;j<k;j++,k--)aux=a[j],a[j]=a[k],a[k]=aux,viz[j]=true,viz[k]=true;
           }
           //TAP pe iepurasul i
           if(a[i]!=maxi)
           {
               TAP++;
               for(j=i,k=N;j<k;j++,k--)aux=a[j],a[j]=a[k],a[k]=aux,viz[j]=true,viz[k]=true;
           }
       }
   }

  //det cartonas minim/maxim
  if(viz[1])k=a[1];
  else
  {
      i=1;while(!viz[i] && i<=N)i++;
      k=a[i-1];
  }

  //constructie sir de numere cu cifrele 7,8,9 pana la numarul de pe pozitia k
  fr7[1]=1;fr8[2]=1;fr9[3]=1;
  toate[1]=7;toate[2]=8;toate[3]=9;
  dim_sir=0;nr1=1;nr2=3;
  while(dim_sir<k)
  {
    c7=fr7[nr1];c8=fr8[nr1];c9=fr9[nr1];
    ncurent=toate[nr1];nr1++;nr2--;
    if(c7<=c8 && c8<=c9) dim_sir++;
    fr7[nr1+nr2]=c7+1;fr8[nr1+nr2]=c8;fr9[nr1+nr2]=c9;toate[nr1+nr2]=10*ncurent+7;nr2++;
    fr7[nr1+nr2]=c7;fr8[nr1+nr2]=c8+1;fr9[nr1+nr2]=c9;toate[nr1+nr2]=10*ncurent+8;nr2++;
    fr7[nr1+nr2]=c7;fr8[nr1+nr2]=c8;fr9[nr1+nr2]=c9+1;toate[nr1+nr2]=10*ncurent+9;nr2++;
  }

  //afisare
  g<<TAP<<endl<<ncurent<<endl;
  f.close();g.close();return 0;
  return 0;
}
