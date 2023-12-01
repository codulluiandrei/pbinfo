type sir= array[0..10000] of integer;
var   n,nr,i,k,max:longint;
   x,y,rez,g,cx,cy:longint;
   a,b:sir;
   f,ff: text;


begin
for i:=0 to 10000 do
        a[i]:=0;
assign(f,'cladiri1.in');
reset(f);
readln(f,cx,cy,g);
nr:=0;
while not (eof(f)) do
   begin
   readln(f,x,y,rez);
   if abs(cx-x)>abs(cy-y) then
        max:=abs(cx-x)
        else
        max:=abs(cy-y);
   if (g-max >0 ) and (rez-(g-max) <=0 ) then
        begin
        nr:=nr+1;
        a[max]:=a[max]+1;
        end;
   end;
max:=-1;
k:=0;
for i:=0 to 10000 do
        if max=a[i] then
            begin
            k:=k+1;
            b[k]:=i;
            end
            else
            if max<a[i] then
                begin
                max:=a[i];
                k:=1;
                b[k]:=i;
                end;

assign(ff,'cladiri1.out');
rewrite(ff);
writeln(ff,nr);
writeln(ff,max);
if nr <>0 then
   for i:=1 to k do
        write(ff,b[i],' ');
close(ff);
close(f);
end.
