#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *root){
    struct node *iterator = root;
    while(iterator){
       printf("%d ",iterator->data);
       iterator = iterator->next;
    }
    printf("\n");
    return;
}

int main(){

    int i,n;
    struct node *head = NULL,*current,*iterator;
    // struct node *temp = (struct node *)malloc(sizeof(struct node));
    // int arr[] = {1,2,3,4,5};
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        // temp->data = arr[i];
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = current->next;
        }
    }

   printf("Before reversing the linked list\n");
   print_list(head);

   struct node *start = head,*end = current,*prev;
   int temp_data;
   while(start != end){ //No. of elements in the list is odd
       temp_data = end->data;
       end->data = start->data;
       start->data = temp_data;
       prev = start;
       while(prev -> next != end){
           prev = prev->next;
       }
       end = prev;
       
       if(start == end){ // No. of elements in the list is even
           break;
       }
       start = start->next;
   }

   printf("After reversing the linked list\n");
   print_list(head);

   return 0;

}