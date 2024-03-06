#include <stdio.h>

int main(){
    char c;
    FILE *fp1, *fp2;

    if((fp1=fopen("original.txt", "r")) == NULL){
        printf("Unable to open a file.\n");
        return -1;
    }
    if((fp2=fopen("modified.txt", "w")) == NULL){
        printf("Unable to open a file.\n");
        return -1;
    }

    do{
        c = fgetc(fp1);
        if(c>='0' && c<='9')
            fputc(c,fp2);
    }while(c!= EOF);
    fclose(fp1);
    fclose(fp2);

    return 0;
}
