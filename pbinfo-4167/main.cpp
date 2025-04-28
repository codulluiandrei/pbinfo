void FLsiElimina(Nod *&head)
{
    Nod *p, *q, *r, *t;
    /// cauta primul nod p cu p->info divizibil cu 3
    for (r = p = head; p->info % 3 != 0; p = p->leg)
        r = p;
    /// cauta ultimul nod q cu q->info divizibil cu 3
    for (q = t = p; t != NULL; t = t->leg)
        if (t->info % 3 == 0) q = t;
    /// elimina toate nodurile de la p la q, inclusiv acestea
    q = q->leg;
    if (head == p) head = q;
    else r->leg = q;
}