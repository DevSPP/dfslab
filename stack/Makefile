
DEPS = stack.h
OBJ = stack.o

all: main gdb

main: $(OBJ)
	gcc -g3 $^ main.c -o $@

%.o: %.c $(DEPS)
	gcc -c -g3 $< -o $@

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





