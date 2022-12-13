#pragma once
#include <string>
#include <unordered_set>
#include <vector>

#define stringVector std::vector<std::string>
#define charSet std::unordered_set<char>
#define charVector std::vector<char>

/**
 * @brief The function separates the line with given separators
 * 
 * @param original string
 * @param separator iterable string
 * @return stringVector 
 */
stringVector split(std::string original, charVector separator) {
    stringVector res;
    charSet sep_set(separator.begin(), separator.end());

    int i = 0, n = original.size();  

    std::string curr = "";

    while (i < n) {
        if (sep_set.find(original[i]) != sep_set.end()) {
            if (curr.length() != 0) {
                res.push_back(curr);
                curr = "";
            }
        } else {
            curr += original[i];
        }

        i++;
    }

    return res;
}

/**
 * @brief The function separates the line with given separators
 * 
 * @param original string
 * @param separator iterable string
 * @return stringVector 
 */
stringVector split(std::string original, char *seperators) {
    // find length of char map
    int n = 0; char* temp = seperators; while (temp != nullptr) {n++; temp++;}
    charVector v = charVector(seperators, seperators + n);
    return split(original, v);
}



/**
 * @brief The function separates the line with given separators
 * 
 * @param original string
 * @param seperator char
 * @return stringVector 
 */
stringVector splitSingle(std::string original, char seperator) {
    char separators[] = {seperator};
    return split(original, separators);
}