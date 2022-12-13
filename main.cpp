#include <iostream>
#include "CompilerConstructionUtilites/StringUtils/StringSplitUtlity.h"
#include "CompilerConstructionUtilites/TableBuilder/Table.h"
using namespace std;


int main(int argc, char const *argv[])
{
    string arr[] = {"A", "B", "C", "D"};
    vector<string> atb(arr, arr + 4);

    string rowA[] = {"1", "2", "3", "4"};
    vector<string> row(rowA, rowA + 4);

    reverse(atb.begin(), atb.end());
    Table t(atb);

    t.addRecord(row);

    vector<string> r = t.attributes();

    cout << t;
    return 0;
}
