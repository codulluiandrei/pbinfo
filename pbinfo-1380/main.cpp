#include<fstream>
using namespace std;
long Nr[4001];//Nr[k]=nr de identificare al soldatului k
long NrSort[4001];//NrSort[k]=nr de identificare al soldatului k
	  //avand cifrele asezate in ordine descrescatoare - cu ajutorul
	  //acestui vector se va verifica rapid daca doi soldati i si j fac
	  //parte din acelasi pluton (adica au numerele de identificare
	  //Nr[i] si Nr[j] formate din acelasi cifre, insa in alta ordine)
	  //deoarece este suficient sa testam daca NrSort[i]=NrSort[j]
long n;    //numarul de soldati
long nrp;  //numarul de plutoane refacute
long Max;  //numarul maxim de soldati dintr-un pluton refacut
long nrmax;//numarul de plutoane refacute cu numar maxim de soldati (Max)
long SortareCifre(long x) //functia intoarce numarul obtinut prin asezarea
{                         //in ordine descrescatoare a cifrelor numarului x
 long aux,c,y;           //de exemplu SortareCifre(2810831)=8832110
 aux=x;             //in aux se salveaza valoarea initiala a numarului x
 y=0;
 for(c=9;c>=0;c--)  //se considera pe rand fiecare cifra c de la 9 la 0
 {
  while(x)                  //se ia pe rand fiecare cifra din numarul x
  {                         //si daca ea este egala cu c se alipeste la
   if(x%10==c) y=y*10+x%10; //un alt numar y - astfel numarul y va avea
   x=x/10;                  //la sfarsit aceleasi cifre ca si numarul x,
  } 			    //insa asezate in ordine descrescatoare
  x=aux;                    //se reface valoarea initiala a lui x
 }
 return y;
}
int main()
{
 long i,j,p,pmax;
 long aux;
 fstream f;
 f.open("pluton.in",ios::in);
 f>>n;               //se citesc din fisierul pluton.in numarul n si
 for(i=1;i<=n;i++)   //elementele vectorului Nr si se completeaza valorile
 {                   //corespunzatoare in vectorul NrSort
  f>>Nr[i];
  NrSort[i]=SortareCifre(Nr[i]);
 }
 f.close();
 i=1;             //pozitia curenta din vectori Nr si NrSort(soldatul curent i)
 nrp=nrmax=Max=0;
 while(i<=n)
 {
  p=i;            //se salveaza pozitia curenta i in variabila p
  j=i+1;          //se cauta soldati j din acelasi pluton cu soldatul curent i
  while(j<=n)     //adica soldati pentru care NrSort[j]=NrSort[i]
  {
   if(NrSort[i]==NrSort[j]) //in cazul in care se gaseste un astfel de soldat
   {                        //acesta este adus langa soldatul curent i
    i++;
    aux=Nr[i]; Nr[i]=Nr[j]; Nr[j]=aux;
    aux=NrSort[i]; NrSort[i]=NrSort[j]; NrSort[j]=aux;
   }
   j++;
  }
  i++;        //s-au adus langa soldatul i toti posibilii sai colegi de pluton
  nrp++;      //deci s-a mai refacut un pluton intre pozitiile p si i-1 din
	      //cei doi vectori Nr si NrSort
  if(i-p>Max) //daca numarul de soldati din ultimul pluton refacut (adica i-p)
  {           //este mai mare strict decat Max se actualizeaza valorile
   Max=i-p;   //variabilelor Max si nrmax
   nrmax=1;
   pmax=p;    //pmax retine pozitia la care incepe in vectorul Nr plutonul
  }           //cu numar maxim de soldati
  else
   if(i-p==Max) nrmax++; //daca numarul de soldati din ultimul pluton refacut
 }                       //este egal cu Max se actualizeaza valoarea lui nrmax
 f.open("pluton.out",ios::out); //se scriu in fisierul pluton.out rezultatele
 f<<nrp<<endl<<Max<<endl<<nrmax<<endl;
 for(i=pmax;i<pmax+Max;i++) f<<Nr[i]<<" ";
 f.close();
}