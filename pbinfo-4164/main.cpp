void FAdaugaInainte(Nod * &head)
{
    Nod *p, *q, *r;
    int flag = 0;
    if (head->info % 2 == 1)
    {
        flag = 1;
        p = new Nod;
        p->info = head->info * 2;
        p->leg = head;
        head = p;
    }
    if (flag == 0)
    {
        q = head;
        p = head->leg;
    }
    else
    {
        q = head->leg;
        p = head->leg->leg;
    }
    while (p != NULL)
    {
        if (p->info % 2 == 1)
        {
            r = new Nod;
            r->info = p->info * 2;
            r->leg = p;
            q->leg = r;
            q = r;
        }
        p = p->leg;
        q = q->leg;
    }
}