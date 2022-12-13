#include <stdio.h>
#include "scanner_predef.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


int main(int argc, char const *argv[])
{
    int ntoken, vtoken;

    ntoken = yylex();

    while (ntoken) {
        printf("%d, %s\n", ntoken, yytext);
        ntoken = yylex();
    }
    return 0;
}
