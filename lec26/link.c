#include <stdio.h>
#include <stdlib.h>


typedef struct Struct item;
struct Struct 
{
    int data;
    item *next;
};
// 1. double pointer
int additem(item **head, int input){
    item *newitem = (item*) malloc(sizeof(item));
    if(newitem == NULL) return 0;
    newitem->data = input;
    newitem->next = *head;
    *head = newitem;
    return 1;
}
// 2. return single pointer
// item *additem(item *head, int input){
//     item *newitem = (item*) malloc(sizeof(item));
//     if(newitem == NULL) return 0;
//     newitem->data = input;
//     newitem->next = head;
//     head = newitem;
//     return head;
// }
// 3. use dummy node 
// int additem(item *head, int input){
//     item *newitem = (item*) malloc(sizeof(item));
//     if(newitem == NULL) return 0;
//     newitem->data = input;
//     newitem->next = head->next;
//     head->next = newitem;
//     return 1;
// }
void delete_node(item **headpptr, int val){
	while( *headpptr != NULL && (*headpptr)->data != val)
		headpptr = &((*headpptr)->next);

	if(*headpptr == NULL) return;
	item *temp = *headpptr; //original target address
	*headpptr = (*headpptr)->next;
	free(temp);
}   

void printitem(item *head){
    item *cursor = head;
    while(cursor != NULL){
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}
void insert_sorted(item **headpptr, int val){
    item *temp = (item*) malloc(sizeof(item));
    temp->data = val;
    while(*headpptr &&  (*headpptr)->data < temp->data)
        headpptr = &((*headpptr)->next);

    temp->next = *headpptr;
    *headpptr = temp;
}
void split(item *head, item **odd_head, item **even_head){
    item *cur = head;
    while(cur != NULL){
        if(cur->data % 2 == 0 ){
            insert_sorted(even_head, cur->data);
        }
        else{
            insert_sorted(odd_head, cur->data);
        }
        cur = cur->next;
    }
}


int main(){
    // 1. double pointer
    item *head = NULL;
    additem(&head,5);
    additem(&head,10);
    additem(&head,11);
    additem(&head,12);
    additem(&head,13);
    // delete_node(&head, 100);
    printitem(head);

    item *even_head = NULL, *odd_head = NULL;
    split(head, &odd_head, &even_head);
    printitem(odd_head);
    printitem(even_head);


    // 2. return single pointer
    // item *head = NULL;
    // head = additem(head,5);
    // head = additem(head,10);
    // 3. use dummy node 
    // item head;
    // head.next = NULL;
    // additem(&head, 5);
    // additem(&head, 10);
    // additem(&head, 1);
    // additem(&head, 15);
    // additem(&head, 20);
    // printitem(head.next);
    // delete_node(&head.next, 100);
    // printitem(head.next);

}
