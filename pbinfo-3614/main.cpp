int suma(int a, int b) {
    int minim, S = 0;
	if (a < b)
        minim = a;
    else 
        minim = b;
    for (int i = 1; i <= minim; ++i)
        if (a % i == 0 && b % i == 0)
        	S = S + i;
	return S;
}