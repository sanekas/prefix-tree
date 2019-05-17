#include "TTrieNode.h"

std::unordered_map<char, TTrieNode> TTrieNode::GetDescendants() const {
    return descendants;
}

void TTrieNode::PutDescendadnt(const char& ch, const TTrieNode& node) {
    const auto& n = descendants.find(ch);
    if (n == descendants.end()) {
        descendants.insert({ch, node});
    }
}

const bool TTrieNode::GetIsWord() const {
    return isWord;
}

void TTrieNode::SetIsWord(const bool &isWord) {
    this->isWord = isWord;
}
