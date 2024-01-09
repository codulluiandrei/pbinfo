void FLdiAdInainte(nod *&prim, nod *&ultim, int x)
{
    nod *p, *q;
    q = prim;
    for (p = prim; p != NULL; p = p->urm)
        if (q->info > p->info) q = p;
    p = new nod;
    p->info = x;
    if (q == prim) /// adaug p ca prim nod
    {
        p->urm = q;
        p->ant = NULL;
        q->ant = p;
        prim = p;
        return;
    }
    p->urm = q;
    p->ant = q->ant;
    q->ant->urm = p;
    q->ant = p;
}
