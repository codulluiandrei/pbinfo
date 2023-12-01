#include <iostream>

using namespace std;

char vocale[10001];
char consoane[10001];

int main()
{
    int n;
    char c;
    int contorVocale=0;
    int contorConsoane=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c==97 || c==101 || c==105 || c==111 || c==117) //Caracterul citit este o vocala
        {
            vocale[contorVocale]=c;
            contorVocale++;
        }
        else //Caracterul citit este o consoana
        {
            consoane[contorConsoane]=c;
            contorConsoane++;
        }
    }

    for(int i=0;i<=contorVocale-1;i++)
    {
        cout<<vocale[i]<<" ";
    }

    for(int i=0;i<=contorConsoane-1;i++)
    {
        cout<<consoane[i]<<" ";
    }
}
