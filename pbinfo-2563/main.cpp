void ins_cresc(nod *&p, int x)
{
    nod *q, *r;
    if (p->info >= x)
    {
        q = new nod;
        q->info = x;
        q->urm = p;
        p = q;
        return;
    }
    for (q = r = p; q != NULL && q->info < x; q = q->urm)
        r = q;
    q = new nod;
    q->info = x;
    q->urm = r->urm;
    r->urm = q;
}