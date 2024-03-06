#include <stdio.h>


int main(){
    int uid;
    char name[20];
    double gpa;

    FILE *fp_in = fopen("data.txt", "r");
    FILE *fp_out = fopen("swapped.txt", "w") ;
    int ret;
    /*
    if((fp_in = fopen("data.txt", "r")) == NULL){
        printf("fopen(r) failed. \n");
        return -1;
    }
    if((fp_out = fopen("swapped.txt", "w")) == NULL){
        printf("fopen(w) failed. \n");
        return -1;
    }
    */

    while( fscanf(fp_in, "%d %s %lf", &uid, name, &gpa) != EOF){
        fprintf(fp_out, "%s %d %lf\n", name, uid, gpa);
    }
    fclose(fp_in);
    fclose(fp_out);

    return 0;


}

