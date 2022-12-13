#include <stdio.h>
#include "english.h"

extern int state;
extern int yylex();
extern int yylineno;
extern char* yytext;


int main(int argc, char const *argv[])
{
    int ntoken, vtoken;

    // ntoken = yylex();

    while (state >= 0) {
        printf("%d\n", state);
        ntoken = yylex();
        printf("%d\n", ntoken);
        // printf("%d, %s\n", ntoken, yytext);
        // ntoken = yylex();
    }
    return 0;
}
