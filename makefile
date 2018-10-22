all: driver.o library.o cllist.o
	gcc -o out driver.o library.o cllist.o

driver.o: driver.c library.h cllist.h
	gcc -c driver.c

library.o: library.c cllist.h
	gcc -c library.c

cllist.o: cllist.c
	gcc -c cllist.c

run:
	./out

clean:
	rm out
	rm *.o
