void generatoare(int n) {
    bool ok = 0;
    for(int a = 2;a < n / 2;a += 2) {
        int b = n / a;
        if(a * b + a / b == n) {
            ok = 1;
            cout << a << "-" << b << " ";
        }
    }
    if(((n / 2) % 2 == 0) && n % 2 == 0) {
        ok = 1;
        cout << n / 2 << "-" << 1; 
    }
    if(!ok) {
        cout << "nu exista";
    }
}