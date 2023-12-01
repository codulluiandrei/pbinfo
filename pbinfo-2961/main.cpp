// prof. Chesca Ciprian - 100 p
// cu constructia matricei sumelor partiale O(lc) si O(sqrt(m))
// sursa cu assert

#include <fstream>
#include <cassert>

using namespace std;


int a[501][501];
int w[501],mat[501][501];

int main()
{
     int l,c,i,j,k,m,x,y,maxl,s,v,maxm,ls,cs,ok,i1,j1;

     /*  l = linii
        c = coloane
        m = numar de mine
        x,y = coordonate mina
        v = varianta
        maxm = numarul maxim de mine dintr-o zona de scanare
        maxl = numarul maxim de mine de pe o linie
        k = contorul pentru numararea minelor dintr-o zona de scanare
        ok = indicator pentru a determina daca problema are solutie
        ls, cs = numarul de linii si coloane al zonei de scanare
    */
    ifstream f("deminare.in");
    ofstream g("deminare.out");



    // citire date de intrare
    f >> v;
    assert(v>=1 && v <=2);

    f >> l >> c;
    assert(l>=1 && l<=500);
    assert(c>=1 && c<=500);

    f >> m;
    assert(m>=1 && m<=l*c);

    int perechi = 0;
    while(f>>x>>y)
        {
        assert(x>=1 && x<=l);
        assert(y>=1 && y<=c);
        perechi++;
        a[x][y]=1;
        }


    // prima cerinta
    if (v == 1)
        {
        // cerinta = care este linia pe care se gasesc cele mai multe mine
        // daca sunt mai multe linii se afiseaza toate in ordine crescatoare cu spatiu intre ele

        // aflu numarul de mine pe linii
        for(i=1;i<=l;i++)
            {
            s=0;
            for(j=1;j<=c;j++)
                if(a[i][j]==1) s++;
            w[i]=s;
            }

        // aflu maximul de mine de pe o linie
        maxl=w[1];
        for(i=1;i<=l;i++)
             if (w[i]>maxl) maxl=w[i];
        // afisez linia(iile)
        for(i=1;i<=l;i++)
             if (w[i]==maxl) g << i << " ";
        g << "\n";
        }


     // cerinta a doua
     if(v == 2)
        {
        // cerinta = numarul minim de mutari de mine astfel incat sa se obtina o suprafata dreptunghiulara


        // aflu numarul de mine in submatricile (1,1) si (i,j) cu (i,j) de la 1<=i<=l si l<=j<=c
	// am renuntat sa calculez separat prima linie si prima coloana pentru ca oricum valorile sunt 0
        
        for(i=1;i<=l;i++)
            for(j=1;j<=c;j++)
    		 mat[i][j]=a[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];

        // descompun m in produs de 2 numere naturale

        ok = 0; maxm = 0;
        for(i=1;i*i<=m;i++)
            if (m%i==0)
                    {
                    ls = i;cs = m/i;
                    // incep scanarea directa
                    if (ls <= l && cs <= c)
                        {
                        ok = 1;
                        for(i1=1;i1<=l-ls+1;i1++)
                            for(j1=1;j1<=c-cs+1;j1++)
                                    {
                                    k = mat[i1+ls-1][j1+cs-1] - mat[i1+ls-1][j1-1] - mat[i1-1][j1+cs-1] + mat[i1-1][j1-1];
                                    if (k > maxm) maxm = k;
                                    }
                        }
		    ls = m/i;cs = i;
                    // si inversa
                    if (ls <= l && cs <= c)
                        {
                        ok = 1;
                        for(i1=1;i1<=l-ls+1;i1++)
                            for(j1=1;j1<=c-cs+1;j1++)
                                    {
                                    k = mat[i1+ls-1][j1+cs-1] - mat[i1+ls-1][j1-1] - mat[i1-1][j1+cs-1] + mat[i1-1][j1-1];
                                    if (k > maxm) maxm = k;
                                    }
                        }
                    }
        if (!ok) g << "-1\n";
            else g << m - maxm << "\n";
        if (perechi!=m) g << "eroare!";
        }
    return 0;
}
