void afisare(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    } if (a % 2 == 1) a++;
    for (int i = a; i <= b; i = i + 2)
        cout << i << " ";
}