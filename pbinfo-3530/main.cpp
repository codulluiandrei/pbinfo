    // returneaza maximul din t
    int Max()
    {
        int M = t[0];
        for (int i = 1; i < n; i++)
            if (M < t[i]) M = t[i];
        return M;
    }
    // returneaza prima pozitie unde se gaseste val in t,
    // sau returneaza -1 daca val nu apare in t
    int Cauta(int val)
    {
        for (int i = 0; i < n; i++)
            if (t[i] == val) return i;
        return -1;
    }