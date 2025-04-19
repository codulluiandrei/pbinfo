void cnt_cif(int n, int k ,int &c)
{
    if(n < 9)
    {
        if(n >= k)
            c = 1;
        else
            c = 0;
    }
    else
    {
        cnt_cif(n / 10, k , c);
        if(n % 10 >= k)
            c ++;
    }
}