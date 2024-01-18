

.ORIG   x3000


    ; R1 <- KBSR
    ; R1 <- mem[xFE00]
    ; Approach1: use other reg (LDR) i.e., R2 <- xFE00
    ; Approach2: R1<- mem[mam[LB]]
POLL    LDI     R1, KBSR_ADDR ;R1<- mem[FE00]
        BRzp    POLL
        LDI     R0, KBDR_ADDR
        LDI     R2, KBSR_ADDR ;R1<- mem[FE00]

POLL2    LDI     R1, DSR_ADDR ;R1<- mem[FE00]
        BRzp    POLL2
        STI     R0, DDR_ADDR
        LDI     R2, DSR_ADDR ;R1<- mem[FE00]



KBSR_ADDR      .FILL xFE00
KBDR_ADDR      .FILL xFE02

DSR_ADDR      .FILL xFE04
DDR_ADDR      .FILL xFE06
.END
