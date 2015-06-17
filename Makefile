clean:
	rm *.o
	rm main
build:
	g++ autocomplete.cpp -g -c -o autocomplete.o
	g++ cli.cpp -g -o cli autocomplete.o
	rm autocomplete.o