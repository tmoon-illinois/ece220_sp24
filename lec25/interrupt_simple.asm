.ORIG   x3000
        ;load ISR address to INTV (M[x0180] <- MYISR)
        LEA     R0, MYISR
        STI     R0, KBINTV 
        ;enable IE bit of KBSR
        LD      R0, EN_IE
        STI     R0, KBSR
        ;main infinite loop to print 'A'
AGAIN
        LD      R0, ALP_A 
        OUT
        LD      R0, ENTER
        OUT
        BR      AGAIN
        
;; Your interrrupt service routine here
MYISR
        ST      R0,SaveR0 ;callee-save
        ST      R1,SaveR1 ;callee-save
        LDI     R0,KBDR ;read a charcter from keyboard and clear ready bit
;load DSR and if ready, write a character to DDR
DISP_INT
        LDI     R1, DSR
        BRzp    DISP_INT
        STI     R0, DDR
        LD      R0,SaveR0
        LD      R1,SaveR1
RTI


EN_IE   .FILL   x4000 ;enable IE 0100_0000_0000_0000
NUM0    .FILL   x0030
NUM9    .FILL   x0039
ALP_A   .FILL   x41
ALP_Z   .FILL   x5A
ENTER   .FILL   x0A
KBSR    .FILL   xFE00
KBDR    .FILL   xFE02
DSR     .FILL   xFE04
DDR     .FILL   xFE06
KBINTV  .FILL   x0180 ;INT vector table address for keyboard
SaveR0  .BLKW   #1
SaveR1  .BLKW   #1
SaveR7  .BLKW   #1
.END


