.ORIG x3000

AND     R7, R7, #0
ADD     R7, R7, #1
ST      R7, SAVE_R7
JSR     FOO
LD      R7, SAVE_R7
HALT

FOO
        ST  R7, SAVE_R7_FOO
        ;pretend using R7 for something
        AND R7, R7, #0
        ;
        LD  R7, SAVE_R7_FOO
        RET
SAVE_R7_FOO .FILL   #0
SAVE_R7 .FILL   #0
.END
