#include <unordered_map>
#include <string>

class TTrieNode {
private:
    const char ch;
    const std::string charPath;

    bool isWord;
    std::unordered_map<char, TTrieNode> descendants;

public:
    TTrieNode(const char& ch, const std::string& charPath) : ch(ch), charPath(charPath), isWord(false) {}
    std::unordered_map<char, TTrieNode> GetDescendants() const;
    void PutDescendadnt(const char& ch, const TTrieNode& node);
    const bool GetIsWord() const;
    void SetIsWord(const bool& isWord);
};
