    START   100
A   DS      1
L1  LOAD    B
    ADD     C
    STORE   D
D   EQU     A
L2  PRINT   D
    ORIGIN  A
C   DC      5
    ORIGIN  L2
    STOP
B   DC      ’19’
    END