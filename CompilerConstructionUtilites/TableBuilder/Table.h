#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define TableMatrix std::unordered_map<std::string, std::vector<std::string> >
#define StringVector std::vector<std::string>
#define Row std::unordered_map<std::string, std::string>

/**
 * @brief this class provides functionality for manipulating the tables
 * 
 */
class Table
{
private:
    TableMatrix table;
    std::unordered_map<std::string, int> unique_key;
    std::string unique_key_attribute;

public:

    Table(StringVector);

    void addRecord(StringVector);
    void addRecord(std::string*);    
    
    Row get(std::string);
    Row get(int);

    StringVector attributes();
    int size();

    bool createUniqueKeyOnAttribute(std::string attribute, bool);
    ~Table();


    friend std::ostream& operator<<(std::ostream&, Table&);
};

/**
 * @brief Construct a new Table:: Table object
 * 
 * @param attributes 
 */
Table::Table(std::vector<std::string> attributes)
{
    int n = attributes.size();
    for (int i = 0; i < n; i++) table[attributes[i]] = StringVector();

    unique_key_attribute = "";
}


/**
 * @brief adds new row to the table
 * 
 * @param row 
 */
void Table::addRecord(StringVector row) {
    if (row.size() < table.size()) {
        throw std::invalid_argument("Incorrect attributes provided (count is less)");
    }
    int i = 0;
    for (TableMatrix::iterator itr = table.begin(); itr != table.end(); itr++) {
        (*itr).second.push_back(row[i]);
        i++;
    }

    createUniqueKeyOnAttribute(unique_key_attribute, false);
}

/**
 * @brief adds new row to the table
 * 
 * @param row 
 */
void Table::addRecord(std::string row[])  {
    StringVector row_in_vector;

    std::string* curr = row;

    while (curr != nullptr) {
        row_in_vector.push_back(*curr);
    }

    return addRecord(row_in_vector);
}

/**
 * @brief returns table entry if given key
 * 
 * @param key key for the row
 * @return std::unordered_map<std::string, std::string> 
 */
Row Table::get(std::string key) {
    Row res;
    if (unique_key_attribute != "" && unique_key.find(key) != unique_key.end()) {
        
        for (
            TableMatrix::iterator itr = table.begin();
            itr != table.end();
            itr++
        ) {
            res[(*itr).first] = (*itr).second[unique_key[key]];
        }

        return res;
    }

    return res;
}

/**
 * @brief returns row at given index
 * 
 * @param index 
 * @return std::unordered_map<std::string, std::string> 
 */
Row Table::get(int index) {
    Row res;
    if (index >= (*(table.begin())).second.size()) {
        return res;
    }

    
    for (
        TableMatrix::iterator itr = table.begin();
        itr != table.end();
        itr++
    ) {
        res[(*itr).first] = (*itr).second[index];
    }

    return res;
}

/**
 * @brief returns the attributes of the table or column names
 * 
 * @return StringVector 
 */
StringVector Table::attributes() {
    StringVector res;

    for (TableMatrix::iterator itr = table.begin();
        itr != table.end(); 
        itr++) {
            res.push_back((*itr).first);
    }

    return res;
}

/**
 * @brief returns the number of entries in table
 * 
 * @return int 
 */
int Table::size() {
    return (*(table.begin())).second.size();
}

/**
 * @brief creates unique key if exist can inPlace if requested
 * 
 * @param attribute the column name
 * @param inPlace
 * @return true 
 * @return false 
 */
bool Table::createUniqueKeyOnAttribute(std::string attribute, bool inPlace = false) {
    if (table.find(attribute) != table.end() && (unique_key_attribute == "" || inPlace == true)) {
        
        unique_key_attribute = attribute;
        unique_key = std::unordered_map<std::string, int>();

        int n = table[attribute].size();

        for (int i = 0; i < n; i++) {
            unique_key[table[attribute][i]] = i;
        }
    }

    return false;
}

Table::~Table()
{
}


std::ostream& operator<<(std::ostream& os, Table& table) {
    for (TableMatrix::iterator itr = table.table.begin(); 
        itr != table.table.end(); 
        itr++) {

            os << (*itr).first << "\t";
    }

    os << "\n";

    for (int i = 0; i < table.size(); i++) {
        for (TableMatrix::iterator itr = table.table.begin(); 
        itr != table.table.end(); 
        itr++) {

            os << (*itr).second[i] << "\t";
    }
    }

    return os;
}