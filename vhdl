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
