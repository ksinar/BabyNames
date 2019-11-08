all: babyQuery babiesQuery

abyQuery:
	gcc -ansi -c -Wall removeCommas.c
	gcc -ansi -Wall -o babyQuery babyQuery.c removeCommas.o

babiesQuery:
	gcc -ansi -c -Wall removeCommas.c
	gcc -ansi -Wall -o babiesQuery babiesQuery.c removeCommas.o

runbaby: 
	./babyQuery

runbabies:
	./babiesQuery

clean: 
	rm *.o babyQuery babiesQuery

