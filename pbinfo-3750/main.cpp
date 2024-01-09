void InserareInainteQ(nod *& prim,nod *& ultim, nod*q , int x)
{
  if(q==prim)
  {
    nod*p=new nod;
    p->info=x;
    p->ant=NULL;
    p->urm= prim;
    prim->ant=p;
    prim=p;
  }
  else
  {
    nod*p=new nod;
    p->info=x;
    p->urm=q;///1
    p->ant=q->ant;///2
    q->ant->urm=p; ///3
    q->ant=p; ///4
  }
}