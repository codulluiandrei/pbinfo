#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("reteta.in");
ofstream fout("reteta.out");
int main(){
    char s[1001],nume[101][21];
    int cantitate[101],nri=0;
    fin.getline(s,1001);
    int durata = 0;
    for(int i=0;s[i];++i){
        if(s[i]>='a' && s[i]<='z'){
            //incepe un cuvant
            char c[21]="";int lc=0;
            while(s[i]>='a' && s[i]<='z')
                c[lc++] = s[i++], c[lc]=0;
            while(s[i]==' ')
                i++;
            int tt=0;
            while(s[i]==' ') i++;
            while(s[i]>='0' && s[i]<='9')
                tt= 10*tt+s[i]-'0', i++;
            i--;
            int poz = 0;
            for(int j=1 ; j<=nri && poz==0 ; ++j)
                if(strcmp(c,nume[j])==0)
                    poz=j;
            if(poz!=0)
                cantitate[poz] += tt;
            else{
                nri++ ;
                strcpy(nume[nri], c);
                cantitate[nri]=tt;
            }
        }
        if(s[i]==')'){
            int tt=0;
            i++;
            while(s[i]==' ') i++;
            while(s[i]>='0' && s[i]<='9')
                tt= 10*tt+s[i]-'0', i++;
            //fout<<tt<<" ";
            durata += tt;
            i--;
        }
    }
    fout<<durata<<endl;
    for(int i=1;i<nri;++i)
        for(int j=i+1;j<=nri;++j)
            if(strcmp(nume[i],nume[j])>0){
                char a[21]; strcpy(a,nume[i]); strcpy(nume[i], nume[j]); strcpy(nume[j],a);
                int x=cantitate[i]; cantitate[i]=cantitate[j], cantitate[j]=x;
            }
    for(int i=1;i<=nri;++i)
        fout<<nume[i]<<" "<<cantitate[i]<<endl;
    return 0;
}