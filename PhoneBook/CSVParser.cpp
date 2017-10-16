#include <sstream>
#include "CSVParser.hpp"

namespace CSVParser {

void split(const std::string &s, std::vector<std::string> &elems, char delim) {
    std::string temp;
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s[i] == delim) {
            elems.push_back(temp);
            temp.clear();
            if (i == s.size() - 1) {
                elems.push_back("");
            }
        } else {
            temp.push_back(s[i]);
            if (i == s.size() - 1) {
                elems.push_back(temp);
            }
        }
    }
}

void join(std::string &s, const std::vector<std::string> &elems, char delim) {
    for (auto elem : elems) {
        s.append(elem + delim);
    }
}

}
