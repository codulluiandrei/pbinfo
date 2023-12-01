program numere;
var c,n:longint;
    f:text;
function performant(c,k:longint):longint;
var i,j,n,z:longint;
begin
n:=0;{nr de aparitii a cifrei c}
j:=1;{pornim de la ultima cifra(j=10-penultima cifra,j=100-antepenultima...)}
z:=0;{in z memoram ultimele cifre ale numarului k, care au fost extrase}
while k>=c do
 begin
 if k mod 10>c then n:=n+(k div 10+1)*j
  else if k mod 10=c then n:=n+(k div 10)*j+z+1
         else n:=n+(k div 10)*j;
 z:=z+(k mod 10)*j;
 k:=k div 10;
 j:=j*10;
 end;
performant:=n;
end;
Begin
assign(f,'aparitiicifra.in');reset(f);
readln(f,n,c);
close(f);
assign(f,'aparitiicifra.out');rewrite(f);
writeln(f,performant(c,n));
close(f);
End.
