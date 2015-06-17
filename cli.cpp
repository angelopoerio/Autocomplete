#include "autocomplete.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	AutoComplete ac;
	ifstream infile; 
	string ac_output;
	string line, input_line;
	int loaded_words = 0;

	if(argc < 2) {
		cout << "Use: " << argv[0] << " input_file" << std::endl;
		return 1;
	}

	infile.open(argv[1]);

	if(!infile) {
		cout << "could not open the file" << std::endl;
		return 1;
	}

   	while(!infile.eof())
	{
    		infile >> line;
		ac.addWord(line.c_str());
		loaded_words++;
	}

	cout << "loaded words: " << loaded_words << std::endl; 
	
	while(true) {
		cout << ">";
		cin >> input_line;
		ac.getAutocomplete(input_line.c_str(), ac_output);
		cout << ac_output << std::endl;
		ac_output = "";
	}

	return 0;
}
