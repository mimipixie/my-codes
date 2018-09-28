// lab 1

loves(romeo,juliet).
loves(juliet,romeo):-loves(romeo,juliet).
male(albert).
male(bob).
male(bill).
male(carl).
male(charlie).
male(don).
male(edward).

female(alice).
female(betsy).
female(diana).

happy(albert).
happy(alice).
happy(bob).
happy(bill).
with_albert(alice).

runs(albert):-
happy(albert).

dances(alice):-
  happy(alice),
  with_albert(alice).

does_bob_dance:-dances(alice),
      write('When Alice is happy and with Albert she dances').

near_water(bob).

swims(bob):-
    happy(bob),
    near_water(bob).

// lab 2
parent(albert,bob).
parent(albert,betsy).
parent(albert,bill).

parent(alice,bob).
parent(alice,betsy).
parent(alice,bill).

parent(bob,carl).
parent(bob,charlie).

get_grandchild:-
     parent(albert,X),
     parent(X,Y),
     write('Alberts grandchild is '),
     write(Y),nl.
get_parent:-
     parent(X,carl),
     parent(X,charlie),
     format('~w ~s parent ~n',[X, "is the"]).
brother(bob,bill).

// lab 3

grand_parent(X,Y):-
           parent(Z,X),
            parent(Y,Z).
what_grade(5):-
     write('Go to kindergarten').
what_grade(6):-
     write('Go to first grade').
what_grade(Other):-
     Grade is Other-5,
     format('Go to grade~w',[Grade]).
owns(albert,pet(cat,olive)).
customer(tom,smith,20.55).
customer(sally,smith,120.55).

get_cust_bal(FName,LName):-customer(FName,LName,Bal),
   write(FName),tab(1),
   format('~w owes us $~2f~n',[LName,Bal]).

// lab 4

get_max(X,Y,Z):-
 P is max(X,Y),
 Q is max(P,Z),
 write(Q),nl.


fac(N):-
	F=1,
	get_fact(N,F).

get_fact(0,F):-
    	write(F),nl.
get_fact(N,F):-
        N =\= 0,
	P is N-1,
	Q is F*N,
	get_fact(P,Q).
    

f:-
        write('Enter a non-negative number : '),
        read(N),nl,
        R is 1,
        fact(N,R).		// initial func

fact(N,R):-
        N =\= 0,
        P is N * R,
        Q is N - 1,
        fact(Q,P).		// main part
        

fact(0,R):-
	write('Factorial = '),
	write(R),nl.		// ending  //// loop end  --> " fact(0,R). "  
				//// " fact(0,R). "  where it indicates or initializes that the stmt is true

// lab extra

m:-
write('start of m'),nl,nl,

50 > 30, 30< 50,
50 >= 30, 30 <=50,

X is 15/2,  	// X=7.5
X is 15//2,	// X=7 (only int part)

3 =:= 3,	// true if equal
5 =\= 3,	// true if not equal

\+ (5 = 10),	// true if not equal (same work with string)

X = 2,
Y is X+2,	
		//// one variable value cannot be changed more than once in one function
		//// use another variable for X is X+2 like Y is X+2
		//// '=' only assigns the number or string from its left (no mathematical operation)
		//// 'is' is used for mathematical operation and assignment operation both
write(X),nl,
write(Y),nl,nl,
P = 4 ,
Q = P ,
write(P),nl,
write(Q),nl,nl,
R=ghxhjb,
S=gdcsu+P+X,
T='Agvhb+P',

write(R),nl,nl,
write(S),nl,nl,
write(T),nl,nl,

write('end of m'),nl.




even(X) :- Y is X//2,
 X =:= 2 * Y.


ff:-
15 > 100 ; 10 < 10.  	// true if either one is true


test :- write('Type the word : '),
 read(word),
 write('Input was '),
 write(word), nl,
 (word=end; test).	// loop

     



double_digit(X,Y) :-		// tells the value of Y
Y is X*2.


random(0,10,X). 	// Get random value between 0 and 10

between(0,10,X).	// Get all values between 0 and 10

succ(1,X). 		// Add 1 and assign it to X (X=X+1)

X is abs(-8).		// Get absolute value of -8 (8)

X is max(10,5).		// Get largest value

X is min(10,5).		// Get smallest value

X is round(10.56).	// Round a value (11)

X is truncate(10.56). 	// Convert float to integer (10)

X is floor(10.56).	// Round down (10)

X is ceiling(10.56).	// Round up (11)

X is 2** 3.		// 2^3

sqrt, sin, cos, tan, asin, acos, atan, atan2, sinh, cosh, tanh,
asinh, acosh, atanh, log, log10, exp, pi, e



// lab loop if..else recursion


grade:-

write('Enter marks : '),
read(M),
(
   ( M>100;M<0) ->
	(
	 format('invalid input'),nl,
	 format('input again'),nl
	);
   ( 33=<M , 100>=M) ->
	(
	 format('passed'),nl,
	 format('congrtz'),nl
	);
   %( 0=<M , 32>=M) ->
	(
	 format('failed'),nl,
	 format('boo'),nl
	)



).


loop:-
	repeat,
	(
		between(1,10,I),
		write(I),
		write(' : hi'),nl
	),
	(
		I==10 %condition for break
	).


loop1(0).
loop1(X):-
Y is X-1,
loop1(Y),
write('Enter marks : '),
read(M),
(
   ( M>100;M<0) ->
	(
	 format('invalid input'),nl,
	 format('input again'),nl
	);
   ( 33=<M , 100>=M) ->
	(
	 format('passed'),nl,
	 format('congrtz'),nl
	);
   %( 0=<M , 32>=M) ->
	(
	 format('failed'),nl,
	 format('boo'),nl
	)



).


marks:-
write('Enter no of students : '),read(X),
loop1(X).


loopp(X,0,0):-
write('Prime').


loopp(X,Z,1):-
write('Not Prime'),nl.

loopp(X,Z,P):-
A is mod(X,Z),

(
	(A==0)->(Q is 1);(Q is 0)
),
Y is Z-1,
loopp(X,Y,Q).


prime:-
write('Enter a number : '),read(X),
Z is X-1,
loopp(X,Z,0).





