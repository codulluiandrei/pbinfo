program alo;
var f,g:text;
   e,n,x,i,pc,uc,nr,d:longint;
begin
 assign(f,'alo.in');reset(f);
 assign(g,'alo.out');rewrite(g);
 readln(f,e,n);
 for i:=1 to n do
   begin
   readln(f,x,d);
   pc:=x div 10000;
   uc:=x mod 10;
   if pc=1 then begin
                if uc=5 then e:=e-2*d;
                end
   else begin
        if uc=5 then e:=e+d;
        end;
   end;
 writeln(g,e);
 close(g);
end.