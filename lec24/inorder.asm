.ORIG x3000
;;R5 - frame pointer
;;R6 - stack pointer
;;MAIN
LD  R6, STACK
LD  R5, STACK
LD  R1, ROOT
ADD R6, R6, #-1
STR R1, R6, #0
JSR INORDER
HALT


;;INORDER TRAVERSAL
INORDER
;;Part 1 - push book keeping info
ADD R6, R6, #-3
STR R7, R6, #1
STR R5, R6, #0
ADD R5, R6, #-1

;;Part 2 - implement function logic
;if (nd == NULL) skip to the end (Done)
LDR R1, R5, #4  ; R1 = node
BRz DONE

;else 
;inorder(nd->left);
LDR R2, R1, #1  ; R2 = node->left
ADD R6, R6, #-1
STR R2, R6, #0
JSR INORDER     ; R1 may change inside
ADD R6, R6, #2  ; stack tear down completely
;printf("%c", nd->data);
LDR R1, R5, #4  ; R1 = node
LDR R0, R1, #0  ; R0 = node->data
OUT
;inorder(nd->right); 
LDR R2, R1, #2  ; R2 = node->right
ADD R6, R6, #-1
STR R2, R6, #0
JSR INORDER     ; R1 may change inside
ADD R6, R6, #2  ; stack tear down completely
;;Part 3 - tear down part of activation record (prepare to return)
DONE
LDR R5, R6, #0        ;restore old frame pointer
ADD R6, R6, #1
LDR R7, R6, #0        ;restore return address
ADD R6, R6, #1

RET


STACK .FILL x7000
ROOT .FILL x6000
.END
