#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
ifstream fin("elicop.in");
ofstream fout("elicop.out");
int a[110][110],m,n,i,j,k,tip[1000], L1[1000],C1[1000],L2[1000],C2[1000],N1,p[1000],np,temp,t;
void interschimba(int &i, int &j){
	int aux;
	aux=i;
	i=j;
	j=aux;
}
//-------------------------
int triunghicu1(int i){
  int L11,L22,C11,C22,t,aux,p,q,no=0;
  L11=L1[i];L22=L2[i];C11=C1[i];C22=C2[i];t=tip[i];
  if(L11>L22){
   aux=L11;L11=L22;L22=aux;
   aux=C11;C11=C22;C22=aux;
   }
  if(C11>C22)
   if(t==1){
    aux=0;
    for(p=L11;p<=L22;p++){
     for(q=C22;q<=C11-aux;q++)
      if(a[p][q]==1) no++;
      aux++;
    }
    }
      else
    {
    aux=0;
    for(p=L22;p>=L11;p--){
     for(q=C22+aux;q<=C11;q++)
      if(a[p][q]==1) no++;
     aux++;
    }
    }
  if(C11<C22)
   if(t==1){
    aux=0;
    for(p=L11;p<=L22;p++){
     for(q=C11+aux;q<=C22;q++)
      if(a[p][q]==1) no++;
      aux++;
    }
    }
      else
    {
    aux=0;
    for(p=L11;p<=L22;p++){
     for(q=C11;q<=C11+aux;q++)
      if(a[p][q]==1) no++;
     aux++;
    }
    }
    return no;
}
//---------------------
void afis(){
int i;
fout<<N1<<"\n"<<np<<" ";
for(i=1;i<=np;i++)
	fout<<p[i]<<" ";
fout.close();
}
int main(){
	fin>>m>>n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			 fin>>a[i][j];
	fin>>k;
	for(i=1;i<=k;i++)
	 fin>>L1[i]>>C1[i]>>L2[i]>>C2[i]>>tip[i];
	fin.close();
	np=0;
	for(i=1;i<=k;i++)
	 {
	   t=triunghicu1(i);
	   //cout<<"Q "<<t<<"\n";
	   temp=abs(L1[i]-L2[i]);
	   temp=(temp+1)*(temp+2)/2;
	   //cout<<"*"<<L1[i]<<" "<<L2[i]<<" "<<temp<<"\n";
	   if(t==temp) N1++;
	   if(t<temp/2.0){
	    np++;
	    p[np]=i;
	    }
	  }
	afis();
return 0;
}