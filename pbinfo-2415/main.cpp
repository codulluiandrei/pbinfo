/// Vlad Tir, Colegiul National "Tudor Vladimirescu", Targu-Jiu
#include <cstdio>
/// Functie ce returneaza numarul de cifre ale lui x
int nr_cifre(int x){
    int ct=0;
    if(x==0) return 1;
    while(x>0){
        ++ct;
        x/=10;
    }
    return ct;
}
/// Functie ce returneaza a^b
int pow(int a,int b){
    int P=1;
    for(int i=1;i<=b;++i)
        P*=a;
    return P;
}
/// Functie ce returneaza oglinditul lui x
int rev(int x){
    int ans=0;
    while(x>0){
        ans=ans*10+(x%10);
        x/=10;
    }
    return ans;
}
int nr_pal(int n){
    if(n==-1) return 0;
    int cif=nr_cifre(n),ans=1;
    /// Daca n are numar impar de cifre
    if(cif%2==1){
        ans+=2*(pow(10,cif/2)-1);
        /// Palindromul de cif cifre format din primele cif/2+1 cifre ale lui n
        int pal=n/pow(10,cif/2)*pow(10,cif/2)+rev(n/pow(10,cif/2+1));
        /// Daca n este mai mare decat pal,avem o solutie in plus
        if(n>=pal) ans+=n/pow(10,cif/2)-pow(10,cif/2)+1;
        else ans+=n/pow(10,cif/2)-pow(10,cif/2);
    }
    /// Daca n are numar par de cifre
    else{
        ans+=2*(pow(10,(cif-1)/2)-1)+9*pow(10,(cif-1)/2);
        /// Palindromul de cif cifre format din primele cif/2 cifre ale lui n
        int pal=n/pow(10,cif/2)*pow(10,cif/2)+rev(n/pow(10,cif/2));
        /// Daca n este mai mare decat pal,avem o solutie in plus
        if(n>=pal) ans+=n/pow(10,cif/2)-pow(10,cif/2-1)+1;
        else ans+=n/pow(10,cif/2)-pow(10,cif/2-1);
    }
    return ans;
}
int main(){
    int n;
    freopen("nr_pal.in","r",stdin);
    freopen("nr_pal.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",nr_pal(b)-nr_pal(a-1) );
    }
    return 0;
}