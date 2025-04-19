void prev_perm(int n,int P[])
{
    int i=n;
    while(i>1 && P[i-1]<=P[i])
        i--;
    int j=i-1;
    while(j+1<=n && P[j+1]<=P[i-1])
        j++;
    swap(P[i-1],P[j]);
    reverse(P+i,P+n+1);
}