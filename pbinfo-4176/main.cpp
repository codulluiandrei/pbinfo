void FLdiAdDupa(nod *&prim, nod *&ultim, int x)
{
    nod *p, *q;
    q = prim;
    for (p = prim; p != NULL; p = p->urm)
        if (q->info > p->info) q = p;
    p = new nod;
    p->info = x;
    if (q == ultim) /// adaug p ca ultim nod
    {
        p->urm = NULL;
        p->ant = q;
        q->urm = p;
        ultim = p;
        return;
    }
    p->urm = q->urm;
    p->ant = q;
    q->urm->ant = p;
    q->urm = p;
}