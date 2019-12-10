l1: r <=  '0' when(a =  '0' and b =  '0' and cin =    '0') else 
			 '1' when(a =  '0' and b =  '0' and cin =    '1') else
			 '1' when(a =  '0' and b =  '1' and cin =    '0') else
			 '0' when(a =  '0' and b =  '1' and cin =    '1') else
			 '1' when(a =  '1' and b =  '0' and cin =    '0') else
			 '0' when(a =  '1' and b =  '0' and cin =    '1') else
			 '0' when(a =  '1' and b =  '1' and cin =    '0') else
			 '1';
l2:cout<= '0' when(a =  '0' and b =  '0' and cin =    '0') else
			 '0' when(a =  '0' and b =  '0' and cin =    '1') else
			 '0' when(a =  '0' and b =  '1' and cin =    '0') else
			 '1' when(a =  '0' and b =  '1' and cin =    '1') else
			 '0' when(a =  '1' and b =  '0' and cin =    '0') else
			 '1' when(a =  '1' and b =  '0' and cin =    '1') else
			 '1' when(a =  '1' and b =  '1' and cin =    '0') else
			 '1';



	component mxor2
		port
			(a1, a2: in bit;
			c: out bit);
		end component;
	component mand2
		port
			(a1, a2: in bit;
			c: out bit);
	end component;
	component mor3
		port
			(a1, a2, a3: in bit;
			c: out bit);
	end component;
	Signal t1, t2, t3, t4 : bit;
begin
	p1: mxor2 port map(a, b, t1);
	p2: mxor2 port map(t1, cin, r);
	p3: mand2 port map(a, b, t2);
	p4: mand2 port map(a, cin, t3);
	p5: mand2 port map(b, cin, t4);
	p6: mor3 port map(t2, t3, t4, cout);
