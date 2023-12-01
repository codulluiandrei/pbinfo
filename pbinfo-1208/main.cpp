//Rodica Pintea - 100 puncte
program solitar;
const fin='solitar.in';fout='solitar.out';
type interval=record a,b:longint end;
var v:array[1..100000]of interval;
    b:array[1..100000]of boolean;
    c:array[1..50000]of byte;
    n,i,k,x,y:longint;
    f:text;mmin:longint;
begin
  assign(f,fin);reset(f);
  settextbuf(f,c);
  readln(f,n);
  k:=1;
  read(f,x);
  v[k].a:=x;
  for i:=2 to n do begin
      read(f,y);
      if y<>x-1 then begin
            v[k].b:=x;
            inc(k);
            v[k].a:=y
         end;
      x:=y
  end;
  v[k].b:=x;
  close(f);
  mmin:=k-1;
  for i:=k downto 2 do begin
      if not b[v[i].a+1] then
         inc(mmin);
      b[v[i].b]:=true
  end;
  assign(f,fout);rewrite(f);
  writeln(f,mmin);
  close(f)
end.
