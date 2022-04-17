int verifprim(int nr) {
    if (nr < 2) return false;
    if (nr % 2 == 0 && nr > 2) return false;
    for (int temp = 3; temp * temp <= nr; temp = temp + 2) if (nr % temp == 0) return false;
    return true;
}
int nr_prim(int x){
    x++;
    while (!verifprim(x)) x++;
    return x;
}