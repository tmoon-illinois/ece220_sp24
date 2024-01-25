.ORIG x3000


LOOP
GETC
OUT
JSR PUSH
ADD   R5, R5, #0
BRp   PUSH_FAIL
BRnzp LOOP

PUSH_FAIL
HALT

;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
ST	R3, SAVE_R3
ST	R6, SAVE_R6
LD	R3, STACK_END
LD	R6, STACK_TOP
AND	R5, R5, #0

;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
ADD	R3, R3, #-1	; STACK_END – 1
NOT	R3, R3
ADD	R3, R3, #1	;- (STACK_END - 1) bc 2’scomp
ADD	R3, R6, R3	; STACK_TOP - (STACK_END - 1)
BRz	OVERFLOW

;it is NOT overflow
STR	R0, R6, #0
ADD	R6, R6, #-1
ST	R6, STACK_TOP
BR	DONE_PUSH

;it is overflow
OVERFLOW
ADD	R5, R5, #1
;restore registers
DONE_PUSH
LD	R3, SAVE_R3
LD	R6, SAVE_R6
RET


STACK_END       .FILL   x3FFD
STACK_START     .FILL   x3FFD
STACK_TOP       .FILL   x3FFD
SAVE_R3         .FILL    x0
SAVE_R6         .FILL    x0

.END



