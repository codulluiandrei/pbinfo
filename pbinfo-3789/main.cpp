void oglindire(nod * & p)
{
    nod * a = NULL;
    for( ; p ; )
    {
        nod * t = p;
        p = p->urm;
        t->urm = a;
        a = t;
    }
    p = a;
}