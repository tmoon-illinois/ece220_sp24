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
int main(){
    // 1. double pointer
    item *head = NULL;
    additem(&head,5);
    additem(&head,10);
    delete_node(&head, 100);
    printitem(head);
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
