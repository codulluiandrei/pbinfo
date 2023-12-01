int next(int n)
{
    // n este un numar cu toate cifrele identice
    // functia determina si returneaza urmatorul asemenea numar
    
    int c = n % 10, nrc = 0;
    do
        nrc ++, n/= 10;
    while(n != 0);
    if(c < 9)
        c++;
    else
        c = 1 , nrc ++;
    n = 0;
    while(nrc)
        n = 10 * n + c, nrc --;
    return n;
}

void identice(int a , int b)
{
    int cnt = 0, i = 1;
    while(i <= b)
    {
        if(i >= a)
            cout << i << " ", cnt ++;
        i = next(i);
    }
    if(cnt == 0)
        cout << "nu exista";
}