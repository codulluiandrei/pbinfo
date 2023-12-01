/*

primprim - Stefan Dascalescu

*/

#include <fstream> 
#include <cmath>
   
using namespace std; 


ifstream fin("primprim.in"); 
ofstream fout("primprim.out"); 
   
int vals[1000002];

int primes[200002], cnt;
int ans[1100002];
bool pr[1100002];

int fr[202];

int main()  
{  
    int c; 
    fin >> c; 
      
    int n, a = 1100000, i, j; 
    fin >> n; 
      
    for(i = 1; i <= n; i++) 
        fin >> vals[i]; 
      
    // precalculam raspunsul optim pentru fiecare numar de la 1 la a folosind ciurul lui Eratostene 
      
    for(i = 2; i <= a; i++) 
    { 
        if(pr[i] == 0) 
        { 
			primes[cnt++] = i;
            for(j = i+i; j <= a; j += i) 
                pr[j] = 1; 
        } 
    } 
      
    int poz = -1; 
      
    // parcurg valorile de la 1 la a pentru a afla raspunsul optim dupa ce am aflat numerele prime 
    ans[1] = 1; 
    for(i = 2; i <= a; i++) 
    { 
        if(pr[i] == 0) 
            poz++; 
        ans[i] = abs(i - primes[poz]); 
        if(poz + 1 < cnt) 
            ans[i] = min(ans[i], abs(i - primes[poz+1])); 
    } 
      
    // voi folosi vector de frecventa pentru a tine aceste diferente, care de altfel sunt destul de mici 
      
    for(i = 1; i <= n; i++) 
        fr[ans[vals[i]]]++; 
      
    if(c == 1) 
    { 
        int total = 0;           
        for(i = 1; i <= n; i++) 
            total += ans[vals[i]]; 
          
        fout << total; 
        return 0; 
    } 
      
    int q; 
    fin >> q; 
      
    for(i = 1; i <= q; i++) 
    { 
        int a, b, p; 
        fin >> a >> b >> p; 
          
        fr[ans[vals[a]]]--; 
          
        vals[a] = b; 
          
        fr[ans[vals[a]]]++; 
          
        int dif = 0; 
        int sol = 0; 
          
        // la fiecare pas parcurg vectorul de frecventa pana cand dau de p diferente 
          
        while(p) 
        { 
            sol += min(p, fr[dif]) * dif; 
            p -= min(p, fr[dif]); 
            dif++; 
        } 
          
        fout << sol << '\n'; 
    } 
      
    return 0; 
} 
