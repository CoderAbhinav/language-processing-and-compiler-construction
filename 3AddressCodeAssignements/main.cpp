#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Splits an expression into tokens
 * 
 * @param exp 
 * @return std::vector<std::string> 
 */
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

                res.push_back(std::string(1, exp[i]));
            }

        } else {
            curr += exp[i];
        }

        i++;
    }

    return res;
}


/**
 * @brief returns the precedence of given operator
 * 
 * @param c 
 * @return int 
 */
int precedance(char c)
{
    if (c == '*' || c == '/')
        return 1;
    if (c == '+' || c == '-')
        return 2;
    return 0;
}

/**
 * @brief Compares two operator and returns one with higher precedence
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool compareOpr(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
        return true;
    else
        return false;
}


/**
 * @brief generates the output of 2 address code
 * 
 * @param exp 
 */
void generate3AddressCode(string exp)
{
    vector<string> tokens = splittedExpression(exp);
    vector<pair<int, int> > operator_list;

    // generate the operator entry table
    for (int i = 0; i < tokens.size(); i++)
    {
        if (precedance(tokens[i][0]) > 0)
        {
            operator_list.push_back(make_pair(precedance(tokens[i][0]), i));
        }
    }

    sort(operator_list.begin(), operator_list.end(), compareOpr);

    // printing the current operators
    for (int i = 0; i < operator_list.size(); i++)
    {

        // cout << operator_list[i].first << "\t" << operator_list[i].second << "\n";

        pair<int, int> curr = operator_list[i];

        string op1 = tokens[curr.second - 1], op2 = tokens[curr.second + 1];

        cout << "t" << (i + 1) << " = " << op1 << " " << tokens[curr.second] << " " << op2 << "\n";

        for (int j = 0; j < tokens.size(); j++) {
            if (tokens[j] == op1 || tokens[j] == op2) tokens[j] = "t" + to_string((i + 1));
        }

        tokens[curr.second] = "t" + to_string((i + 1));
    }
}

int main(int argc, char const *argv[])
{
    string exp2 = "a+b*c-d";
    cout << "Enter Expression:\n";
    cin >> exp2;
    // std::string exp = "a = b * - c + b * - c";

    generate3AddressCode(exp2);

    return 0;
}
