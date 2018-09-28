userWindow:-
	write('Are you new here? ( (Type y/n/exitwindow) '),nl,
	read(X),
	member_login(X).

member_login(exitwindow).

member_login(y):-
	write('Please enter user information :- '),nl,nl,
	write('Username : '),read(U),nl,
	write('Password : '),read(P),nl,
	read_from_userfile('username.txt',U,P,0,0,0,0,1).

member_login(n):-
	write('Please login with username and password :- '),nl,nl,
	write('Username : '),read(U),nl,
	write('Password : '),read(P),nl,
	read_from_userfile('username.txt',U,P,0,0,0,0,0).
	
member_login(X):-
	write('Invalid input. Please type again.'),nl,nl,
	userWindow.

read_from_userfile(File,U,P,A,B,C,D,Z):-
    open(File, read, Str),
    read_file(Str,Lines,U,P,A,B,C,D,Z),
    close(Str).
										
read_file(Stream,Lines,U,P,A,B,C,D,Z):-
    at_end_of_stream(Stream),
	notMatched(U,P,A,Q,C,D,Z).
										
read_file(Stream,Lines,U,P,A,B,C,D,Z):-
    \+ at_end_of_stream(Stream),
(

    ( (A=:=0) ; (\+ (B = A))) ->
	(
		readLine(Stream,Lines),
		Q is B+1,
		(

			( (\+ (Lines = U))) ->
			(
				read_file(Stream,L,U,P,A,Q,C,D,Z)
			);
			( 
				( (Q =:= A) ; (D =:= 0) ) ->
				(
					matched(U,P,A,Q,1,D,Z)
				);
				(
					read_file(Stream,L,U,P,A,Q,C,D,Z)
				)
			)
		)
	);
	(
		notMatched(U,P,A,Q,C,D,Z)
	)
).

readLine(InStream,W):- 
    get_code(InStream,Char), 
    readC(Char,Chars,InStream), 
    atom_codes(W,Chars). 
    
    
readC(10,[],_):-  !. 
    
readC(32,[],_):-  !. 

readC(-1,[],_):-  !. 
    
readC(end_of_file,[],_):-  !. 
    
readC(Char,[Char|Chars],InStream):- 
	get_code(InStream,NextChar), 
	readC(NextChar,Chars,InStream).
		 
write_to_file(File,Text):-
	open(File,append,Stream), 
	write(Stream,Text),nl(Stream), 
	close(Stream).

u_file(File,Text):-
	open(File,write,Stream),
	write(Stream,Text),
	close(Stream).
	 
logged_in(U):-
	write('Welcome '),write(U),nl.
	
matched(U,P,A,B,C,D,0):-
(

    ( (D =:= 0)) ->
	(
		read_from_userfile('password.txt',P,U,B,0,D,C,Z)	
	);
    ( (D =:= 1),(C =:= 1) ) ->
	(
		logged_in(P)
	)
).

matched(U,P,A,B,C,D,1):-
	write('This username already exists. Please try another one.'),nl,nl,
	member_login(y).
	
notMatched(U,P,A,B,C,D,0):-
(
	( (D =:= 0) , (A =:= 0) ) ->
	(
		write('invalid username. Please try again.'),nl,nl,
		userWindow
	);
	( (D =:= 1) ) ->
	(
		write('password incorrect. Please try again.'),nl,nl,
		userWindow
	)
).

notMatched(U,P,A,B,C,D,1):-
	write_to_file('username.txt',U),
	write_to_file('password.txt',P),
	atomic_concat(U,'.txt',Z),
	write_to_file(Z,''),
	write('New account created.'),nl,nl,
	member_login(n).
	



	
	
	
	
	
	
	
