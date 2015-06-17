#include "autocomplete.h"

AutoComplete::AutoComplete() {
	root = initializeTrie();
}

int AutoComplete::getIndex(char ch) {
	char chars[] = "qwertyuiopasdfghjklzxcvbnm0123456789 ";
	int index;
	for(index = 0; index < strlen(chars);index++) {
		if(tolower(ch) == chars[index])
			return index;
	}

	return -1;
}

TrieNode *AutoComplete::initializeTrie(void) {
	TrieNode *root = (TrieNode *)malloc(sizeof(TrieNode));
	root->value = ROOT_NODE_VALUE;
	return root;
}

void AutoComplete::addWord_i(TrieNode **root, const char *word, int i) {
	int ch_next;

	if(i == strlen(word) - 1) {
		(*root)->end_word = true;
		(*root)->word = (char *)malloc(strlen(word) + 3);
		strcpy((*root)->word, word);
		return;
	}

	(*root)->end_word = false;
	(*root)->value = word[i];
	ch_next = getIndex(word[i + 1]);

	if((*root)->nodes[ch_next] == NULL) {
		(*root)->nodes[ch_next] = (TrieNode *)malloc(sizeof(TrieNode));
	}
	addWord_i(&(*root)->nodes[ch_next], word, i + 1);
}

void AutoComplete::addWord(const char *word) {
	int ch_i = getIndex(word[0]);
	if(root->nodes[ch_i] == NULL)
		root->nodes[ch_i] = (TrieNode *)malloc(sizeof(TrieNode));
	addWord_i(&root->nodes[ch_i], word, 0);
}

void AutoComplete::getAutocomplete(const char *prefix, string & buf) {
	int i, ch_i = getIndex(prefix[0]);
	TrieNode *start_node = root->nodes[ch_i];

	if(start_node == NULL)
		return;

	for(i = 1;i < strlen(prefix);i++) {
		ch_i = getIndex(prefix[i]);
		start_node = start_node->nodes[ch_i];
		if(start_node == NULL)
			return;
	}
	
	visitTrie(start_node, buf);
}

void AutoComplete::visitTrie(TrieNode *root, string & buf) {
	int i;

	if(root == NULL) 
		return;
	
	for(i = 0;i < MAX_LETTERS;i++) {
		if(root->nodes[i] != NULL) {
			visitTrie(root->nodes[i], buf);
		}
	}

	if(root->end_word) {	
		buf += root->word;
		buf += ";";
	}
	
}
