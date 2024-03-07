#include <stdio.h>
#include <string.h>
#define BUF_SIZE 100
typedef struct StudentStruct{
    int UIN;
    char netid[BUF_SIZE];
    float GPA;
}student;

void printStudent(student s[], int num);
void swapStudent(student *a, student *b);

int main(){
    student s[100];

    s[0].UIN = 1;
    //s[0].netid = "Bob";
    strcpy( s[0].netid , "Bob");
    //strcpy( &(s[0].netid[0]) , "Bob");
    s[0].GPA= 3.0;

    s[1].UIN = 2;
    strcpy( s[1].netid , "Alice");
    s[1].GPA= 3.5;

    student *ptr;
    //ptr = s;
    ptr = &s[0];
    //(*ptr).UIN = 100;
    ptr->UIN = 100;
    strcpy( ptr->netid , "Bruno");
    ptr->GPA = 3.8;


    printStudent(s, 2);
    swapStudent(&s[0], &s[1]);
    printStudent(s, 2);
}
void printStudent(student s[], int num){

    for(int i=0;i<num;i++)
        printf("%d %s %f\n", s[i].UIN, s[i].netid, s[i].GPA);
        //printf("%d %s %f\n", *(s+i).UIN, s[i].netid, s[i].GPA);

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




