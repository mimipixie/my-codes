startTouristGuide:-
	N is 0,
	u_file('users.txt',N).
	
	
bb:-
	read(X),
	write(X),nl.
	
chh:-
	write('Done').



f:-
        write('Enter a non-negative number : '),
        read(N),nl,
        R is 1,
        fact(N,R,M),		
	write('Factorial = '),
	write(R),nl,		
	write(M),nl.		

fact(N,R,M):-
        N =\= 0,
        P is N * R,
        Q is N - 1,
		M is 0,
        fact(Q,P,M).		
        

fact(0,R,M).
	
    start:-
        openread(xinput,"data.txt"),
        readdevice(xinput),
        reading(1).

		
    reading(LineNo):-
        not(eof(xinput)),
        readline(Line),
        write(LineNo," ",Line),nl,
        LL = LineNo + 1,
        reading(LL).

    reading(_):-
        write("\nEnter Line No = "),
        readdevice(keyboard),
        readint(LineNo),
        filepos(xinput,0,0),
        readdevice(xinput),
        searching(LineNo,1).
        
    searching(LineNo,Num):-
        not(eof(xinput)),
        LineNo =\= Num,
        readln(Line),
        NN = Num + 1,
        searching(LineNo,NN).
        
    searching(LineNo,Num):-
        not(eof(xinput)),
        readln(Line),
        closefile(xinput),
        openwrite(xinput,"Outputq6.txt"),
        writedevice(xinput),
        write(Line),nl,
        closefile(xinput),
        write("See file outputq6.txt").
        
    searching(LineNo,Num):-
        write("Enter line no. is outof file"),nl.




		
k(File):-
	open(File,read,Str), 
    read(Str,House1), 
    read(Str,House2), 
    read(Str,House3), 
    read(Str,House4), 
    close(Str), 
    write([House1,House2,House3,House4]),nl.
	
	
main :-
    open('myFile.txt', read, Str),
    read_file(Str,Lines),
    close(Str),
    write(Lines), nl.

read_file(Stream,[]) :-
    at_end_of_stream(Stream).

read_file(Stream,[X|L]) :-
    \+ at_end_of_stream(Stream),
    read(Stream,X),
    read_file(Stream,L).
	
	
main :-
    open('data.txt', read, Str),
    read_file(Str,Lines),
    close(Str).

read_file(Stream,Lines) :-
    at_end_of_stream(Stream).

read_file(Stream,Lines) :-
    \+ at_end_of_stream(Stream),
    readWord(Stream,Lines),
    write(Lines), nl,
    read_file(Stream,L).
	
readWord(InStream,W):- 
         get_code(InStream,Char), 
         checkCharAndReadRest(Char,Chars,InStream), 
         atom_codes(W,Chars). 
    
    
   checkCharAndReadRest(10,[],_):-  !. 
    
    
   checkCharAndReadRest(-1,[],_):-  !. 
    
   checkCharAndReadRest(end_of_file,[],_):-  !. 
    
   checkCharAndReadRest(Char,[Char|Chars],InStream):- 
         get_code(InStream,NextChar), 
         checkCharAndReadRest(NextChar,Chars,InStream).