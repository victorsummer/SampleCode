#pragma once

#include <vector>
#include <string>
#include <functional>

namespace CSVParser {

void split(const std::string &s, std::vector<std::string> &elems, char delim = '\n');
void join(std::string &s, const std::vector<std::string> &elems, char delim = ',');

}
