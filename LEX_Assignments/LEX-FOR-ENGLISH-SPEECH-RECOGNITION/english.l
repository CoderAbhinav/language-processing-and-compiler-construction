%{
    #include "scanner_predef.h"
%}

%%

is |
am |
are |
were |
was |
be |
being |
been |
do |
does |
did  |
will |
would |
should |
can  |
could |
has  |
have |
had |
go          return VERB;

[a-zA-Z]+    return NOUN;
[ \t\n]     ;
[.]          return ENDOFSENTENCE;

%%

int yywrap(void) {
    return 1;
}