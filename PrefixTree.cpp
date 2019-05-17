#include <iostream>
#include "PrefixTree.h"
#include "NodeArray.h"

class Trie : public PrefixTree {
public:
	Node *root;
	Trie() {
		root = new Node;
		root->wordEnd = true;
	}
	int charToIndex(char c) {
		return (int)c - 97;
	}
	bool AddWord(const std::string& word) override {
		Node *ptr;
		ptr = root;
		for (const char &c : word) {
			if (ptr->wordEnd || !ptr->children[charToIndex(c)]) {
				ptr->wordEnd = false;
				ptr->children[charToIndex(c)] = new Node;
				ptr = ptr->children[charToIndex(c)];
				ptr->wordEnd = true;
			} else {
				ptr = ptr->children[charToIndex(c)];
			}
		}
		ptr->wordEnd= true;
		return true;
	}

	bool Contains(const std::string& word) override {
		Node *ptr;
		ptr = root;
		for (int i = 0; i < word.length(); i++) {
			ptr = ptr->children[charToIndex(word[i])];
			if (!ptr || (!ptr->wordEnd && i == word.length() - 1)
				|| (ptr->wordEnd && i != word.length() - 1)
					&& !ptr->children[charToIndex(word[i + 1])]) { return false; }
		}
		return true;
	}
	/*
	void returnSuggestion(Node *node, std::string &suggestion) {
		for (const auto &child : node->children) {
			if (child != nullptr) {
				returnSuggestion(child, suggestion);
				suggestion.push_back()
			}
		}
	}*/

	std::vector<std::string> Suggestions(const std::string& word) {
		Node *ptr;
		ptr = root;
		std::vector<std::string> suggestions;
		for (const char &c : word) {
			ptr = ptr->children[charToIndex(c)];
			if (!ptr) { return {nullptr}; }
		}
		if (ptr->wordEnd) { return {nullptr}; }
		for (const auto &child : ptr->children) {
			Node *newPtr = ptr;

		}
	}

	~Trie() { delete root; }
};

int main() {
	Trie trie;
	trie.AddWord("kdlfnh");
	trie.AddWord("kdlnh");
	trie.AddWord("vasyka");
	std::cout << trie.Contains("vasyk");
	return 0;
}