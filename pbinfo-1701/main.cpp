program CS_birouri;
var
	n, m, k, c, niv, b, p : longint;
	fin, fout:text;
begin
	assign(fin, 'birouri.in');
	assign(fout,'birouri.out');
	reset(fin); rewrite(fout);
    	readln(fin, c, n);
	m:=n;
    	repeat

        	inc(niv);
        	if niv mod 2 = 1 then
            		b := b + n * m
        	else begin
			if n > m then k := m
				 else k := n;
            		p := k * k div 2 - k;
			b := b + p;
            		if p = 0 then dec(niv);
            		if k mod 4 = 0 then begin
				k := k div 2;
				n := k; m := k
			end
                	else begin
				n := n div 2 - 1; m := n + 2
			end
        	end;
    	until not((n <> 0) and (n mod 2 = 0));
    	if c=1 then
        	writeln(fout, niv)
    	else
        	writeln(fout, b);
 	close(fin); close(fout);
end.
