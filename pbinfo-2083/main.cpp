void ordon123(int n, int a[]){
    int i = 0, m = 0, j = n-1;

    while ( m <= j ){
        switch ( a[m] ){
            case 1 : { swap (a[i], a[m]); ++i; ++m; break; }
            case 2 : { ++m; break; }
            case 3 : { swap (a[m], a[j]); --j; break; }
        }
    }
}