        START   101
        READ    N
        MOVER   BREG, ONE
        MOVEM   BREG, TERM //ALGORITHM this is a comment
AGAIN   MULT    BREG, TERM // ABHINAV
        MOVER   CREG, TERM
        ADD     CREG, ONE
        MOVEM   CREG, TERM
        COMP    CREG, N
        BC      LE, AGAIN
        MOVEM   BREG, RESULT
        PRINT   RESULT
        STOP

N       DS      1
RESULT  DS      1
ONE     DC      '1'
TERM    DS      1
        END