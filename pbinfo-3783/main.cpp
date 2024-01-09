void StergeAfterQ(nod*&prim,nod*&ultim, nod*q)
{
  nod*p=q->pre;

  if(q==ultim) return;

  if(p==ultim)
  {
    ultim->ant->pre=NULL;
    ultim=ultim->ant;
    delete p;
  }
  else
  {
    q->pre=p->pre;
    p->pre->ant=q;
    delete p;
  }
}
