const NMAX=100;

var n: integer;
    pct: array[1..NMAX] of integer;
    bonus: integer;
    m: integer;
    p: integer;

    i, j: integer;
    complet: boolean;
    crt: integer;
    max: integer;
    fin, fout: text;

begin
assign(fin, 'submit.in');  reset(fin);
assign(fout,'submit.out'); rewrite(fout);

readln(fin, n);
for i:=1 to n do read(fin, pct[i]);
readln(fin);
readln(fin, bonus);
readln(fin, m);
max:=0;
for j:=1 to m do
    begin

    complet:=true;
    crt:=0;

    for i:=1 to n do
        begin
        read(fin, p);
        if p=0 then complet:=false
        else crt:=crt+pct[i];
        end;
    readln(fin);

    if complet then crt:=crt+bonus;

    crt:=crt - 2*(j-1);

    if crt>max then max:=crt;
    end;

writeln(fout, max);
close(fin);
close(fout);
end.
