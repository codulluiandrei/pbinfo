// o posibila solutie pentru problema ecuatii_grad_2 #1458 @pbinfo
// programul poate fi imbunatatit
// compilat cu Code::Blocks 13.12
#include <cstring>  // strlen, strcpy
#include <cmath>    // sqrt
#include <cstdio>   // scanf, printf cu numar definit de zecimale
#include <cstdlib>  // atoi
double min(double a, double b) {
    return (a > b) ? b : a;
}
double max(double a, double b) {
    return (a > b) ? a : b;
}
//------------------------------------------------------------------------------------------------------------
// determinam coeficientul (de tip int) din sierul initial (de tip char*)
// verificare=1 se foloseste la a si b, unde sirInitial poate contine doar '+' (sau nu contine nimic) pentru 1 si '-' pentru -1
int determinare(char sirInitial[], int verificare=1) {
    int lungime = strlen(sirInitial);
    if(verificare) {
        if( lungime == 0 )
            return 1;
        if( lungime == 1 && sirInitial[0] == '-' )
            return -1;
    }
    if(lungime == 1 && sirInitial[0] == '+')
        return 1;
    return atoi(sirInitial);
}
//------------------------------------------------------------------------------------------------------------
// ecuatie[] este de forma "ax^2+bx+c", asa ca atribuim variabilelor a, b, c, transmise prin referinta, valorile aferente
void separare(char ecuatie[], int &a, int &b, int &c) {
    int lungime = strlen(ecuatie), lungimeCoeficienti[3] = {0}, pozitie = 0;
    char coeficienti[3][100]; // coeficienti[0] -> a, coeficient[1] -> b, coeficienti[2] -> c
    while( ecuatie[pozitie] != 'x' ) // separare sir a
        coeficienti[0][ lungimeCoeficienti[0]++ ] = ecuatie[pozitie++];
    coeficienti[0][ lungimeCoeficienti[0] ] = '\0';
    pozitie += 3;
    while( ecuatie[pozitie] != 'x' ) // separare sir b
        coeficienti[1][ lungimeCoeficienti[1]++ ] = ecuatie[pozitie++];
    coeficienti[1][ lungimeCoeficienti[1] ] = '\0';
    pozitie += 1;
    while( pozitie < lungime ) // separare sir c
        coeficienti[2][ lungimeCoeficienti[2]++ ] = ecuatie[pozitie++];
    coeficienti[2][lungimeCoeficienti[2]] = '\0';
    a = determinare(coeficienti[0]);
    b = determinare(coeficienti[1]);
    c = determinare(coeficienti[2], 0);
}
//------------------------------------------------------------------------------------------------------------
// Programul principal (citirea ecuatiei din fisier, separarea coeficientilor, determinarea rezultatului)
int main(void) {
    freopen("ecuatii.in", "r", stdin);
    freopen("ecuatii.out", "w", stdout);
    char ecuatie[100];
    int a, b, c;
    gets(ecuatie);
    separare(ecuatie, a, b, c);
    // solutiile reale ale ecuatiei
    double x1, x2;
    // afisarea solutiilor
    int delta = b * b - 4 * a * c;
    if( delta < 0 )
        printf("-1"); // ecuatia nu are solutie
    else if(delta == 0) // ecuatia are o singura solutie
        printf("%.2f", (double) (-b) / (2 * a));
    else { // ecuatia are doua solutii -> o afisam pe cea mai mica, urmata de cea mai mare
        double radDelta = sqrt(delta);
        x1 = (-b + radDelta) / (2*a);
        x2 = (-b - radDelta) / (2*a);
        printf("%.2f %.2f", min(x1, x2), max(x1, x2));
    }
    return 0;
}