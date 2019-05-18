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
				|| ((ptr->wordEnd && i != word.length() - 1)
					&& !ptr->children[charToIndex(word[i + 1])])) { return false; }
		}
		return true;
	}


	void returnSuggestion(Node *node, std::string &suggestion,
						std::vector<std::string> &suggestions, const std::string &word) {
		for (int i = 0; i < SIZE; i++) {
			if (node->children[i] != nullptr) {
				suggestion.push_back((char)('a' + i));
				if (node->children[i]->wordEnd) {
					suggestions.push_back(suggestion);
				}
				returnSuggestion(node->children[i], suggestion, suggestions, word);
				suggestion.pop_back();
			}
		}
	}

	std::vector<std::string> Suggestions(const std::string& word) {
		Node *ptr;
		ptr = root;
		std::string suggestion;
		std::vector<std::string> suggestions;
		for (int i = 0; i < word.length() - 1; i++) {
			ptr = ptr->children[charToIndex(word[i])];
			if (!ptr) { return {""}; }
		}
		ptr = ptr->children[charToIndex(word[word.length() - 1])];
		if (!ptr || ptr->wordEnd) { return {""}; }
		suggestion += word;
		returnSuggestion(ptr, suggestion, suggestions, word);
		return suggestions;
	}

	~Trie() override { delete root; }
};

int main() {
	Trie trie;
	trie.AddWord("kdlfnh");
	trie.AddWord("kdlfnn");
	trie.AddWord("vasyka");
	//std::cout << trie.Contains("vasyka");
	std::vector<std::string> suggestions = trie.Suggestions("");
	for (const auto &item : suggestions) {
		std::cout << item << std::endl;
	}
	return 0;
}