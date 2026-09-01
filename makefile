OUT = ./bin/
SCRIPTS = ptr_test

run: $(SCRIPTS)
	gcc cel_to_fahr.c -o $(OUT)cel_to_fahr
	gcc fahrenheit_to_celsius.c -o $(OUT)fahrenheit_to_celsius
	gcc hello_world.c -o $(OUT)hello_world
	gcc in_to_out_chars.c -o $(OUT)in_to_out_chars
	gcc deci_binary.c -o $(OUT)deci_binary
	gcc sort_int_by_bits.c -o $(OUT)sort_int_by_bits

ptr_test: ptr_test.o
	gcc -o $(OUT)ptr_test ptr_test.o
ptr_test.o: ptr_test.c
	gcc -c ptr_test.c -o ptr_test.o

.PHONY: clean
clean:
	rm $(OUT)*
