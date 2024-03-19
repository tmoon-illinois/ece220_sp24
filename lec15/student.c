#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 100
typedef struct StudentStruct{
    int UIN;
    char netid[BUF_SIZE];
    float GPA;
}student;

void printStudent(student s[], int num);
void swapStudent(student *a, student *b);
void bubbleSort(student array[], int n);

int main(){
    student *s;
    s = (student*)  malloc(2*sizeof(student));
    //student s[100];

    s[0].UIN = 1;
    strcpy( s[0].netid , "Bob");
    s[0].GPA= 3.0;

    s[1].UIN = 2;
    strcpy( s[1].netid , "Alice");
    s[1].GPA= 3.5;

    free(s);
   
    /*
    s[2].UIN = 3;
    strcpy( s[2].netid , "Cris");
    s[2].GPA= 4.0;

    s[3].UIN = 4;
    strcpy( s[3].netid , "David");
    s[3].GPA= 2.5;


    printStudent(s, 2);
    bubbleSort(s, 2);
    printStudent(s, 2);
    */
}
void printStudent(student s[], int num){

    for(int i=0;i<num;i++)
        printf("%d %s %f\n", s[i].UIN, s[i].netid, s[i].GPA);
        //printf("%d %s %f\n", *(s+i).UIN, s[i].netid, s[i].GPA);

    printf("\n\n");
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swapStudent(student *a, student *b){
    student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(student array[], int n)
{
    int i, is_swap;
    do{
        is_swap = 0;
        for(i=0; i< n-1; i++){
            if(array[i].GPA < array[i+1].GPA){
                swapStudent(&array[i], &array[i+1]);
                is_swap = 1;
            }
        }
    }while(is_swap != 0);

}



