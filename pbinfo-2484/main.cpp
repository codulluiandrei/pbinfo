#include <fstream>
char a[4],b[4];int s,d,f,g,P,n,c,t,m,k;
std::ifstream I("key.in");
std::ofstream O("key.out");
int main(){
    I>>P>>a>>n;
    while(n--){
        I>>b>>c;m=0,k=-1;
        while(++k<3)
            if(a[k]==b[k])++m;
        switch(m){
            case 0:t+=c;++s;break;
            case 1:t+=c/3*2;++d;break;
            case 2:t+=c/3;++f;break;
            case 3:++g;break;
        }
    }
    if(P==1)
        O<<s<<' '<<d<<' '<<f<<' '<<g;
    else
        if(t)O<<t;
        else O<<"GRATIS";
}