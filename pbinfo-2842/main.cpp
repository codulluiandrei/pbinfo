void triplete(int n)
{
    int y = 1;
    while(y * y < n)
    {
        if(n % y == 0)
            for(int x = 0 ; x < y ; x ++)
                if(n/y-x > y)
                    cout << "(" << x << "," << y << "," << n/y-x <<")\n";
        y ++;
    }
}