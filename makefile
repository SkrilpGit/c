run:
	gcc "cel_to_fahr.c" -o ./bin/cel_to_fahr
	gcc "fahrenheit_to_celsius.c" -o ./bin/fahrenheit_to_celsius
	gcc "hello_world.c" -o ./bin/hello_world
	gcc "in_to_out_chars.c" -o ./bin/in_to_out_chars
	gcc "deci_binary.c" -o ./bin/deci_binary
	gcc "sort_int_by_bits.c" -o ./bin/sort_int_by_bits
clean:
	rm -rf ./bin/cel_to_fahr
	rm -rf ./bin/fahrenheit_to_celsius
	rm -rf ./bin/hello_world
	rm -rf ./bin/in_to_out_chars
	rm -rf ./bin/deci_binary
	rm -rf ./bin/sort_int_by_bits
