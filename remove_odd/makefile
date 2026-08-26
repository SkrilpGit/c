CFLAGS = -Wall -g -I../intList
LIBDIR = ../intList/


remove_odd: remove_odd.o intList.o
	gcc -o remove_odd.o intList.o

remove_odd.o: remove_odd.c
	gcc $(CFLAGS) -c remove_odd.c

intList.o: $(LIBDIR)int_list.c $(LIBDIR)int_list.h
	gcc $(CFLAGS) -c int_list.c
