///Solutia #1 (ineficienta)
#include <iostream>
using namespace std;
int scor(int g,int o){
 if(g==0||o==0){return 1;}
 else return scor(g-1,o)+scor(g,o-1);
}
int main(){
 int g,o;
 cin>>g>>o;
 cout<<scor(g,o);
 return 0;
}