void FInserareKX(Nod * &head, int k, int x)
{
    Nod *p, *q;
    if (k <= 1 || head == NULL)
    {
        p = new Nod;
        p->info = x;
        p->leg = head;
        head = p;
        return;
    }
    for (p = head; p->leg != NULL && k > 2; p = p->leg)
        k--;
    q = new Nod;
    q->info = x;
    q->leg = p->leg;
    p->leg = q;
}