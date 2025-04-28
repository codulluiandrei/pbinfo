do {   
    ok = 1;    
    for ( i = 1; i < N; i ++ )      
        if ( a[i] > a[i+1] ){        
             swap(a[i], a[i+1]);   
             ok = 0;   
        }
}while( ok == 0 );          