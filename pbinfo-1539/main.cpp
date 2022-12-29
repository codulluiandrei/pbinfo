int apartenenta(int numar) {
    int valori[] = {2, 3, 5};
    for (int i = 0; i < 3; i++)
        while (numar % valori[i] == 0)
        	numar = numar / valori[i];
	return (numar == 1);
}   