%{
enum {
      LOOKUP = 0,
      TEXT = 1,
      INTEGER = 2,
      SYMBOL = 3
};

int state = LOOKUP;

%}

%%

[0-9]+      {     printf("INTEGER\n");    }
[a-zA-Z]+   {     printf("TEXT\n");       }
[ \n\t]     ;
[.,+-]      {     printf("SYMBOL\n");     }

%%

int yywrap(void) {
    return state;
}