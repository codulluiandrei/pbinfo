//---------------------------------------------------------------------------------------------------------------
// c = a * b
void inmultire(matrice_rara a, matrice_rara b, matrice_rara &c) {
    // se presupune ca numarul de coloane din matricea a este egal cu numarul de linii din matricea b
    c.nr_linii      = a.nr_linii;
    c.nr_coloane    = b.nr_coloane;
    c.nr_triplete   = 0;
    // calculul inmulturii
    for(int i = 0; i < a.nr_linii; i++)
        for(int j = 0; j < b.nr_coloane; j++) {
            int suma = 0;
            // calcul valoare element
            for(int col = 0; col < a.nr_coloane; col++)
                for(int i1 = 0; i1 < a.nr_triplete; i1++)
                    // verificam daca exista in a si b
                    if(a.t[i1].linie == i && a.t[i1].coloana == col)
                        for(int i2 = 0; i2 < b.nr_triplete; i2++)
                            if(b.t[i2].linie == col && b.t[i2].coloana == j)
                                suma += a.t[i1].valoare * b.t[i2].valoare;
            if(suma != 0)
                c.t[c.nr_triplete++] = {i, j, suma};
        }
}