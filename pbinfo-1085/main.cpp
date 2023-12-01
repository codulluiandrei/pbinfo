var  i,j,n,mx,mn,max,min,x:longint;
     a:array[0..10000]of boolean;
     b:array[1..6]of integer;

begin
 assign(input,'loto.in'); reset(input);
 assign(output,'loto.out');rewrite(output);
 readln(n);
 fillchar(a,sizeof(a),false);
 for i:=1 to n do begin
    read(x);a[x]:=true;
 end;

 max:=0; min:=10000; mx:=0;mn:=0;
 for i:=1 to 6 do begin
   read(b[i]); a[b[i]]:=false;
   if b[i]<min then begin min:=b[i]; mn:=i; end;
   if b[i]>max then begin max:=b[i]; mx:=i; end;
 end;
 i:=min; j:=min;
 repeat
   if i<10000 then inc(i);
   if j>1 then dec(j)
 until a[i] or a[j];
 if a[i] then b[mn]:=i else b[mn]:=j;
 a[b[mn]]:=false;
 i:=max; j:=max;
 repeat
   if i<10000 then inc(i);
   if j>1 then dec(j)
 until a[i] or a[j];
 if a[i] then b[mx]:=i else b[mx]:=j;

 for i:=1 to 5 do
   for j:=i+1 to 6 do
     if b[i]>b[j] then begin
      b[i]:=b[i]+b[j];
      b[j]:=b[i]-b[j];
      b[i]:=b[i]-b[j];
     end;

 for i:=1 to 5 do write(b[i],' ');
 writeln(b[6]);
 close(output);
end.
