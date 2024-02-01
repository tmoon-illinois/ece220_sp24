#include <stdio.h>

int main(){
    /*
    int num1 = 11, num2 = 3;
    printf("%d + %d=%d \n", num1, num2, num1+num2);
    printf("%d - %d=%d \n", num1, num2, num1-num2);
    printf("%d * %d=%d \n", num1, num2, num1*num2);
    printf("%d / %d=%d \n", num1, num2, num1/num2);
    printf("%d %% %d=%d \n", num1, num2, num1%num2);


    int bit = 1;
    printf("%x << 1 = %x\n", bit, bit<<1);
    printf("%x << 2 = %x\n", bit, bit<<2);

    int bit1 = 0x01, bit2 = 0x10;
    printf("%x | %x  = %x\n", bit1, bit2, bit1|bit2);
    printf("%x & %x  = %x\n", bit1, bit2, bit1&bit2);
    printf("%x ^ %x  = %x\n", bit1, bit2, bit1^bit2);
*/

    int num1 = 10, num2 = 12;
    int result1, result2, result3;

    result1 = (num1==10 && num2==12);
    result2 = (num1<12 || num2>12);
    result3 = (!num1);

    printf("result1: %d\n", result1);
    printf("result2: %d\n", result2);
    printf("result3: %d\n", result3);

    return 0;
}

