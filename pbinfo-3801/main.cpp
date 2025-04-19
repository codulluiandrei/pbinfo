void LsiInterclasare(Nod *h1, Nod *h2, Nod *&h)
{
    Nod *p1, *p2, *ult;
    p1 = h1; p2 = h2;
    if (p1->info <= p2->info)
    {
        h = p1;
        p1 = p1->leg;
    }
    else
    {
        h = p2;
        p2 = p2->leg;
    }
    ult = h;
    while (p1 != NULL && p2 != NULL)
        if (p1->info <= p2->info)
        {
            ult->leg = p1;
            p1 = p1->leg;
            ult = ult->leg;
        }
        else
        {
            ult->leg = p2;
            p2 = p2->leg;
            ult = ult->leg;
        }
    if (p1 != NULL) ult->leg = p1;
    else ult->leg = p2;
}