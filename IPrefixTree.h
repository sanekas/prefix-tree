#include <string>
#include <vector>

class IPrefixTree {
public:
    virtual bool AddWord(const std::string& word) = 0;
    virtual bool Contains(const std::string& word) = 0;
    virtual std::vector<std::string> Suggestions(const std::string& word) = 0;
    virtual ~IPrefixTree() = default;
};
