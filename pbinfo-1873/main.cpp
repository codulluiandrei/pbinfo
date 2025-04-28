#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char s[101],s2[101]="";
    int ok=0;
    cin.getline(s,101);
    char *cuv=strtok(s," ");
    while(cuv)
    {
        if(strlen(cuv)%2==0)
        {
            ok=1;
            strcat(s2,"#");
        }
        else
            strcat(s2,cuv);
        strcat(s2," ");
        cuv=strtok(NULL," ");
    }
    if(ok==0)
        cout<<"nu exista";
    else
    {
        s2[strlen(s2)-1]='\0';
        strcpy(s,s2);
        cout << s;
    }
    return 0;
}