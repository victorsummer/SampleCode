#pragma once

#include <vector>
#include <string>
#include <functional>
#include <type_traits>

namespace PhoneAlgorithm {

template <typename T>
void split(const T &s, std::vector<T> &elems, typename T::value_type delim) noexcept {
    T temp;
    for (size_t i = 0; i < s.size(); ++i) {
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

template <typename T>
void join(T &s, const std::vector<T> &elems, typename T::value_type delim) noexcept {
    for (auto elem : elems) {
        s.append(elem + delim);
    }
}

}
