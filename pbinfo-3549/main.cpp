#include <iostream>

using namespace std;

void eliminaPrimaLitera(char c[51]){
    int i=0;
    while (c[i]!=0){
       c[i]=c[i+1];
       i++;
    }
    c[i]=0;
 // pentru ca strcpy(c,c+1); nu merge ?!
}

int strlen(char *c){ // daca tot...
    int i=0;
    while (c[i])i++;
    return i;
}

long long citesteVal(char c[51]){
    long long v = 0;
    while(c[0]>='0' && c[0]<='9') {
        v = v * 10 + (c[0]-'0');
        eliminaPrimaLitera(c);
    }
    return v;
}

long long evalExp(char c[51]);

long long evalPar(char c[51]){
    char str[51]="";
    int p=1;eliminaPrimaLitera(c);
    while (p>0)
    {
        if (c[0]=='(') p++;
        if (c[0]==')') p--;
        str[strlen(str)] = c[0];
        eliminaPrimaLitera(c);
    }
    str[strlen(str)-1]=0;
    long long valoare = evalExp(str);
    return valoare;
}

long long evalExp(char c[51]){
    long long st[30];
    int vf = 0;

    while(strlen(c)>0)
    {
        long long neg=1;
        if (c[0]=='+') {eliminaPrimaLitera(c);}
        if (c[0]=='-') {neg=-1; eliminaPrimaLitera(c);}

        long long primaValoare;
        if (c[0]!='(')
        {
            primaValoare = citesteVal(c);
        }

        if (c[0]=='(')
        {
            primaValoare = evalPar(c);
        }

        st[vf] = primaValoare*neg;
        vf++;

        while (c[0]=='*')
        {
            eliminaPrimaLitera(c);
            if (c[0]!='(') st[vf-1] = st[vf-1] * citesteVal(c);
            if (c[0]=='(')
            {
                st[vf-1] = st[vf-1] * evalPar(c);
            }
        }
    }
    long long s=0;
    for(int i=0; i<vf; i++)
        s+= st[i];
    return s;
}

int main() {
    char sir[51];
    cin.get(sir,50);
    cout << evalExp(sir);
    return 0;
}
