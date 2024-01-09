bool Palindrom(nod* prim, nod* ultim)
{
    nod*p,*q;
    for(p=prim,q=ultim;p!=q; p=p->urm,q=q->ant)
        if(p->info!=q->info) return 0;
    return 1;
}