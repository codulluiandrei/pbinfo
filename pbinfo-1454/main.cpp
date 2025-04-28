#include <stdio.h>
#include <cstring>
using namespace std;
FILE *ci,*co;
int main()
{
    ci=fopen("permutarecuvant.in","r");
    co=fopen("permutarecuvant.out","w");
    char name[40],bubble,temp[40];
    int loop,size,count;
    fscanf(ci,"%s",name);
    for(loop=0;loop<strlen(name);loop++){
        temp[loop]=name[loop];
        fprintf(co,"%c",temp[loop]);
    }
    for(count=1;count<strlen(name);count++){
        for(loop=0;loop<strlen(name);loop++){
         if(loop==0){bubble=temp[0];}
         temp[loop]=temp[loop+1];
         temp[strlen(name)]=bubble;
         }
        fprintf(co," ");
        for(loop=0;loop<strlen(name);loop++){
         fprintf(co,"%c",temp[loop]);
        }
    }
    return 0;
}