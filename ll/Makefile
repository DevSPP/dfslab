all: main gdb

main: main.c ll.o
	gcc -Wall -g3 ll.o main.c -o main

ll.o: ll.c
	gcc -c -Wall -g3 ll.c -o ll.o

memcheck: main
	valgrind --tool=memcheck --leak-check=full --log-file=main_memcheck.log ./main

massif: main
	rm -rf *.out.*
	valgrind --tool=massif --log-file=main_massif.log ./main
	ms_print ./massif.out.*

gdb: main
	gdb -iex 'add-auto-load-safe-path .' ./main


clean: 
	rm -rf *o
	rm -rf *out
	rm -rf *log