void triplete(int a, int b , int c)
{
    int gasit = 0;
    for(int x = a ; x <= b ; x ++)
        for(int y = x ; y <= b && x + y + y <= c ; y ++)
        {
            int z = c - x - y;
            if(y <= z && z <= b)
            {
                cout << "{" << x << "," << y << "," << z <<"}\n";
                gasit = 1;
            }
        }
    if(!gasit)
        cout << "nu exista\n";
}