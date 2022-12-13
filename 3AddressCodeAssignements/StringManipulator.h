#pragma onces
#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> splittedExpression(std::string exp) {
    exp += " ";
    int i = 0, n = exp.length();
    std::vector<std::string> res;

    std::string curr = "";

    while (i < n) {
        if (exp[i] == ' ' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '=') {
            
            if (curr.length() > 0) res.push_back(curr);
            curr = "";

            

            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '=') {
                // string sym = exp[i] + "";
                res.push_back(std::string(1, exp[i]));
            }

        } else {
            curr += exp[i];
        }

        i++;
    }

    return res;
}
