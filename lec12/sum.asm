.ORIG x3000
; init R6 and R5
    LD R6, STACK_TOP
    ADD R5, R6, #0
; push argument
    ADD R6, R6, #-1
    AND R0, R0, #0
    ADD R0, R0, #3
    STR R0, R6, #0
; call subroutine x = sum(3);
    JSR SUM
; pop return value from run-time stack (to R0) 
    LDR R0, R6, #0
    ADD R6, R6, #-2
    STR R0, R5, #0
    HALT

SUM
; push callee’s bookkeeping info onto the run-time stack
; allocate space in the run-time stack for return value
    ADD R6, R6, #-1
; store caller’s return address  
    ADD R6, R6, #-1
    STR R7, R6, #0
; store caller's frame pointer
    ADD R6, R6, #-1
    STR R5, R6, #0
; allocate memory for local variable fn
    ADD R6, R6, #-1
    ADD R5, R6, 0
; if (n<=1)
    LDR R1, R5, #4
    ADD R2, R1, #-1 ; R2 = n-1
    BRnz BASE 
; compute  n + sum(n-1)
; caller-built stack for sum(n-1) function call 
; push n-1 onto run-time stack
    ADD R6, R6, #-1
    STR R2, R6, #0 ; R2 = n-1
; call sum subroutine
    JSR SUM
; pop return value from run-time stack (R0 = sum(n-1)) 
    LDR R0, R6, #0
    ADD R6, R6, #1
; pop function argument from the run-time stack 
    ADD R6, R6, #1
; add n by the return value (n+sum(n-1))  
    LDR R1, R5, #4
    ADD R0, R0, R1
; store result in local var 
    STR R0, R5, #0
; done with this branch
    BRnzp RETURN
BASE
; store value of 1 in local var 
    AND R2, R2, #0
    ADD R2, R2, #1
    STR R2, R5, #0
; tear down the run-time stack and return
RETURN
; write return value from local var 
    LDR R0, R5, #0
    STR R0, R5, #3
; pop local variable(s) from the run-time stack
    ADD R6, R6, #1
; restore caller’s frame pointer and return address 
    LDR R5, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
; return control to the caller function
    RET

STACK_TOP           .FILL x4000
.END
