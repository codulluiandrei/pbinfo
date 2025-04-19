//Jakab Tunde
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
{ifstream in("robot3.in");
 ofstream out("robot3.out");
 char c;
 int a=0,b=0,n=0,m=0,z=0,e,d,p;
 in>>p;
 if(p==1){
   while(!in.eof()){
     in>>c;
     if (c=='A')a++;
   }
   out<<a<<endl;
 }
 if(p==2){
   in>>c;
   b=0;
   while(c!='T'){
      if (c=='D'){
        in>>c;
        a=c-48;
        b=(b+a)%10;
      }else if (c=='S'){
              in>>c;
              a=c-48;
              b=(b+10-a)%10;
            }
      if(c=='A')out<<b;
      in>>c;
   }
 }
 if(p==3){
 in>>a;
 if(a==0)out<<"A";
 else
   if(a<10){if(10-a<a)out<<'S'<<10-a<<'A';
            else out<<'D'<<a<<'A';
            }
   else
    {
    z=0;
    while(a%10==0){
      z++;
      a=a/10;
    }
    while(a!=0){
      b=b*10+a%10;
      a=a/10;
    }
    a=b;
    b=a%10;
    if(10-b<b)out<<'S'<<10-b<<'A';
    else out<<'D'<<b<<'A';
    a=a/10;
    while(a!=0){
      if(b==a%10)out<<'A';
      else
        if(b>a%10)
          if(10-b+a%10<=b-a%10)out<<'D'<<10-b+a%10<<'A';
          else out<<'S'<<b-a%10<<'A';
        else if(10-a%10+b<a%10-b)out<<'S'<<10-a%10+b<<'A';
             else out<<'D'<<a%10-b<<'A';
      b=a%10;
      a=a/10;
    }
    if(z!=0){
      if(10-b<b)out<<'D'<<b;
      else out<<'S'<<b;
      while(z!=0){
        out<<'A';
        z--;
      }
    }
   }
  out<<'T';
 }
 in.close();
 out.close();
return 0;
}