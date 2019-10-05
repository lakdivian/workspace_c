#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

Node *head = NULL;

Node* createNode(int val){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void InsertNode(Node *newNode){
    if(head == NULL){
        head = newNode;
    } else {
        Node *iter = head;
        while(iter->next != NULL){
            iter = iter->next;
        }

        newNode->prev = iter;
        iter->next = newNode;
    }
}

void PrintList(){
    Node *iter = head;
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter -> next;
    }
    printf("\n");
}

void ReverseDoublyLinkedList(){
    Node *start = head;
    Node *end = head;
    while(end->next != NULL){
        end = end -> next;
    }

    while(start != end){
        int temp = start->data;
        start->data = end->data;
        end->data = temp;
        start = start->next;
        if(start == end){
            break;
        }
        end = end->prev;
    }
}

int main(){

    int N,i,val;
    printf("Enter the number of nodes you wanna add to the doubly\n");
    fscanf(stdin, "%d", &N);
    printf("Enter the %d node Values\n", N);
    for(i=0;i<N;i++){
        scanf("%d", &val);
        InsertNode(createNode(val));
    }
    printf("Printing the Linked List\n");
    PrintList();
    ReverseDoublyLinkedList();
    printf("Printing the Reversed Linked List\n");
    PrintList();
    return 0;
}