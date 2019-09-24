DEPS = heap.h
OBJ = heap.o


all: main

main: $(OBJ)
	gcc -g3 $^ main.c -o $@

%.o: %.c $(DEPS)
	gcc -c -g3 $< -o $@

memcheck: main
	valgrind --tool=memcheck --leak-check=full --log-file=main_memcheck.log ./main

massif: main
	valgrind --tool=massif --log-file=main_massif.log ./main
    #use ms_print filename
clean: 
	rm -rf *o
	rm -rf *out
	rm -rf *log