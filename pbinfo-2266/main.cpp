#include <fstream>
using namespace std;
ifstream fin("calcmare.in");
ofstream fout("calcmare.out");
char c;
struct big{
 int n[1002],size=0;
 inline big operator+=(big b){
  int t=0;
  for(int i=1;i<=size;i++){
   n[i]=n[i]+b.n[i]+t;
   t=n[i]/10;n[i]%=10;
  }
  if(t!=0){size++;n[size]=t;}
 }
 inline big operator-=(big b){
  int t=0;
  for(int i=1;i<=size;i++){
   int c=n[i]-b.n[i]+t;
   if(c<0){c+=10;t=-1;}
   else t=0;
   n[i]=c;
  }
  ///!Atentie sa nu ajunga sa scoata toate cifrele
  while(n[size]==0&&size!=1){size--;}
 }
 void invers(){
  for(int i=1,j=size;i<=j;i++,j--){swap(n[i],n[j]);}
 }
};
big a,b;
int main(){
 while(fin.get(c)&&c!='\n'){a.n[++a.size]=c-'0';}
 while(fin.get(c)&&c!='\n'){b.n[++b.size]=c-'0';}
 fin>>c;
 a.invers();
 b.invers();
 if(c=='+'){a+=b;}
 else if(c=='-'){a-=b;}
 a.invers();
 for(int i=1;i<=a.size;i++){fout<<a.n[i];}
 return 0;
}