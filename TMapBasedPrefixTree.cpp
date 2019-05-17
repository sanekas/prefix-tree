#include "IPrefixTree.h"
#include "TTrieNode.h"

class TMapBasedPrefixTree : public IPrefixTree {
private:
    TTrieNode root;
public:
    TMapBasedPrefixTree(): root('\0', "") {}

    TMapBasedPrefixTree(const std::vector<std::string> &dictionary): root('\0', "") {
        for (const auto& w: dictionary) {
            AddWord(w);
        }
    }

    bool AddWord(const std::string &word) override {
        TTrieNode* temp = &root;
        for (auto i = 0; i < word.length(); ++i) {
            auto descendants = temp->GetDescendants();
            auto pair = descendants.find(word[i]);
            if (pair != descendants.end()) {
                if (i == word.length() - 1) {
                    const auto& isWord = (pair->second).GetIsWord();
                    if (isWord) {
                        return false;
                    } else {
                        (pair->second).SetIsWord(true);
                        return true;
                    }
                }
                temp = &(pair->second);
            } else {
                TTrieNode newNode = TTrieNode(word[i], word.substr(i));
                temp->PutDescendadnt(word[i], newNode);
                temp = &newNode;
            }
        }
        return false;
    }

    bool Contains(const std::string &word) override {
        return false;
    }

    std::vector<std::string> Suggestions(const std::string &word) override {
        return std::vector<std::string>();
    }
};
