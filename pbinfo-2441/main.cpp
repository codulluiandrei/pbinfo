#include <iostream>
#include <string.h>

using namespace std;

char s[101],a[51][101];
int main()
{
    cin.getline(s,101);
    int k=0,i,j;
    char *p=strtok(s," ");
    while(p)
    {
        strcpy(a[k++],p);
        p=strtok(NULL," ");
    }
    for(i=0; i<k; i++)
    {
        if(strlen(a[i])%2!=0)
        {
            char x[102];
            strcpy(x,a[i]);
            x[(strlen(x)+1)/2]=0;
            strcat(x,a[i]+(strlen(a[i])-1)/2);
            for(j=0; j<k; j++)
                if(strcmp(x,a[j])==0)
                {
                    cout<<"DA";
                    return 0;
                }
        }
    }
    cout<<"NU";
    return 0;
}
