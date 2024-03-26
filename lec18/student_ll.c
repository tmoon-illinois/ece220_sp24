#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 100
typedef struct StudentStruct{
    int UIN;
    char netid[BUF_SIZE];
    float GPA;
    struct StudentStruct *next;
}node;

void insert_head(node **headpptr, node *data);
void insert_sorted_GPA(node **headpptr, node *data);
int loadFile(char filename[], node **headpptr);
void printStudents(node *headptr);
void delete_all(node **headptr);
int delete_node(node **headpptr, int UIN);
void push(node **headpptr, node *data);
int pop(node **headpptr);
void enqueue(node **headpptr, node *data);
int dequeue(node **headpptr);

int main(){
    node *headptr = NULL;

    int numStudent, uin;
    char filename[20];

    numStudent = loadFile("roster.txt", &headptr);
    printf("Load the roster\n");
    printStudents(headptr);

    // pop
    /*
    while(pop(&headptr))
        printStudents(headptr);
        */
    while(dequeue(&headptr))
        printStudents(headptr);

    return 0;

}
void insert_head(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = *headpptr;
    *headpptr = temp;
}
// descending order sort by GPA
void insert_sorted_GPA(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    while(  *headpptr && (*headpptr)->GPA > data->GPA  ) 
        headpptr = &((*headpptr)->next);

    temp->next = *headpptr;
    *headpptr = temp;
}
int loadFile(char filename[], node **headpptr){
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n", filename);
        return -1;
    }
    char buf[BUF_SIZE], buf_name[BUF_SIZE];
    int num= 0;
    fgets(buf, BUF_SIZE, fp); //skip the header

    node data;
    while(fgets(buf, BUF_SIZE, fp)){ //NULL if fails
        sscanf(buf, "%d %s %f", &(data.UIN), data.netid, &(data.GPA));
        data.next = NULL;
        //insert_head(headpptr, &data);
        //insert_sorted_GPA(headpptr, &data);
        //push(headpptr, &data);
        enqueue(headpptr, &data);
        num++;
    }
    fclose(fp);
    return num;
}

void printStudents(node *headptr){
    printf("UIN netid GPA\n");
    while(headptr){
        printf("%d %s %f\n", headptr->UIN, headptr->netid, headptr->GPA);
        headptr = headptr->next;
    }
    printf("\n\n");
}
void delete_all(node **headpptr){
    node *next;
    while(*headpptr){
        printf("deleting %s\n", (*headpptr)->netid);
        next = (*headpptr)->next;
        free(*headpptr);
        *headpptr = next;
    }
}
int delete_node(node **headpptr, int UIN){
    node *target;
    while(*headpptr && (*headpptr)->UIN != UIN)
        headpptr = &((*headpptr)->next);

    if(*headpptr == NULL) return 0;
    target = *headpptr;
    *headpptr = target->next;
    free(target);
    return 1;
}
void push(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;

    temp->next = *headpptr;
    *headpptr = temp;
}
int pop(node **headpptr){
    node *next;

    if(*headpptr == NULL){
        printf("stack is empty.\n");
        return 0;
    }

    next = (*headpptr)->next;
    free(*headpptr);
    *headpptr = next;
    return 1;
}
void enqueue(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = NULL;

    while(*headpptr != NULL)
        headpptr = &((*headpptr)->next);
    
    *headpptr = temp;
}
int dequeue(node **headpptr){
    node *next;

    if(*headpptr == NULL){
        printf("Queue is empty.\n");
        return 0;
    }

    next = (*headpptr)->next;
    free(*headpptr);
    *headpptr = next;
    return 1;
}

