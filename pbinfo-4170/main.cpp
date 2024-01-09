void FLsiDesc(Nod *head)
{
    int n = head->info;
    Nod *p, *q, *r;
    q = p = head;
    while (n > 0)
    {
        if (q == NULL || q->info != n)
        {
            r = new Nod;
            r->info = n;
            r->leg = p->leg;
            p->leg = r;
            p = r;
        }
        else
        {
            p = q;
            q = q->leg;
        }
        n--;
    }
}