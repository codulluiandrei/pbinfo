/*
Complexitate: O(ValMax * logValMax + N)
Punctaj: 100p
*/

#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 5;
const int VALMAX = 1e6;
const long long KMAX = 1LL*1e18;

ifstream f ("tema.in");
ofstream g ("tema.out");

int A[NMAX];

int Task, N;
long long K;

int fpmax[VALMAX+5];/// fpmax[i] - Cel mai mare factor prim a lui i
int fpmin[VALMAX+5];/// fpmin[i] Cel mai mic factor prim a lui i

bool compus[VALMAX+5];

void Ciur () {
    /// determinam pentru fiecare numar cel mai mic si cel mai mare
    /// factor prim al in timp ce folosind Ciurul lui Eratostene
    /// determinam numerele prime <= VALMAX
    /// numarul x este prim atunci compus[x] = false;

    for (int i = 2; i <= VALMAX; i += 2) {
        fpmax[i] = fpmin[i] = 2;
        compus[i] = true;
    }
    compus[1] = compus[0] = true;
    compus[2] = false;

    for (int i = 3; i <= VALMAX; i += 2) {
        if (!compus[i]) {
            fpmin[i] = i;
            fpmax[i] = i;
            for (int j = 2*i; j <= VALMAX; j += i) {
                if (fpmin[j] == 0) fpmin[j] = i;
                fpmax[j] = i;
                compus[j] = true;
            }
        }
    }
}

void Read () {
    f >> Task >> N >> K;
    int S = 0;
    assert (1<= N && N <= 100000 && K <= KMAX && K > 0);
    for (int i = 1; i <= N; ++ i )
        { f >> A[i];
          assert (1 <= A[i] && A[i] <= 1000000);
          S += (A[i]==1? 1: 0);
        }
    assert (S < N);
}


void Solve_1 () {
    /// pentru fiecare indice curent i, considerat capat dreapta
    /// al secventei curente determinam indicele de inceput al secventei
    /// pentru care produsul nu depaseste K.
    /// Daca produsul este mai mare se renunta la A[st], incrementand st
    /// si actualizand valoarea produsului
    /// se va retine lungimea maxima a secventei ce respecta cerinta

    long long S_prim = 0;
    long long S_compus = 0;

    int ans_st = 0, ans_dr = -1;
    int st = 1;
    for (int i = 1; i <= N; ++ i ) {
        if (compus[A[i]] && A[i] > 1) S_compus += 1LL * A[i];
        if (!compus[A[i]] && A[i] > 1)S_prim += 1LL * A[i];

        while (st <= i && S_prim * S_compus > K) {
            if (compus[A[st]] && A[st] > 1) S_compus -= A[st];
            if (!compus[A[st]] && A[st] > 1) S_prim -= A[st];

            ++ st;
        }

        if (i - st + 1 > ans_dr - ans_st + 1) {
            ans_st = st;
            ans_dr = i;
        }
    }

    g << ans_dr - ans_st + 1 << '\n';
}

int st[2][NMAX];
int dr[2][NMAX];

void Solve_2 () {
    ///Considerand transformarea numerelor deja efectuata determinam pentru fiecare i
    /// st[0][i] - cel mai mic indice din stanga unde regasim fpmin[A[i]] ca factor in toate elementele dintre acel indice si i
    /// st[1][i] - cel mai mic indice din stanga unde regasim fpmax[A[i]] ca factor in toate elementele dintre acel indice si i
    /// dr[0][i] - cel mai mare indice din dreapta unde regasim fpmin[A[i]] ca factor in toate elementele de la i pana la acea pozitie
    /// dr[1][i] - cel mai mare indice din dreapta unde regasim fpmax[A[i]] ca factor in toate elementele de la i pana la acea pozitie
    /// Pentru fiecare A[i] lungimea maxima a secventei care il contine si are cmmdc > 1
    /// este = max{dr[0][i] - st[0][i] + 1, dr[1][i] - st[1][i] + 1}
    for (int i = 0; i < 2; ++ i )
        for (int j = 1; j <= N; ++ j )
            st[i][j] = dr[i][j] = j;

    for (int i = 2; i <= N; ++ i ) {
        if (A[i] == 1) {
            st[0][i] = st[1][i] = i+1;

            continue;
        }

        if (fpmin[A[i]] == fpmin[A[i-1]])
            st[0][i] = st[0][i-1];
        else if (fpmin[A[i]] == fpmax[A[i-1]])
            st[0][i] = st[1][i-1];
        else st[0][i] = i;

        if (fpmax[A[i]] == fpmin[A[i-1]])
            st[1][i] = st[0][i-1];
        else if (fpmax[A[i]] == fpmax[A[i-1]])
            st[1][i] = st[1][i-1];
        else st[1][i] = i;
    }

    for (int i = N-1; i >= 1; -- i ) {
        if (A[i] == 1) {
            dr[0][i] = dr[1][i] = i-1;

            continue;
        }

        if (fpmin[A[i]] == fpmin[A[i+1]])
            dr[0][i] = dr[0][i+1];
        else if (fpmin[A[i]] == fpmax[A[i+1]])
            dr[0][i] = dr[1][i+1];
        else dr[0][i] = i;

        if (fpmax[A[i]] == fpmin[A[i+1]])
            dr[1][i] = dr[0][i+1];
        else if (fpmax[A[i]] == fpmax[A[i+1]])
            dr[1][i] = dr[1][i+1];
        else dr[1][i] = i;
    }

    int ans_left = 1, ans_right = 0;
    for (int i = 1; i <= N; ++ i ) {
        int lg = dr[0][i] - st[0][i] + 1;

        if (lg > (ans_right - ans_left + 1)) {
            ans_left = st[0][i];
            ans_right = dr[0][i];
        }
        else if (lg == (ans_right - ans_left + 1) && ans_left < st[0][i]) {
            ans_left = st[0][i];
            ans_right = dr[0][i];
        }

        lg = dr[1][i] - st[1][i] + 1;
        if (lg > (ans_right - ans_left + 1)) {
            ans_left = st[1][i];
            ans_right = dr[1][i];
        }
        else if (lg == (ans_right - ans_left + 1) && ans_left < st[1][i]) {
            ans_left = st[1][i];
            ans_right = dr[1][i];
        }
    }

    g << ans_left << " " << ans_right << '\n';
}

int main () {
    Ciur();

    Read();

    if (Task == 1) Solve_1();
    else Solve_2();

    return 0;
}
