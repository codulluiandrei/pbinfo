int FLsiDublu(Nod *head)
{
    Nod *p, *q, *r;
    int n = 0;
    /// numara cate noduri are lista
    for (p = head; p != NULL; p = p->leg)
        n++;
    if (n % 2 == 1) return -1;
    /// pozitionam pointerul q la nodul n/2+1
    n /= 2;
    for (r = q = head; q != NULL && n > 0; q = q->leg)
    {
        n--;
        r = q;
    }
    /// verificam egalitatea celor doua jumatati
    p = head;
    while (q != NULL)
    {
        if (p->info != q->info) return -1;
        p = p->leg;
        q = q->leg;
    }
    return r->info;
}