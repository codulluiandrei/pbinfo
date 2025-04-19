int FLdiCauta(nod *prim, nod *ultim, int k)
{
    nod *p;
    if (k > 0)
    {
        for (p = prim; p != NULL && k > 1; p = p->urm)
            k--;
        if (p == NULL) return ultim->info;
        return p->info;
    }
    k = -k;
    for (p = ultim; p != NULL && k > 1; p = p->ant)
        k--;
    if (p == NULL) return prim->info;
    return p->info;
}