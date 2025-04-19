void InserareDupaQ(nod *& prim, nod *& ultim, nod*q,int x)
{
  if(q==ultim)
  {
    nod*p=new nod;
    p->info=x;
    p->pre=NULL;
    p->ant=ultim;
    ultim->pre=p;
    ultim=p;
  }
  else
  {
    nod*p=new nod;
    p->info=x;
    p->pre=q->pre;///1
    p->ant=q;///2
    q->pre=p;///3
    q->pre->ant=p;///4
  }
}