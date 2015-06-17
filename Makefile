clean:
	rm *.o
	rm cli
build:
	g++ autocomplete.cpp -g -c -o autocomplete.o
	g++ cli.cpp -g -o cli autocomplete.o
	rm autocomplete.o
