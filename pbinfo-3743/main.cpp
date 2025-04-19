void AdaugareInceput(nod*&prim, nod*&ultim, int x)
{
  if(prim==NULL)
  {
    prim=new nod;
    prim->info=x;
    prim->ant=NULL;
    prim->urm=NULL;
    ultim=prim;
  }
  else
  {
    nod*p=new nod;
    p->info=x;
    p->ant=NULL;
    p->urm= prim;
    prim->ant=p;
    prim=p;
  }
}