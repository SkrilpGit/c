int_hash_table_test: int_hash_table.o int_hash_table_test.o
	gcc -o ./bin/int_hash_table_test int_hash_table.o int_hash_table_test.o

int_hash_table.o: int_hash_table.c
	gcc -c int_hash_table.c

int_hash_table_test.o: int_hash_table_test.c
	gcc -c int_hash_table_test.c

debug: int_hash_table.o
	gcc -o ./bin/debug int_hash_table.o

.PHONY: clean
clean:
	rm -f ./bin/*
