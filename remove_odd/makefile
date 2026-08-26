CFLAGS = -Wall -g -I../intList
LIBDIR = ../intList/
OBJS = int_list.o remove_odd.o


remove_odd: remove_odd.o int_list.o
	gcc -o remove_odd.o int_list.o

remove_odd.o: remove_odd.c
	gcc $(CFLAGS) -c remove_odd.c

int_list.o: $(LIBDIR)int_list.c $(LIBDIR)int_list.h
	gcc $(CFLAGS) -c $(LIBDIR)int_list.c

.PHONY: clean
clean:
	rm -f $(OBJS)
