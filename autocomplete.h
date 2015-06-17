#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>

#define MAX_LETTERS 37
#define ROOT_NODE_VALUE -1

using namespace std;

struct TrieNode {
	char value;
	char *word;
	bool end_word;
	struct TrieNode *nodes[MAX_LETTERS];
};

typedef struct TrieNode TrieNode;

class AutoComplete {
	public:
		AutoComplete();
		void addWord(const char *word);
		void getAutocomplete(const char *prefix, string & buf);
	private:
		int getIndex(char ch);
		void addWord_i(TrieNode **root, const char *word, int i);
		void visitTrie(TrieNode *root, string & buf);
		TrieNode *initializeTrie(void);
		TrieNode *root;
};
