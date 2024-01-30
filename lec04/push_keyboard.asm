.ORIG x3000


;1. first keyboard input
GETC
OUT
JSR PUSH
;omit overflow check

;2. second keyboard input
GETC
OUT
JSR PUSH
;omit overflow check

;3. third keyboard input
GETC
OUT
JSR PUSH
;omit overflow check


JSR POP
;omit underflow check
OUT

JSR POP
;omit underflow check
OUT

JSR POP
;omit underflow check
OUT



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


;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;callee-save & initialize registers
	ST	R3,SAVE_R3
	ST	R6,SAVE_R6	
	LD	R3,STACK_START
	LD	R6,STACK_TOP
	AND	R5,R5,#0
;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	UNDERFLOW

;it is NOT underflow
	ADD	R6,R6,#1
	LDR	R0,R6,#0
	ST	R6,STACK_TOP
	BRnzp	DONE_POP
;it is underflow
UNDERFLOW
	ADD	R5,R5,#1

;restore registers
DONE_POP
	LD	R3,SAVE_R3
	LD	R6,SAVE_R6
	RET


STACK_END       .FILL   x3FFD
STACK_START     .FILL   x4000
STACK_TOP       .FILL   x4000
SAVE_R3         .FILL    x0
SAVE_R6         .FILL    x0

.END



