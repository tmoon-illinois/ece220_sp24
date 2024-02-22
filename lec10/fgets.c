#include <stdio.h>


int main(){

    char str1[10] = "aaaaaaaa";
    char str2[3];

    //scanf("%s", str2);
    fgets(str2, 3, stdin);



    printf("%s, %s \n", str1, str2);
}



