void StergeQ(nod*&prim, nod*&ultim, nod*q)
{
  if(q==prim)
  {
    prim->pre->ant=NULL;
    prim=prim->pre;
    delete q;
  }
  else if(q==ultim)
  {
    ultim->ant->pre=NULL;
    ultim=ultim->ant;
    delete q;
  }
  else
  {
    q->ant->pre=q->pre;
    q->pre->ant=q->ant;
    delete q;
  }
}